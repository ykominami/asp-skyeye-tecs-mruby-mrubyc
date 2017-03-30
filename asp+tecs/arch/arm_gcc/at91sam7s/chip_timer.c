/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN  
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: chip_timer.c 565 2007-10-31 07:04:13Z honda $
 */

/*
 *  �����ޥɥ饤�С�AT91SAM7S�ѡ�
 */

#include "kernel_impl.h"
#include "time_event.h"
#include <sil.h>
#include "target_timer.h"

/*
 *  �����ޤε�ư����
 */
void
target_timer_initialize(intptr_t exinf)
{
    CLOCK    cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

    /*
     *  �����޴�Ϣ������
     */
    /* ����å����͡��֥� */
    sil_wrw_mem((void*)(TADR_PMC_BASE+TOFF_PMC_PCER), (1<<INTNO_TC0_PID));
    /* ��������� */
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_CCR), TC_CLKDIS);
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_IDR), 0xFFFFFFFF);
    /* �����޾���ͤΥ����å� */
    assert(cyc <= MAX_CLOCK);
    /* ��������ͤ򥻥å� */
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_CMR), TC_CLKS_MCK8);	/* 47,923,200Hz/8=5,990,400Hz */
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_CMR), sil_rew_mem((void*)(TADR_TC_BASE+TOFF_TC_CMR)) | TC_WAVESEL10);
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_RC), cyc);
    /* ����ߤΥ��ꥢ  */
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_IER), TC_CPCS);
    /* ������ȥ�������   */
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_CCR), (TC_CLKEN|TC_SWTRG));
}

/*
 *  �����ޤ���߽���
 */
void
target_timer_terminate(intptr_t exinf)
{
    /* �ڥ�ǥ��󥰥ӥåȤ򥯥ꥢ */
    sil_rew_mem((void*)(TADR_TC_BASE+TOFF_TC_SR));
    sil_wrw_mem((void*)(TADR_AIC_BASE+TOFF_AIC_EOICR), 0);
    /* ��������� */
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_CCR), TC_CLKDIS);
    /* ������Ե���*/
    sil_wrw_mem((void*)(TADR_TC_BASE+TOFF_TC_IDR), TC_CPCS);    
}

/*
 *  �����޳���ߥϥ�ɥ�
 */
void
target_timer_handler(void)
{
    sil_rew_mem((void *)(TADR_TC_BASE+TOFF_TC_SR));
    
    i_begin_int(INTNO_TIMER);
    signal_time();                    /* ������ƥ��å��ζ��� */
    i_end_int(INTNO_TIMER);
}
