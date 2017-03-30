/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
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
 *  @(#) $Id: core_kernel.h 2346 2012-04-26 07:15:16Z ertl-honda $
 */

/*
 *      kernel.h�Υ�����¸����ARM�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�target_kernel.h�ʤޤ��ϡ��������饤��
 *  �롼�ɤ����ե�����ˤΤߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��
 *  ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef TOPPERS_CORE_KERNEL_H
#define TOPPERS_CORE_KERNEL_H

#ifndef TOPPERS_MACRO_ONLY

#include "arm.h"

#if (__TARGET_ARCH_ARM == 4) || (__TARGET_ARCH_ARM == 5)
typedef struct {
	uint32_t nest_count;
	uint32_t ipm;
	uint32_t cpsr;
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r12;
	uint32_t lr;
	uint32_t pc;
} exc_frame_t;
#else /* (__TARGET_ARCH_ARM == 6) || (__TARGET_ARCH_ARM == 7) */
typedef struct {
	uint32_t nest_count;
	uint32_t ipm;
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r12;
	uint32_t lr;
	uint32_t pc;
	uint32_t cpsr;
} exc_frame_t;
#endif /* (__TARGET_ARCH_ARM == 6) || (__TARGET_ARCH_ARM == 7) */


/*
 * CPU�㳰���������襢�ɥ쥹�μ���
 */
Inline uint32_t
x_get_exc_raddr(void *p_excinf)
{
	return(((exc_frame_t *)(p_excinf))->pc);
}

/*
 * CPU�㳰���������襢�ɥ쥹������
 */
Inline void
x_set_exc_raddr(void *p_excinf, uint32_t pc)
{
	((exc_frame_t *)(p_excinf))->pc = pc;
}

#if __TARGET_ARCH_ARM == 7

/* ��ǽ��¬�ѤΥ����󥿤Υǡ����� */
typedef uint32_t PERFCNT;

/*
 *  �ѥե����ޥ󥹥����󥿤ν����
 */
Inline void
x_init_pcc(void)
{
	uint32_t tmp;
	/* �������󥿡���ͭ���� */
	CP15_PMCR_READ(tmp);

#ifdef TOPPERS_ARM_PCC_DIV64
	tmp |= CP15_PMCR_PMCCNTR_D;
#else /* !TOPPERS_ARM_PCC_DIV64 */
	tmp &= ~CP15_PMCR_PMCCNTR_D;
#endif /* TOPPERS_ARM_PCC_DIV64 */

	CP15_PMCR_WRITE(tmp|CP15_PMCR_ALLCNTR_ENABLE);

	/* �ѥե����ޥ󥹥����󥿤�ͭ���� */
	CP15_PMCNTENSET_READ(tmp);
	CP15_PMCNTENSET_WRITE(tmp|CP15_PMCNTENSET_CCNTR_ENABLE);
}

/*
 *  �ѥե����ޥ󥹥����󥿤��ɤ߹���
 */
Inline void 
x_get_pcc(PERFCNT *p_count)
{
	CP15_PMCCNTR_READ(*p_count);
}

/*
 *  �ѥե����ޥ󥹥����󥿤Υꥻ�å�
 */
Inline void
x_rst_pcc(void)
{
	uint32_t tmp;
	CP15_PMCR_READ(tmp);
	CP15_PMCR_WRITE(tmp|CP15_PMCR_PMCCNTR_CLEAR);
}

/*
 *  �������ͤ�nsec�ؤ��Ѵ�
 */
Inline ulong_t
x_cnv_nsec(PERFCNT count) {
#ifdef TOPPERS_ARM_PCC_DIV64
	return ((ulong_t)count*(1000/(CORE_CLK_MHZ/64)));
#else /* !TOPPERS_ARM_PCC_DIV64 */
	return ((ulong_t)count*(1000/CORE_CLK_MHZ));
#endif /* TOPPERS_ARM_PCC_DIV64 */
}

#elif __TARGET_ARCH_ARM == 6


#endif /* __TARGET_ARCH_ARM == 7 */

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_CORE_KERNEL_H */
