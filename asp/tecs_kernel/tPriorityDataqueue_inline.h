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
 *  @(#) $Id: tPriorityDataqueue_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id
 */

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# ePriorityDataqueue
 * entry port: ePriorityDataqueue
 * signature:  sPriorityDataqueue
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_send
 * name:         ePriorityDataqueue_send
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_send
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_send(CELLIDX idx, intptr_t data, PRI dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(snd_pdq(ATTR_id, data, dataPriority));
}

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_sendPolling
 * name:         ePriorityDataqueue_sendPolling
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_sendPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_sendPolling(CELLIDX idx, intptr_t data, PRI dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(psnd_pdq(ATTR_id, data, dataPriority));
}

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_sendTimeout
 * name:         ePriorityDataqueue_sendTimeout
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_sendTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_sendTimeout(CELLIDX idx, intptr_t data, PRI dataPriority, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(tsnd_pdq(ATTR_id, data, dataPriority, timeout));
}

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_receive
 * name:         ePriorityDataqueue_receive
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_receive
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_receive(CELLIDX idx, intptr_t* p_data, PRI* p_dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rcv_pdq(ATTR_id, p_data, p_dataPriority));
}

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_receivePolling
 * name:         ePriorityDataqueue_receivePolling
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_receivePolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_receivePolling(CELLIDX idx, intptr_t* p_data, PRI* p_dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(prcv_pdq(ATTR_id, p_data, p_dataPriority));
}

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_receiveTimeout
 * name:         ePriorityDataqueue_receiveTimeout
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_receiveTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_receiveTimeout(CELLIDX idx, intptr_t* p_data, PRI* p_dataPriority, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(trcv_pdq(ATTR_id, p_data, p_dataPriority, timeout));
}

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_initialize
 * name:         ePriorityDataqueue_initialize
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_initialize
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_pdq(ATTR_id));
}

/* #[<ENTRY_FUNC>]# ePriorityDataqueue_refer
 * name:         ePriorityDataqueue_refer
 * global_name:  tPriorityDataqueue_ePriorityDataqueue_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
ePriorityDataqueue_refer(CELLIDX idx, T_RPDQ* pk_priorityDataqueueStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_pdq(ATTR_id, pk_priorityDataqueueStatus));
}

/* #[<ENTRY_PORT>]# eiPriorityDataqueue
 * entry port: eiPriorityDataqueue
 * signature:  siPriorityDataqueue
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiPriorityDataqueue_sendPolling
 * name:         eiPriorityDataqueue_sendPolling
 * global_name:  tPriorityDataqueue_eiPriorityDataqueue_sendPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiPriorityDataqueue_sendPolling(CELLIDX idx, intptr_t data, PRI dataPriority)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ipsnd_pdq(ATTR_id, data, dataPriority));
}

