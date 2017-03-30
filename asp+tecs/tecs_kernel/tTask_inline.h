/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: tTask_inline.h 428 2009-07-17 08:02:10Z ertl-takuya $
 */

/* °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id         
 */

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eTask
 * entry port: eTask
 * signature:  sTask
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTask_activate
 * name:         eTask_activate
 * global_name:  tTask_eTask_activate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_activate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(act_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_cancelActivate
 * name:         eTask_cancelActivate
 * global_name:  tTask_eTask_cancelActivate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER_UINT
eTask_cancelActivate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(can_act(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_terminate
 * name:         eTask_terminate
 * global_name:  tTask_eTask_terminate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_terminate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ter_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_changePriority
 * name:         eTask_changePriority
 * global_name:  tTask_eTask_changePriority
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_changePriority(CELLIDX idx, PRI priority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(chg_pri(ATTR_id, priority));
}

/* #[<ENTRY_FUNC>]# eTask_getPriority
 * name:         eTask_getPriority
 * global_name:  tTask_eTask_getPriority
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_getPriority(CELLIDX idx, PRI* p_priority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(get_pri(ATTR_id, p_priority));
}

/* #[<ENTRY_FUNC>]# eTask_refer
 * name:         eTask_refer
 * global_name:  tTask_eTask_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_refer(CELLIDX idx, T_RTSK* pk_taskStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_tsk(ATTR_id, pk_taskStatus));
}

/* #[<ENTRY_FUNC>]# eTask_wakeup
 * name:         eTask_wakeup
 * global_name:  tTask_eTask_wakeup
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_wakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(wup_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_cancelWakeup
 * name:         eTask_cancelWakeup
 * global_name:  tTask_eTask_cancelWakeup
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER_UINT
eTask_cancelWakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(can_wup(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_releaseWait
 * name:         eTask_releaseWait
 * global_name:  tTask_eTask_releaseWait
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_releaseWait(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rel_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_suspend
 * name:         eTask_suspend
 * global_name:  tTask_eTask_suspend
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_suspend(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(sus_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_resume
 * name:         eTask_resume
 * global_name:  tTask_eTask_resume
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_resume(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rsm_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eTask_raiseException
 * name:         eTask_raiseException
 * global_name:  tTask_eTask_raiseException
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eTask_raiseException(CELLIDX idx, TEXPTN pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ras_tex(ATTR_id, pattern));
}

/* #[<ENTRY_PORT>]# eiTask
 * entry port: eiTask
 * signature:  siTask
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiTask_activate
 * name:         eiTask_activate
 * global_name:  tTask_eiTask_activate
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_activate(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(iact_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_wakeup
 * name:         eiTask_wakeup
 * global_name:  tTask_eiTask_wakeup
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_wakeup(CELLIDX idx)
{
	CELLCB	*p_cellcb= GET_CELLCB(idx);
	return(iwup_tsk(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_releaseWait
 * name:         eiTask_releaseWait
 * global_name:  tTask_eiTask_releaseWait
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_releaseWait(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(irel_wai(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eiTask_raiseException
 * name:         eiTask_raiseException
 * global_name:  tTask_eiTask_raiseException
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiTask_raiseException(CELLIDX idx, TEXPTN pattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(iras_tex(ATTR_id, pattern));
}
