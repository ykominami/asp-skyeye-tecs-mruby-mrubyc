/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2007-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: at91skyeye.h 2613 2014-01-21 06:02:17Z ertl-honda $
 */

#ifndef TOPPERS_AT91SKYEYE_H
#define TOPPERS_AT91SKYEYE_H

#include <sil.h>

/*
 * ����ߥϥ�ɥ��ֹ椫�顤IRC���Τ���Υӥåȥѥ���������ޥ���
 */
#define INTNO_BITPAT(intno) (1U << intno)

/*
 *  ����ߥ���ȥ���ط�
 */
#define AIC_IVR      (0xFFFFF100)
#define AIC_ISR      (0xFFFFF108)
#define AIC_IMR      (0xFFFFF110)
#define AIC_IECR     (0xFFFFF120)
#define AIC_IDCR     (0xFFFFF124)
#define AIC_ICCR     (0xFFFFF128)
#define AIC_EOI      (0xFFFFF130)
#define AIC_IPR      (0xFFFFF10C)

#define IRQ_USART0      2
#define IRQ_TC1         5

/*
 *  �����޴�Ϣ
 */
#define TIMER_1_CCR      (0xFFFE0040)
#define TIMER_1_CMR      (0xFFFE0044)
#define TIMER_1_CV       (0xFFFE0050)
#define TIMER_1_SR       (0xFFFE0060)
#define TIMER_1_RC       (0xFFFE005C)
#define PIT_PIVR         (0xFFFFFD38)

/*
 * �ǥХ����ޥ͡�����Υޥ���ץ��å�������ǽ�ؤΥ��������쥸����
 * skyeye��conf�ե��������������礵���� 
 */
#define MUTEX_ID_REG     (0xFFFFFF00)
#define MUTEX_CNT_REG    (0xFFFFFF04)
#define IPI_REG          (0xffffff80)

/*
 *  UART��Ϣ
 */
#define USART0_THR       (0xFFFD001C)  // USART Transmitter Holding Register
#define USART0_RPR       (0xFFFD0030)  // USART Receive Pointer Register
#define USART0_RCR       (0xFFFD0034)  // USART Receive Counter Register
#define USART0_CSR       (0xFFFD0014)  // USART Channel Satus Register
#define USART0_IER       (0xFFFD0008)  // USART Interrupt Enable Register
#define USART0_IDR       (0xFFFD000C)  // USART Interrupt Disable Register

/* 
 *  �������륫���󥿴�Ϣ 
 */ 
#define CYCLE_COUNTER_REG (0xFFFFFFC0)

/*
 *  �С������쥸����
 */
#define SKYEYE_VER_REG  (0xFFFE1000)
#define DEVM_VER_REG    (0xFFFE1010)

#ifndef TOPPERS_MACRO_ONLY

/*
 * IRC���ؿ�
 */

/*
 * ������׵�Υޥ���
 */
Inline void
at91skyeye_disable_int(uint32_t mask)
{
    sil_wrw_mem((void *)(AIC_IDCR), mask);
}

/*
 * ������׵�Υޥ����β��
 */
Inline void
at91skyeye_enable_int(uint32_t mask)
{
    sil_wrw_mem((void *)(AIC_IECR), mask);
}

/*
 * ������׵�Υ��ꥢ
 */
Inline void
at91skyeye_clear_int(uint32_t mask)
{
    sil_wrw_mem((void *)(AIC_ICCR), mask);	
}

/*
 * ������׵�Υ����å�
 */
Inline bool_t
at91skyeye_probe_int(uint32_t mask)
{
    return((sil_rew_mem((void *)(AIC_IPR)) & mask) == mask);
}

/*
 * ��λ����
 */
Inline void
at91skyeye_exit(void)
{    
}

/* 
 *  �������륫���󥿤��ɤ߹��� 
 */ 
Inline uint32_t 
cycle_counter_get_current(void)
{ 
        return sil_rew_mem((void*)(CYCLE_COUNTER_REG)); 
}

/*
 *  �ȥ졼�����˴ؤ������
 *  �������륫���󥿤��Ѥ��롥
 */
#define TRACE_GET_TIM()   cycle_counter_get_current()

#endif /* TOPPPERS_MACRO_ONLY */


#endif /* TOPPERS_AT91SAM7S_H */
