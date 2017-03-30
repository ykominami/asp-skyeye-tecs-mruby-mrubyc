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
 *  $Id: test_mutex3.c 2593 2014-01-02 06:29:10Z ertl-hiro $
 */

/* 
 *		�ߥ塼�ƥå����Υƥ���(3)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ͥ���پ�¥ߥ塼�ƥå����򡤥��å���������ȥ��å��������������
 *  �̤�ƥ��Ȥ��롥ref_tsk�ˤ��١���ͥ���٤ȸ���ͥ���٤λ��Ƚ����Υ�
 *  ���Ȥ��ͤƤ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) �ߥ塼�ƥå����Υ��å�������loc_mtx��
 *		(A-1) ���å�����Ƥ��ʤ����ˤϡ������˥��å��Ǥ��뤳��
 *		(A-2) ¿�Ť˥��å����褦�Ȥ���ȡ�E_ILUSE���顼�ˤʤ뤳��
 *		(A-3) ���å�����Ƥ�����ˤϡ�ͥ���ٽ���Ԥ����֤ˤʤ뤳��
 *	(B) �ߥ塼�ƥå����Υ��å����������unl_mtx��
 *		(B-1) ¾�����������å����Ƥ���ߥ塼�ƥå�����������褦�Ȥ����
 *		������E_ILUSE���顼�ˤʤ뤳��
 *		(B-2) �Ԥ����������ʤ��ȡ�ñ�˥��å�������뤳��
 *		(B-3) �Ԥ��������˥��å����Ϥ�����
 *		(B-4) �Ԥ��������˥��å����Ϥ��ơ��ǥ����ѥå��������뤳��
 *	(C) �ߥ塼�ƥå����Υ��å�������ploc_mtx��
 *		(C-1) ���å�����Ƥ�����ˤϡ�������E_TMOUT���顼�ˤʤ뤳��
 *	(D) �ߥ塼�ƥå����Υ��å�������tloc_mtx��
 *		(D-1) ���å�����Ƥ�����ˤϡ������ॢ�����դ����Ԥ����֤ˤ�
 *		�������뤳��
 *	(E) ���ޤ�
 *		(E-1) ��������λ����ȡ��ߥ塼�ƥå�������å�������뤳��
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥��������ᥤ�󥿥������ǽ餫�鵯ư
 *	TASK2: ��ͥ���٥�����
 *	TASK3: ��ͥ���٥�����
 *	MTX1: �ߥ塼�ƥå�����TA_CEILING°������¤Ϲ�ͥ���١�
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *		call(set_bit_func(bit_mutex))
 *	1:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		loc_mtx(MTX1)					... (A-1)
 *	2:	ref_tsk(TASK1, &rtsk)
 *		assert(rtsk.tskpri == HIGH_PRIORITY)
 *		assert(rtsk.tskbpri == LOW_PRIORITY)
 *		loc_mtx(MTX1) -> E_ILUSE		... (A-2)
 *	3:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK1)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		act_tsk(TASK2)
 *	4:	tslp_tsk(10) -> E_TMOUT
 *	== TASK2��ͥ���١����==
 *	5:	ploc_mtx(MTX1) -> E_TMOUT		... (C-1)
 *		loc_mtx(MTX1)					... (A-3)
 *	== TASK1��³����==
 *	6:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK1)
 *		assert(rmtx.wtskid == TASK2)
 *		act_tsk(TASK3)
 *	7:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3��ͥ���١����==
 *	8:	unl_mtx(MTX1) -> E_ILUSE		... (B-1)
 *	9:	loc_mtx(MTX1)					... (A-3)
 *	== TASK1��³����==
 *	10:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK1)
 *		assert(rmtx.wtskid == TASK3)
 *		dis_dsp()
 *		unl_mtx(MTX1)					... (B-3)
 *	11:	ref_tsk(TASK1, &rtsk)
 *		assert(rtsk.tskpri == LOW_PRIORITY)
 *		assert(rtsk.tskbpri == LOW_PRIORITY)
 *		ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TASK2)
 *		ena_dsp()
 *	== TASK3��³����==
 *	12:	ext_tsk() -> noreturn			... (E-1)
 *	== TASK2��³����==
 *	13:	ref_tsk(TASK2, &rtsk)
 *		assert(rtsk.tskpri == HIGH_PRIORITY)
 *		assert(rtsk.tskbpri == MID_PRIORITY)
 *		unl_mtx(MTX1)					... (B-4)
 *	14:	loc_mtx(MTX1)
 *	15:	slp_tsk()
 *	== TASK1��³����==
 *	16:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK2)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		tloc_mtx(MTX1, 10) -> E_TMOUT	... (D-1)
 *	17:	wup_tsk(TASK2)
 *	== TASK2��³����==
 *	18:	unl_mtx(MTX1)					... (B-2)
 *	19:	ext_tsk() -> noreturn
 *	== TASK1��³����==
 *	20:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex.h"

extern ER	bit_mutex(void);

/* DO NOT DELETE THIS LINE -- gentest depends on it. */

void
task1(intptr_t exinf)
{
	ER_UINT	ercd;
	T_RTSK	rtsk;
	T_RMTX	rmtx;

	test_start(__FILE__);

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);

	check_assert(rmtx.htskid == TSK_NONE);

	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = ref_tsk(TASK1, &rtsk);
	check_ercd(ercd, E_OK);

	check_assert(rtsk.tskpri == HIGH_PRIORITY);

	check_assert(rtsk.tskbpri == LOW_PRIORITY);

	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_ILUSE);

	check_point(3);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);

	check_assert(rmtx.htskid == TASK1);

	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(6);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);

	check_assert(rmtx.htskid == TASK1);

	check_assert(rmtx.wtskid == TASK2);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(10);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);

	check_assert(rmtx.htskid == TASK1);

	check_assert(rmtx.wtskid == TASK3);

	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = ref_tsk(TASK1, &rtsk);
	check_ercd(ercd, E_OK);

	check_assert(rtsk.tskpri == LOW_PRIORITY);

	check_assert(rtsk.tskbpri == LOW_PRIORITY);

	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);

	check_assert(rmtx.htskid == TASK3);

	check_assert(rmtx.wtskid == TASK2);

	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);

	check_assert(rmtx.htskid == TASK2);

	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = tloc_mtx(MTX1, 10);
	check_ercd(ercd, E_TMOUT);

	check_point(17);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_finish(20);
	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER_UINT	ercd;
	T_RTSK	rtsk;

	check_point(5);
	ercd = ploc_mtx(MTX1);
	check_ercd(ercd, E_TMOUT);

	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ref_tsk(TASK2, &rtsk);
	check_ercd(ercd, E_OK);

	check_assert(rtsk.tskpri == HIGH_PRIORITY);

	check_assert(rtsk.tskbpri == MID_PRIORITY);

	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = ext_tsk();

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER_UINT	ercd;

	check_point(8);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_ILUSE);

	check_point(9);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = ext_tsk();

	check_point(0);
}