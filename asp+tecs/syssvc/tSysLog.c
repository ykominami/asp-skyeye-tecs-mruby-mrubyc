/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: tSysLog.c 1958 2013-05-18 03:16:20Z ritsumei-takuya $
 */

/*
 *		�����ƥ����ǽ
 */

#include "tSysLog_tecsgen.h"
#include <sil.h>
#include <t_syslog.h>
#include <log_output.h>

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_SYSLOG_WRI_LOG_ENTER
#define LOG_SYSLOG_WRI_LOG_ENTER(prio, p_syslog)
#endif /* LOG_SYSLOG_WRI_LOG_ENTER */

#ifndef LOG_SYSLOG_WRI_LOG_LEAVE
#define LOG_SYSLOG_WRI_LOG_LEAVE(ercd)
#endif /* LOG_SYSLOG_WRI_LOG_LEAVE */

#ifndef LOG_SYSLOG_REA_LOG_ENTER
#define LOG_SYSLOG_REA_LOG_ENTER(p_syslog)
#endif /* LOG_SYSLOG_REA_LOG_ENTER */

#ifndef LOG_SYSLOG_REA_LOG_LEAVE
#define LOG_SYSLOG_REA_LOG_LEAVE(ercd, p_syslog)
#endif /* LOG_SYSLOG_REA_LOG_LEAVE */

#ifndef LOG_SYSLOG_MSK_LOG_ENTER
#define LOG_SYSLOG_MSK_LOG_ENTER(logmask, lowmask)
#endif /* LOG_SYSLOG_MSK_LOG_ENTER */

#ifndef LOG_SYSLOG_MSK_LOG_LEAVE
#define LOG_SYSLOG_MSK_LOG_LEAVE(ercd)
#endif /* LOG_SYSLOG_MSK_LOG_LEAVE */

#ifndef LOG_SYSLOG_REF_LOG_ENTER
#define LOG_SYSLOG_REF_LOG_ENTER(pk_rlog)
#endif /* LOG_SYSLOG_REF_LOG_ENTER */

#ifndef LOG_SYSLOG_REF_LOG_LEAVE
#define LOG_SYSLOG_REF_LOG_LEAVE(pk_rlog)
#endif /* LOG_SYSLOG_REF_LOG_LEAVE */

/*
 *  ���ߤΥ����ƥ����
 *
 *  ���������Ф�����ˡ����ʤ��������ͥ�������ѿ��򻲾Ȥ��Ƥ�
 *  �롥
 */
extern ulong_t	_kernel_current_time;

/*
 *  ���٥���ϤθƽФ��ؿ�
 */
static void
low_putchar(char_t c)
{
	cPutLog_putChar(c);
}

/* 
 *  ������ν���
 *
 *  CPU��å����֤�¹ԥ���ƥ����Ȥˤ�餺ư��Ǥ���褦�˼������Ƥ��롥
 */
ER
eSysLog_write(uint_t priority, const SYSLOG *p_syslog)
{
	SIL_PRE_LOC;

	LOG_SYSLOG_WRI_LOG_ENTER(prio, p_syslog);
	SIL_LOC_INT();

	/*
	 *  �����������
	 */
	((SYSLOG *) p_syslog)->logtim = _kernel_current_time;

	/*
	 *  ���Хåե��˵�Ͽ
	 */
	if ((VAR_logMask & LOG_MASK(priority)) != 0U) {
		VAR_logBuffer[VAR_tail] = *p_syslog;
		VAR_tail++;
		if (VAR_tail >= ATTR_logBufferSize) {
			VAR_tail = 0U;
		}
		if (VAR_count < ATTR_logBufferSize) {
			VAR_count++;
		}
		else {
			VAR_head = VAR_tail;
			VAR_lost++;
		}
	}

	/*
	 *  ���٥����
	 */
	if (((~(VAR_lowMaskNot)) & LOG_MASK(priority)) != 0U) {
		syslog_print(p_syslog, low_putchar);
		low_putchar('\n');
	}

	SIL_UNL_INT();
	LOG_SYSLOG_WRI_LOG_LEAVE(E_OK);
	return(E_OK);
}

/*
 *  ���Хåե�������ɽФ�
 *
 *  CPU��å����֤�¹ԥ���ƥ����Ȥˤ�餺ư��Ǥ���褦�˼������Ƥ��롥
 */
ER_UINT
eSysLog_read(SYSLOG *p_syslog)
{
	ER_UINT	ercd;
	SIL_PRE_LOC;

	LOG_SYSLOG_REA_LOG_ENTER(p_syslog);
	SIL_LOC_INT();

	/*
	 *  ���Хåե�����μ�Ф�
	 */
	if (VAR_count > 0U) {
		*p_syslog = VAR_logBuffer[VAR_head];
		VAR_count--;
		VAR_head++;
		if (VAR_head >= ATTR_logBufferSize) {
			VAR_head = 0U;
		}
		ercd = (ER_UINT) VAR_lost;
		VAR_lost = 0U;
	}
	else {
		ercd = E_OBJ;
	}

	SIL_UNL_INT();
	LOG_SYSLOG_REA_LOG_LEAVE(ercd, p_syslog);
	return(ercd);
}

/* 
 *  ���Ϥ��٤�������ν����٤�����
 */
ER
eSysLog_mask(uint_t logMask, uint_t lowMask)
{
	LOG_SYSLOG_MSK_LOG_ENTER(logmask, lowmask);
	VAR_logMask = logMask;
	VAR_lowMaskNot = ~lowMask;
	LOG_SYSLOG_MSK_LOG_LEAVE(E_OK);
	return(E_OK);
}

/*
 *  ���Хåե��ξ��ֻ���
 */
ER_UINT
eSysLog_refer(T_SYSLOG_RLOG *pk_rlog)
{
	SIL_PRE_LOC;

	LOG_SYSLOG_REF_LOG_ENTER(pk_rlog);
	SIL_LOC_INT();

	pk_rlog->count = VAR_count;
	pk_rlog->lost = VAR_lost;
	pk_rlog->logmask = VAR_logMask;
	pk_rlog->lowmask = ~(VAR_lowMaskNot);

	SIL_UNL_INT();
	LOG_SYSLOG_REF_LOG_LEAVE(pk_rlog);
	return(E_OK);
}
