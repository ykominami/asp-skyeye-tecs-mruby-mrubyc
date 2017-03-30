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
 *  @(#) $Id: tFixedSizeMemoryPool_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/* 
 * °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id
 */

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eEventflag
 * entry port: eEventflag
 * signature:  sEventflag
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEventflag_set
 * name:         eEventflag_set
 * global_name:  tEventflag_eEventflag_set
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eEventflag_set(CELLIDX idx, FLGPTN setPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(set_flg(ATTR_id, setPattern));
}

/* #[<ENTRY_FUNC>]# eEventflag_clear
 * name:         eEventflag_clear
 * global_name:  tEventflag_eEventflag_clear
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eEventflag_clear(CELLIDX idx, FLGPTN clearPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(clr_flg(ATTR_id, clearPattern));
}

/* #[<ENTRY_FUNC>]# eEventflag_wait
 * name:         eEventflag_wait
 * global_name:  tEventflag_eEventflag_wait
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eEventflag_wait(CELLIDX idx, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(wai_flg(ATTR_id, waitPattern, waitFlagMode, p_flagPattern));
}

/* #[<ENTRY_FUNC>]# eEventflag_waitPolling
 * name:         eEventflag_waitPolling
 * global_name:  tEventflag_eEventflag_waitPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eEventflag_waitPolling(CELLIDX idx, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(pol_flg(ATTR_id, waitPattern, waitFlagMode, p_flagPattern));
}

/* #[<ENTRY_FUNC>]# eEventflag_waitTimeout
 * name:         eEventflag_waitTimeout
 * global_name:  tEventflag_eEventflag_waitTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eEventflag_waitTimeout(CELLIDX idx, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(twai_flg(ATTR_id, waitPattern, waitFlagMode, p_flagPattern, timeout));
}

/* #[<ENTRY_FUNC>]# eEventflag_initialize
 * name:         eEventflag_initialize
 * global_name:  tEventflag_eEventflag_initialize
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eEventflag_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_flg(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eEventflag_refer
 * name:         eEventflag_refer
 * global_name:  tEventflag_eEventflag_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eEventflag_refer(CELLIDX idx, T_RFLG* pk_eventflagStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_flg(ATTR_id, pk_eventflagStatus));
}

/* #[<ENTRY_PORT>]# eiEventflag
 * entry port: eiEventflag
 * signature:  siEventflag
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiEventflag_set
 * name:         eiEventflag_set
 * global_name:  tEventflag_eiEventflag_set
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiEventflag_set(CELLIDX idx, FLGPTN setPattern)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(iset_flg(ATTR_id, setPattern));
}

