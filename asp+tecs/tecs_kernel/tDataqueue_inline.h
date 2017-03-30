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
 *  @(#) $Id: tDataqueue_inline.h 308 2009-05-09 12:33:04Z ertl-takuya $
 */

/*
 * °�����������ޥ��� #_CAAM_#
 * id               ID               ATTR_id         
 */

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eDataqueue
 * entry port: eDataqueue
 * signature:  sDataqueue
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eDataqueue_send
 * name:         eDataqueue_send
 * global_name:  tDataqueue_eDataqueue_send
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_send(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(snd_dtq(ATTR_id, data));
}

/* #[<ENTRY_FUNC>]# eDataqueue_sendPolling
 * name:         eDataqueue_sendPolling
 * global_name:  tDataqueue_eDataqueue_sendPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(psnd_dtq(ATTR_id, data));
}
/* #[<ENTRY_FUNC>]# eDataqueue_sendTimeout
 * name:         eDataqueue_sendTimeout
 * global_name:  tDataqueue_eDataqueue_sendTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_sendTimeout(CELLIDX idx, intptr_t data, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(tsnd_dtq(ATTR_id, data, timeout));
}

/* #[<ENTRY_FUNC>]# eDataqueue_sendForce
 * name:         eDataqueue_sendForce
 * global_name:  tDataqueue_eDataqueue_sendForce
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(fsnd_dtq(ATTR_id, data));
}

/* #[<ENTRY_FUNC>]# eDataqueue_receive
 * name:         eDataqueue_receive
 * global_name:  tDataqueue_eDataqueue_receive
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_receive(CELLIDX idx, intptr_t* p_data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rcv_dtq(ATTR_id, p_data));
}

/* #[<ENTRY_FUNC>]# eDataqueue_receivePolling
 * name:         eDataqueue_receivePolling
 * global_name:  tDataqueue_eDataqueue_receivePolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_receivePolling(CELLIDX idx, intptr_t* p_data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(prcv_dtq(ATTR_id, p_data));
}

/* #[<ENTRY_FUNC>]# eDataqueue_receiveTimeout
 * name:         eDataqueue_receiveTimeout
 * global_name:  tDataqueue_eDataqueue_receiveTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_receiveTimeout(CELLIDX idx, intptr_t* p_data, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(trcv_dtq(ATTR_id, p_data, timeout));
}

/* #[<ENTRY_FUNC>]# eDataqueue_initialize
 * name:         eDataqueue_initialize
 * global_name:  tDataqueue_eDataqueue_initialize
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_dtq(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eDataqueue_refer
 * name:         eDataqueue_refer
 * global_name:  tDataqueue_eDataqueue_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eDataqueue_refer(CELLIDX idx, T_RDTQ* pk_dataqueueStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_dtq(ATTR_id, pk_dataqueueStatus));
}

/* #[<ENTRY_PORT>]# eiDataqueue
 * entry port: eiDataqueue
 * signature:  siDataqueue
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiDataqueue_sendPolling
 * name:         eiDataqueue_sendPolling
 * global_name:  tDataqueue_eiDataqueue_sendPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ipsnd_dtq(ATTR_id, data));
}

/* #[<ENTRY_FUNC>]# eiDataqueue_sendForce
 * name:         eiDataqueue_sendForce
 * global_name:  tDataqueue_eiDataqueue_sendForce
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eiDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ifsnd_dtq(ATTR_id,  data));
}

