/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2009 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: tSerialPortMain.c 1958 2013-05-18 03:16:20Z ritsumei-takuya $
 */

/*
 *		���ꥢ�륤�󥿥ե������ɥ饤��
 */

#include <kernel.h>
#include <t_syslog.h>
#include "tSerialPortMain_tecsgen.h"

/*
 *  �ե�����˴�Ϣ��������ȥޥ���
 */
#define	FC_STOP			'\023'		/* ����ȥ���-S */
#define	FC_START		'\021'		/* ����ȥ���-Q */

#define BUFCNT_STOP(bufsz)		((bufsz) * 3 / 4)	/* STOP��������ʸ���� */
#define BUFCNT_START(bufsz)		((bufsz) / 2)		/* START��������ʸ���� */

/*
 *  �ݥ��󥿤Υ��󥯥����
 */
#define INC_PTR(ptr, bufsz)		{ if (++(ptr) == (bufsz)) { (ptr) = 0; }}

/*
 *  �����ӥ�������ƽФ��ޥ���
 *
 *  �����ӥ�������ƽФ���ޤ༰exp��ɾ���������ͤ����顼������͡ˤξ�
 *  ��ˤϡ�erc��ercd_exp��ɾ�������ͤ���������error_exit��goto���롥
 */
#define SVC(exp, ercd_exp) \
				{ if ((exp) < 0) { ercd = (ercd_exp); goto error_exit; }}

/*
 *  E_SYS���顼������
 */
static ER
gen_ercd_sys(CELLCB *p_cellcb)
{
	VAR_errorFlag = true;
	return(E_SYS);
}

/*
 *  �Ԥ������륵���ӥ������뤫��Υ��顼���Ѵ�
 */
static ER
gen_ercd_wait(ER rercd, CELLCB *p_cellcb)
{
	switch (MERCD(rercd)) {
	case E_RLWAI:
	case E_DLT:
		return(rercd);
	default:
		VAR_errorFlag = true;
		return(E_SYS);
	}
}

/*
 *  ���ꥢ��ݡ��ȤΥ����ץ�ʼ������ؿ���
 */
ER
eSerialPort_open(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	ER		ercd;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!VALID_IDX(idx)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}
	p_cellcb = GET_CELLCB(idx);

	SVC(dis_dsp(), gen_ercd_sys(p_cellcb));
	if (VAR_openFlag) {				/* �����ץ�Ѥߤ��Υ����å� */
		ercd = E_OBJ;
	}
	else {
		/*
		 *  �ѿ��ν����
		 */
		VAR_ioControl = (IOCTL_ECHO | IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV);

		VAR_receiveReadPointer = 0U;
		VAR_receiveWritePointer = 0U;
		VAR_receiveCount = 0U;
		VAR_receiveFlowControl = '\0';
		VAR_receiveStopped = false;

		VAR_sendReadPointer = 0U;
		VAR_sendWritePointer = 0U;
		VAR_sendCount = 0U;
		VAR_sendStopped = false;

		/*
		 *  ����ʹߡ�����ߤ�ػߤ��롥
		 */
		if (loc_cpu() < 0) {
			ercd = E_SYS;
			goto error_exit_enadsp;
		}

		/*
		 *  �ϡ��ɥ�������¸�Υ����ץ����
		 */
		cSIOPort_open();

		/*
		 *  �������Υ�����Хå�����Ĥ��롥
		 */
		cSIOPort_enableCBR(SIO_RDY_RCV);
		VAR_openFlag = true;
		VAR_errorFlag = false;

		if (unl_cpu() < 0) {
			VAR_errorFlag = true;
			ercd = E_SYS;
			goto error_exit_enadsp;
		}
		ercd = E_OK;
	}

  error_exit_enadsp:
	SVC(ena_dsp(), gen_ercd_sys(p_cellcb));

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��ȤΥ������ʼ������ؿ���
 */
ER
eSerialPort_close(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	ER		ercd;
	bool_t	eflag = false;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!VALID_IDX(idx)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}
	p_cellcb = GET_CELLCB(idx);

	SVC(dis_dsp(), gen_ercd_sys(p_cellcb));
	if (!VAR_openFlag) {			/* �����ץ�Ѥߤ��Υ����å� */
		ercd = E_OBJ;
	}
	else {
		/*
		 *  �ϡ��ɥ�������¸�Υ���������
		 */
		if (loc_cpu() < 0) {
			eflag = true;
		}
		cSIOPort_close();
		VAR_openFlag = false;
		if (unl_cpu() < 0) {
			eflag = true;
		}

		/*
		 *  ���ޥե��ν����
		 */
		if (cSendSemaphore_initialize() < 0) {
			eflag = true;
		}
		if (cReceiveSemaphore_initialize() < 0) {
			eflag = true;
		}

		/*
		 *  ���顼�����ɤ�����
		 */
		if (eflag) {
			ercd = gen_ercd_sys(p_cellcb);
		}
		else {
			ercd = E_OK;
		}
	}
	SVC(ena_dsp(), gen_ercd_sys(p_cellcb));

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥؤ�ʸ������
 *
 *  p_cellcb�ǻ��ꤵ��륷�ꥢ��I/O�ݡ��Ȥ��Ф��ơ�ʸ��c���������롥ʸ
 *  ���������쥸�����ˤ��줿���ˤ�true���֤��������Ǥʤ����ˤϡ���
 *  ���쥸���������������Ȥ����Τ��륳����Хå��ؿ�����Ĥ���false����
 *  �������δؿ��ϡ�CPU��å����֤ǸƤӽФ���롥
 */
Inline bool_t
serialPort_snd_chr(CELLCB *p_cellcb, char_t c)
{
	if (cSIOPort_putChar(c)) {
		return(true);
	}
	else {
		cSIOPort_enableCBR(SIO_RDY_SND);
		return(false);
	}
}

/*
 *  ���ꥢ��ݡ��Ȥؤ�1ʸ������
 */
static ER_BOOL
serialPort_wri_chr(CELLCB *p_cellcb, char_t c)
{
	bool_t	buffer_full;
	ER		ercd, rercd;

	/*
	 *  LF������CR���������롥
	 */
	if (c == '\n' && (VAR_ioControl & IOCTL_CRLF) != 0U) {
		SVC(rercd = serialPort_wri_chr(p_cellcb, '\r'), rercd);
		if ((bool_t) rercd) {
			SVC(rercd = cSendSemaphore_wait(),
										gen_ercd_wait(rercd, p_cellcb));
		}
	}

	SVC(loc_cpu(), gen_ercd_sys(p_cellcb));
	if (VAR_sendCount == 0U && !VAR_sendStopped
								&& serialPort_snd_chr(p_cellcb, c)) {
		/*
		 *  ���ꥢ��I/O�ǥХ����������쥸������ʸ��������뤳�Ȥ�������
		 *  ����硥
		 */
		buffer_full = false;
	}
	else {
		/*
		 *  �����Хåե���ʸ��������롥
		 */
		VAR_sendBuffer[VAR_sendWritePointer] = c;
		INC_PTR(VAR_sendWritePointer, ATTR_sendBufferSize);
		VAR_sendCount++;
		buffer_full = (VAR_sendCount == ATTR_sendBufferSize);
	}

	SVC(unl_cpu(), gen_ercd_sys(p_cellcb));
	ercd = (ER_BOOL) buffer_full;

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥؤ�ʸ���������ʼ������ؿ���
 */
ER_UINT
eSerialPort_write(CELLIDX idx, const char_t *buffer, uint_t length)
{
	CELLCB	*p_cellcb;
	bool_t	buffer_full;
	uint_t	wricnt = 0U;
	ER		ercd, rercd;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!VALID_IDX(idx)) {			/* �ݡ����ֹ�Υ����å� */
		return(E_ID);
	}

	p_cellcb = GET_CELLCB(idx);
	if (!VAR_openFlag) {			/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (VAR_errorFlag) {			/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	buffer_full = true;				/* �롼�פ�1����wai_sem���� */
	while (wricnt < length) {
		if (buffer_full) {
			SVC(rercd = cSendSemaphore_wait(),
										gen_ercd_wait(rercd, p_cellcb));
		}
		SVC(rercd = serialPort_wri_chr(p_cellcb, *buffer++), rercd);
		wricnt++;
		buffer_full = (bool_t) rercd;
	}
	if (!buffer_full) {
		SVC(cSendSemaphore_signal(), gen_ercd_sys(p_cellcb));
	}
	ercd = E_OK;

  error_exit:
	return(wricnt > 0U ? (ER_UINT) wricnt : ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥ����1ʸ������
 */
static bool_t
serialPort_rea_chr(CELLCB *p_cellcb, char_t *p_c)
{
	bool_t	buffer_empty;
	ER		ercd;

	SVC(loc_cpu(), gen_ercd_sys(p_cellcb));

	/*
	 *  �����Хåե�����ʸ������Ф���
	 */
	*p_c = VAR_receiveBuffer[VAR_receiveReadPointer];
	INC_PTR(VAR_receiveReadPointer, ATTR_receiveBufferSize);
	VAR_receiveCount--;
	buffer_empty = (VAR_receiveCount == 0U);

	/*
	 *  START���������롥
	 */
	if (VAR_receiveStopped && VAR_receiveCount <= BUFCNT_START(ATTR_receiveBufferSize)) {
		if (!serialPort_snd_chr(p_cellcb, FC_START)) {
			VAR_receiveFlowControl = FC_START;
		}
		VAR_receiveStopped = false;
	}

	SVC(unl_cpu(), gen_ercd_sys(p_cellcb));
	ercd = (ER_BOOL) buffer_empty;

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥ����ʸ��������ʼ������ؿ���
 */
ER_UINT
eSerialPort_read(CELLIDX idx, char_t *buffer, uint_t length)
{
	CELLCB	*p_cellcb;
	bool_t	buffer_empty;
	uint_t	reacnt = 0U;
	char_t	c = '\0';		/* ����ѥ���ηٹ���޻ߤ��뤿��˽�������� */
	ER		ercd, rercd;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!VALID_IDX(idx)) {			/* �ݡ����ֹ�Υ����å� */
		return(E_ID);
	}

	p_cellcb = GET_CELLCB(idx);
	if (!VAR_openFlag) {			/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (VAR_errorFlag) {			/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	buffer_empty = true;			/* �롼�פ�1����wai_sem���� */
	while (reacnt < length) {
		if (buffer_empty) {
			SVC(rercd = cReceiveSemaphore_wait(),
										gen_ercd_wait(rercd, p_cellcb));
		}
		SVC(rercd = serialPort_rea_chr(p_cellcb, &c), rercd);
		*buffer++ = c;
		reacnt++;
		buffer_empty = (bool_t) rercd;

		/*
		 *  �������Хå�������
		 */
		if ((VAR_ioControl & IOCTL_ECHO) != 0U) {
			SVC(rercd = cSendSemaphore_wait(),
										gen_ercd_wait(rercd, p_cellcb));
			SVC(rercd = serialPort_wri_chr(p_cellcb, c), rercd);
			if (!((bool_t) rercd)) {
				SVC(cSendSemaphore_signal(), gen_ercd_sys(p_cellcb));
			}
		}
	}
	if (!buffer_empty) {
		SVC(cReceiveSemaphore_signal(), gen_ercd_sys(p_cellcb));
	}
	ercd = E_OK;

  error_exit:
	return(reacnt > 0U ? (ER_UINT) reacnt : ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥ�����ʼ������ؿ���
 */
ER
eSerialPort_control(CELLIDX idx, uint_t ioctl)
{
	CELLCB	*p_cellcb;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!VALID_IDX(idx)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}

	p_cellcb = GET_CELLCB(idx);
	if (!VAR_openFlag) {			/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (VAR_errorFlag) {			/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	VAR_ioControl = ioctl;
	return(E_OK);
}

/*
 *  ���ꥢ��ݡ��Ⱦ��֤λ��ȡʼ������ؿ���
 */
ER
eSerialPort_refer(CELLIDX idx, T_SERIAL_RPOR* pk_rpor)
{
	CELLCB	*p_cellcb;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!VALID_IDX(idx)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}

	p_cellcb = GET_CELLCB(idx);
	if (!VAR_openFlag) {			/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (VAR_errorFlag) {			/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	pk_rpor->reacnt = VAR_receiveCount;
	pk_rpor->wricnt = VAR_sendCount;
	return(E_OK);
}

/*
 *  ���ꥢ��ݡ��Ȥ����������ǽ������Хå��ʼ������ؿ���
 */
void
eiSIOCBR_readySend(CELLIDX idx)
{
	CELLCB	*p_cellcb;

	assert(VALID_IDX(idx));
	p_cellcb = GET_CELLCB(idx);
	if (VAR_receiveFlowControl != '\0') {
		/*
		 *  START/STOP ���������롥
		 */
		(void) cSIOPort_putChar(VAR_receiveFlowControl);
		VAR_receiveFlowControl = '\0';
	}
	else if (!VAR_sendStopped && VAR_sendCount > 0U) {
		/*
		 *  �����Хåե��椫��ʸ������Ф����������롥
		 */
		(void) cSIOPort_putChar(VAR_sendBuffer[VAR_sendReadPointer]);
		INC_PTR(VAR_sendReadPointer, ATTR_sendBufferSize);
		if (VAR_sendCount == ATTR_sendBufferSize) {
			if (ciSendSemaphore_signal() < 0) {
				VAR_errorFlag = true;
			}
		}
		VAR_sendCount--;
	}
	else {
		/*
		 *  �������٤�ʸ�����ʤ����ϡ�������ǽ������Хå���ػߤ��롥
		 */
		cSIOPort_disableCBR(SIO_RDY_SND);
	}
}

/*
 *  ���ꥢ��ݡ��Ȥ���μ������Υ�����Хå��ʼ������ؿ���
 */
void
eiSIOCBR_readyReceive(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	char_t	c;

	assert(VALID_IDX(idx));
	p_cellcb = GET_CELLCB(idx);
	c = (char_t) cSIOPort_getChar();
	if ((VAR_ioControl & IOCTL_FCSND) != 0U && c == FC_STOP) {
		/*
		 *  ����������ߤ��롥�������ʸ���Ϥ��Τޤ��������롥
		 */
		VAR_sendStopped = true;
	}
	else if (VAR_sendStopped && (c == FC_START
				|| (VAR_ioControl & IOCTL_FCANY) != 0U)) {
		/*
		 *  ������Ƴ����롥
		 */
		VAR_sendStopped = false;
		if (VAR_sendCount > 0U) {
			c = VAR_sendBuffer[VAR_sendReadPointer];
			if (serialPort_snd_chr(p_cellcb, c)) {
				INC_PTR(VAR_sendReadPointer, ATTR_sendBufferSize);
				if (VAR_sendCount == ATTR_sendBufferSize) {
					if (ciSendSemaphore_signal() < 0) {
						VAR_errorFlag = true;
					}
				}
				VAR_sendCount--;
			}
		}
	}
	else if ((VAR_ioControl & IOCTL_FCSND) != 0U && c == FC_START) {
		/*
		 *  �������Ф��ƥե����椷�Ƥ����硤START �ϼΤƤ롥
		 */
	}
	else if (VAR_receiveCount == ATTR_receiveBufferSize) {
		/*
		 *  �Хåե��ե�ξ�硤��������ʸ����ΤƤ롥
		 */
	}
	else {
		/*
		 *  ��������ʸ��������Хåե�������롥
		 */
		VAR_receiveBuffer[VAR_receiveWritePointer] = c;
		INC_PTR(VAR_receiveWritePointer, ATTR_receiveBufferSize);
		if (VAR_receiveCount == 0U) {
			if (ciReceiveSemaphore_signal() < 0) {
				VAR_errorFlag = true;
			}
		}
		VAR_receiveCount++;

		/*
		 *  STOP���������롥
		 */
		if ((VAR_ioControl & IOCTL_FCRCV) != 0U && !VAR_receiveStopped
						&& VAR_receiveCount >= BUFCNT_STOP(ATTR_receiveBufferSize)) {
			if (!serialPort_snd_chr(p_cellcb, FC_STOP)) {
				VAR_receiveFlowControl = FC_STOP;
			}
			VAR_receiveStopped = true;
		}
	}
}

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Ф����̤����ʸ���μ�Ф�
 */
bool_t
enSerialPort_getChar(CELLIDX idx, char_t *p_c)
{
	CELLCB	*p_cellcb;

	if (VALID_IDX(idx)) {						/* �ݡ����ֹ�Υ����å� */
		p_cellcb = GET_CELLCB(idx);
		if (VAR_openFlag) {						/* �����ץ�Ѥߤ��Υ����å� */
			if (VAR_sendCount > 0U) {
				*p_c = VAR_sendBuffer[VAR_sendReadPointer];
				INC_PTR(VAR_sendReadPointer, ATTR_sendBufferSize);
				VAR_sendCount--;
				return(true);
			}
		}
	}
	return(false);
}
