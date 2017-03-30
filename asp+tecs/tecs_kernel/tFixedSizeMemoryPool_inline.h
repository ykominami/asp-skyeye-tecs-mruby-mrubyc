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
/* #[<ENTRY_PORT>]# eFixedSizeMemoryPool
 * entry port: eFixedSizeMemoryPool
 * signature:  sFixedSizeMemoryPool
 * context:    task
 * params: 
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eFixedSizeMemoryPool_get
 * name:         eFixedSizeMemoryPool_get
 * global_name:  tFixedSizeMemoryPool_eFixedSizeMemoryPool_get
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eFixedSizeMemoryPool_get(CELLIDX idx, void** p_block)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(get_mpf( ATTR_id, p_block));
}

/* #[<ENTRY_FUNC>]# eFixedSizeMemoryPool_getPolling
 * name:         eFixedSizeMemoryPool_getPolling
 * global_name:  tFixedSizeMemoryPool_eFixedSizeMemoryPool_getPolling
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eFixedSizeMemoryPool_getPolling(CELLIDX idx, void** p_block)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(pget_mpf(ATTR_id, p_block));
}

/* #[<ENTRY_FUNC>]# eFixedSizeMemoryPool_getTimeout
 * name:         eFixedSizeMemoryPool_getTimeout
 * global_name:  tFixedSizeMemoryPool_eFixedSizeMemoryPool_getTimeout
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eFixedSizeMemoryPool_getTimeout(CELLIDX idx, void** p_block, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(tget_mpf(ATTR_id, p_block, timeout));
}

/* #[<ENTRY_FUNC>]# eFixedSizeMemoryPool_release
 * name:         eFixedSizeMemoryPool_release
 * global_name:  tFixedSizeMemoryPool_eFixedSizeMemoryPool_release
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eFixedSizeMemoryPool_release(CELLIDX idx, const void* block)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(rel_mpf(ATTR_id, (void *)block));
}

/* #[<ENTRY_FUNC>]# eFixedSizeMemoryPool_initialize
 * name:         eFixedSizeMemoryPool_initialize
 * global_name:  tFixedSizeMemoryPool_eFixedSizeMemoryPool_initialize
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eFixedSizeMemoryPool_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_mpf(ATTR_id));
}

/* #[<ENTRY_FUNC>]# eFixedSizeMemoryPool_refer
 * name:         eFixedSizeMemoryPool_refer
 * global_name:  tFixedSizeMemoryPool_eFixedSizeMemoryPool_refer
 * oneway:       
 * #[/ENTRY_FUNC>]# */
Inline ER
eFixedSizeMemoryPool_refer(CELLIDX idx, T_RMPF* pk_memoryPoolFixedSizeStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_mpf(ATTR_id, pk_memoryPoolFixedSizeStatus));
}

