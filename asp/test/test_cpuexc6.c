/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2007-2013 by Embedded and Real-Time Systems Laboratory
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
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  $Id: test_cpuexc6.c 2534 2013-10-13 12:27:37Z ertl-hiro $
 */

/* 
 *		CPU�㳰�����Υƥ���(6)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  �����ͥ���٥ޥ�����TIPM_ENAALL���ǥ����ѥå����ľ��֡��������㳰��
 *  �߾��֤�ȯ������CPU�㳰�ˤ����륷���ƥ���֤Υƥ��ȡ��������ڴ�����
 *  ���ꥫ�Х꡼�Ǥ��뤳�Ȥ�ƥ��Ȥ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *  ������⡤�����ͥ���٥ޥ�����TIPM_ENAALL���ǥ����ѥå����ľ��֡���
 *  �����㳰�ػ߾��֤�ȯ������CPU�㳰�ˤ����ơ�
 *
 *	(A) CPU�㳰�ϥ�ɥ�¹Գ��ϻ���CPU���å��ե饰���Ѳ����ʤ�����
 *	(B) CPU�㳰�ϥ�ɥ�¹Գ��ϻ��˳����ͥ���٥ޥ������Ѳ����ʤ�����
 *		��CPU�㳰�ϥ�ɥ���ǳ����ͥ���٥ޥ������ɤ�ʤ����ᡤ�ƥ��Ȥ�
 *		���ʤ���
 *	(C) CPU�㳰�ϥ�ɥ�¹Գ��ϻ��˥ǥ����ѥå��ػߥե饰���Ѳ����ʤ�����
 *	(D) CPU�㳰�ϥ�ɥ�¹Գ��ϻ��˥������㳰�����ػߥե饰���Ѳ����ʤ�����
 *	(E) CPU�㳰�ϥ�ɥ�꥿�������CPU���å��ե饰��������뤳��
 *	(F) CPU�㳰�ϥ�ɥ�꥿������˳����ͥ���٥ޥ�����������뤳��
 *	(G) CPU�㳰�ϥ�ɥ�꥿������˥ǥ����ѥå��ػߥե饰���Ѳ����ʤ�����
 *	(H) CPU�㳰�ϥ�ɥ�꥿������˥������㳰�����ػߥե饰���Ѳ����ʤ�����
 *	(I) xsns_xpn��true���֤�����
 *	(J) xsns_dpn��false���֤�����
 *	(K) �������ڴ����ˤ��ꥫ�Х꡼���Ǥ��뤳��
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: TA_ACT����ͥ���١��������㳰�����롼������Ͽ
 *	TASK2: TA_NULL����ͥ����
 *	CPUEXC1: TA_NULL
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1����ͥ���١�1���ܡ�==
 *	1:	���֤Υ����å�
 *	2:	RAISE_CPU_EXCEPTION
 *	== CPUEXC1 ==
 *	3:	���֤Υ����å�				... (A),(C),(D)
 *		xsns_xpn() == true			... (I)
 *		xsns_dpn() == false			... (J)
 *  4:	iact_tsk(TASK2)
 *		iloc_cpu()
 *  	�꥿����
 *	== TASK2�ʹ�ͥ���١�==
 *	5:	���֤Υ����å�				... (E),(F),(G),(H)
 *	6:	ter_tsk(TASK1)				... (K)
 *	7:	act_tsk(TASK1)				... (K)
 *	8:	ext_tsk()
 *	== TASK1����ͥ���١�2���ܡ�==
 *	9:	���֤Υ����å�				... (K)
 *	10:	�ƥ��Ƚ�λ
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_cpuexc.h"

int_t	task1_count = 0;

void
task1(intptr_t exinf)
{
	switch (++task1_count) {
	case 1:
		test_start(__FILE__);

		check_point(1);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		check_point(2);
		RAISE_CPU_EXCEPTION;

		check_point(0);
		break;

	case 2:
		check_point(9);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		check_finish(10);
		break;

	default:
		check_point(0);
		break;
	}
}

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(5);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	check_point(6);
	ercd = ter_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = act_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = ext_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
alarm1_handler(intptr_t exinf)
{
	check_point(0);
}

void
cpuexc_handler(void *p_excinf)
{
	ER		ercd;

	check_point(3);
	check_state_i(true, false, false, true, true);
	check_assert(xsns_xpn(p_excinf) == true);
	check_assert(xsns_dpn(p_excinf) == false);

	check_point(4);
	ercd = iact_tsk(TASK2);
	check_ercd(ercd, E_OK);
	ercd = iloc_cpu();
	check_ercd(ercd, E_OK);
}