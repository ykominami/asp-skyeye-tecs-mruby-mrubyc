/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: core_sil.h 2266 2011-11-22 09:40:42Z ertl-honda $
 */

/*
 *  sil.h�Υ�����¸����ARM�ѡ�
 */

#ifndef TOPPERS_CORE_SIL_H
#define TOPPERS_CORE_SIL_H

#ifndef TOPPERS_MACRO_ONLY

#ifdef __thumb__
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
#endif /* __thumb__ */

/*
 *  ���٤Ƥγ���ߡ�FIQ��IRQ�ˤζػ�
 */
Inline uint32_t
TOPPERS_disint(void)
{
    uint32_t  cpsr;
    uint32_t  irq_fiq_mask;

#ifndef __thumb__
    Asm("mrs  %0,CPSR" : "=r"(cpsr));
    irq_fiq_mask = cpsr & (0x40|0x80);
    cpsr |= (0x40|0x80);
    Asm("msr CPSR, %0" : : "r"(cpsr) :"memory", "cc");
#else /* __thumb__ */
    cpsr = current_sr();
    irq_fiq_mask = cpsr & (0x40|0x80);
    cpsr |= (0x40|0x80);
    set_sr(cpsr);
#endif /* __thumb__ */

    return(irq_fiq_mask);
}

/*
 *  FIQ,IRQ������
 */
Inline void
TOPPERS_set_fiq_irq(uint32_t TOPPERS_irq_fiq_mask)
{
    uint32_t  cpsr;

#ifndef __thumb__
    Asm("mrs  %0,CPSR" : "=r"(cpsr));
    cpsr = cpsr & ~(0x40|0x80);
    cpsr = cpsr | (TOPPERS_irq_fiq_mask & (0x40|0x80));
    Asm("msr CPSR, %0" : : "r"(cpsr):"memory", "cc");
#else /* __thumb__ */
    cpsr = current_sr();
    cpsr = cpsr &  ~(0x40|0x80);
    cpsr = cpsr | (TOPPERS_irq_fiq_mask&  (0x40|0x80));
    set_sr(cpsr);
#endif /* __thumb__ */
}

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
