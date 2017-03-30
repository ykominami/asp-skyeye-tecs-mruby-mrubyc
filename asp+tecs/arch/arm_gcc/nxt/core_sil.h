/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id$
 */

/*
 *  sil.h�Υ�����¸����ARM�ѡ�
 */

#ifndef TOPPERS_CORE_SIL_H
#define TOPPERS_CORE_SIL_H

#ifndef TOPPERS_MACRO_ONLY
#if 0
/*
 *  ���٤Ƥγ���ߡ�FIQ��IRQ�ˤζػ�
 */
Inline uint32_t
TOPPERS_disint(void)
{
    uint32_t  cpsr;
    uint32_t  irq_fiq_mask;

    Asm("mrs  %0,CPSR" : "=r"(cpsr));
    irq_fiq_mask = cpsr & (0x40|0x80);
    cpsr |= (0x40|0x80);
    Asm("msr CPSR, %0" : : "r"(cpsr) :"memory", "cc");

    return(irq_fiq_mask);
}

/*
 *  FIQ,IRQ������
 */
Inline void
TOPPERS_set_fiq_irq(uint32_t TOPPERS_irq_fiq_mask)
{
    uint32_t  cpsr;

    Asm("mrs  %0,CPSR" : "=r"(cpsr));
    cpsr = cpsr & ~(0x40|0x80);
    cpsr = cpsr | (TOPPERS_irq_fiq_mask & (0x40|0x80));
    Asm("msr CPSR, %0" : : "r"(cpsr):"memory", "cc");
}
#else /* 0 */
/*
 *  ����쥸���������ؿ�
 */

/*
 *  ���ơ������쥸������CPSR�ˤθ����ͤ��ɽФ�
 */
extern uint32_t current_sr(void);

/*
 *  ���ơ������쥸������CPSR�ˤθ����ͤ��ѹ�
 */
extern void set_sr(uint32_t sr);

/*
 *  ���٤Ƥγ���ߡ�FIQ��IRQ�ˤζػ�
 */
Inline uint32_t
TOPPERS_disint(void)
{
    uint32_t  cpsr;
    uint32_t  irq_fiq_mask;

#ifndef THUMB_MODE
    Asm("mrs  %0,CPSR" : "=r"(cpsr));
    irq_fiq_mask = cpsr & (0x40|0x80);
    cpsr |= (0x40|0x80);
    Asm("msr CPSR, %0" : : "r"(cpsr) :"memory", "cc");
#else /* THUMB_MODE */
	cpsr = current_sr(); // ���ߤΥ��ơ������쥸��������
    irq_fiq_mask = cpsr & (0x40|0x80); // ���ߤ�IRQ��FIQ�Υޥ���
    cpsr |= (0x40|0x80); // IRQ��FIQ��ػ�
	set_sr(cpsr); // ���ơ������쥸����������
#endif /* THUMB_MODE */

    return(irq_fiq_mask);
}

/*
 *  FIQ,IRQ������
 */
Inline void
TOPPERS_set_fiq_irq(uint32_t TOPPERS_irq_fiq_mask)
{
    uint32_t  cpsr;

#ifndef THUMB_MODE
    Asm("mrs  %0,CPSR" : "=r"(cpsr));
    cpsr = cpsr & ~(0x40|0x80);
    cpsr = cpsr | (TOPPERS_irq_fiq_mask & (0x40|0x80));
    Asm("msr CPSR, %0" : : "r"(cpsr):"memory", "cc");
#else /* THUMB_MODE */
	cpsr = current_sr(); // ���ߤΥ��ơ������쥸����
    cpsr = cpsr & ~(0x40|0x80); // IRQ��FIQ�ʳ��ΥӥåȤϤ��Τޤ�
    cpsr = cpsr | (TOPPERS_irq_fiq_mask & (0x40|0x80)); // IRQ��FIQ�ΥӥåȤ�����
	set_sr(cpsr); // ���ơ������쥸����������
#endif /* THUMB_MODE */
	
}
#endif /* 0 */

/*
 *  ������ߥ�å����֤�����
 */
#define SIL_PRE_LOC   uint32_t TOPPERS_irq_fiq_mask
#define SIL_LOC_INT() ((void)(TOPPERS_irq_fiq_mask = TOPPERS_disint()))
#define SIL_UNL_INT() (TOPPERS_set_fiq_irq(TOPPERS_irq_fiq_mask))

/*
 *  ���������Ԥ�
 */
Inline void
sil_dly_nse(ulong_t dlytim)
{
    register uint32_t r0 asm("r0") = (uint32_t) dlytim;    
    Asm("bl _sil_dly_nse" : "=g"(r0) : "0"(r0) : "lr","cc");
}

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_CORE_SIL_H */
