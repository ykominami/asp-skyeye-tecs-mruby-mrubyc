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
 *  @(#) $Id: tLogTaskMain.c 1958 2013-05-18 03:16:20Z ritsumei-takuya $
 */

/*
 *		�����ƥ��������
 */

#include <kernel.h>
#include <t_syslog.h>
#include <log_output.h>
#include "tLogTaskMain_tecsgen.h"
#include "tLogTask.h"

/*
 *  ���ꥢ�륤�󥿥ե������ؤ�1ʸ������
 */
static void
logtask_putc(char c)
{
	cSerialPort_write(&c, 1);
}

/*
 *
 */
static void
target_fput_log(char c)
{
	cPutLog_putChar(c);
}

/*
 *  �����ƥ�����Ϥ��Ԥ���碌
 */
ER
eLogTask_flush(uint_t count)
{
	T_SYSLOG_RLOG	rlog;
	T_SERIAL_RPOR	rpor;
	ER				ercd, rercd;

	if (sns_dpn()) {
		ercd = E_CTX;
	}
	else {
		for (;;) {
			if (cSysLog_refer(&rlog) < 0) {
				ercd = E_SYS;
				goto error_exit;
			}
			if (rlog.count <= count) {
				if (count == 0U) {
					/*
					 *  count��0�ξ��ˤϡ����ꥢ��Хåե����������
					 *  ǧ���롥
					 */
					if (cSerialPort_refer(&rpor) < 0) {
						ercd = E_SYS;
						goto error_exit;
					}
					if (rpor.wricnt == 0U) {
						ercd = E_OK;
						goto error_exit;
					}
				}
				else {
					ercd = E_OK;
					goto error_exit;
				}
			}

			/*
			 *  ATTR_flushWait�ߥ����Ԥġ�
			 */
			rercd = dly_tsk(ATTR_flushWait);
			if (rercd < 0) {
				ercd = (rercd == E_RLWAI) ? rercd : E_SYS;
				goto error_exit;
			}
		}
	}

  error_exit:
	return(ercd);
}

/*
 *  �����ƥ��������������
 */
void
eLogTaskBody_main(void)
{
	SYSLOG	syslog;
	uint_t	lost;
	ER_UINT	rercd;

	cSerialPort_open();
	cSysLog_mask(LOG_UPTO(LOG_NOTICE), LOG_UPTO(LOG_EMERG));
	syslog_0(LOG_NOTICE, "System logging task is started.");
	for (;;) {
		lost = 0U;
		while ((rercd = cSysLog_read(&syslog)) >= 0) {
			lost += (uint_t) rercd;
			if (syslog.logtype >= LOG_TYPE_COMMENT) {
				if (lost > 0U) {
					syslog_lostmsg(lost, logtask_putc);
					lost = 0U;
				}
				syslog_print(&syslog, logtask_putc);
				logtask_putc('\n');
			}
		}
		if (lost > 0U) {
			syslog_lostmsg(lost, logtask_putc);
		}
		dly_tsk(ATTR_interval);
	}
}

/*
 *  �����ƥ���������ν�λ����
 */
void
tLogTask_terminate(intptr_t exinf)
{
	char	c;
	SYSLOG	syslog;
	bool_t	msgflg = false;
	ER_UINT	rercd;

	/*
	 *  ���ꥢ�륤�󥿥ե������ɥ饤�Ф������Хåե������Ѥ��줿�ǡ���
	 *  �����٥���ϵ�ǽ���Ѥ��ƽ��Ϥ��롥
	 */
	while (cnSerialPort_getChar(&c)) {
		target_fput_log(c);
	}

	/*
	 *  ���Хåե��˵�Ͽ���줿����������٥���ϵ�ǽ���Ѥ��ƽ�
	 *  �Ϥ��롥
	 */
	while ((rercd = cSysLog_read(&syslog)) >= 0) {
		if (!msgflg) {
			/*
			 *  ���Хåե��˻Ĥä�������Ǥ��뤳�Ȥ򼨤�ʸ������
			 *  �Ϥ��롥
			 */
			syslog_printf("-- buffered messages --\n", NULL, target_fput_log);
			msgflg = true;
		}
		if (rercd > 0) {
			syslog_lostmsg((uint_t) rercd, target_fput_log);
		}
		if (syslog.logtype >= LOG_TYPE_COMMENT) {
			syslog_print(&syslog, target_fput_log);
			target_fput_log('\n');
		}
	}
}
