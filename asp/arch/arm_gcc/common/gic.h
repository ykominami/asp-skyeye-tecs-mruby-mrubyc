/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2012 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: gic.h 2409 2012-08-30 08:08:57Z ertl-honda $
 */

/*
 *  ARM Generic Interrupt Controller �ɥ饤��
 */

#ifndef TOPPERS_GIC_H
#define TOPPERS_GIC_H

#include <sil.h>
#include <arm.h>

/*
 *  CPU Interface
 *
 *  ͥ���٤ϡ�0x0��0xF ��16�ʳ���
 *  0x0���ǹ�ͥ���٤ǡ�0xF������ͥ���١�
 */
#define GICC_CTLR (GICC_BASE + 0x00)  /* ����ȥ���쥸���� */
#define GICC_PMR  (GICC_BASE + 0x04)  /* ͥ���٥ޥ����쥸���� */
#define GICC_BPR  (GICC_BASE + 0x08)  /* �Х��ʥ�ݥ���ȥ쥸���� */
#define GICC_IAR  (GICC_BASE + 0x0C)  /* Interrupt Acknowledge Register */
#define GICC_EOIR (GICC_BASE + 0x10)  /* End of Interrupt Register */
#define GICC_RPR  (GICC_BASE + 0x14)  /* Running Interrupt Register */

#define GICC_CTLR_EN      0x01
#define GICC_CTLR_ENABLEGRP0 0x01
#define GICC_CTLR_ENABLEGRP1 0x02
#define GICC_CTLR_CBPR       0x10
#define GICC_CTLR_FIQEn      0x08

#if GIC_PRI_LEVEL == 16
#define GICC_PMR_OFFSET 0x04
#define GICC_PMR_MASK   0x0f
#elif GIC_PRI_LEVEL == 32
#define GICC_PMR_OFFSET 0x03
#define GICC_PMR_MASK   0x1f
#elif GIC_PRI_LEVEL == 64
#define GICC_PMR_OFFSET 0x02
#define GICC_PMR_MASK   0x3f
#elif GIC_PRI_LEVEL == 128
#define GICC_PMR_OFFSET 0x01
#define GICC_PMR_MASK   0x7f
#elif GIC_PRI_LEVEL == 256
#define GICC_PMR_OFFSET 0x00
#define GICC_PMR_MASK   0xff
#else
#error
#endif /* GIC_PRI_LEVEL == 16 */

/*
 *  Distributor
 */
#define GICD_CTLR        (GICD_BASE + 0x0000)  /* ����ȥ���쥸���� */
#define GICD_TYPER       (GICD_BASE + 0x0004)  /* Interrupt Controller �����ץ쥸���� */
#define GICD_IIDR        (GICD_BASE + 0x0008)  /* Distributor Implementer ID */
#define GICD_IGROUPRn    (GICD_BASE + 0x0080)  /* ����ߥ������ƥ� */
#define GICD_ISENABLERn  (GICD_BASE + 0x0100)  /* ����ߥ��͡��֥륻�å�   */
#define GICD_ICENABLERn  (GICD_BASE + 0x0180)  /* ����ߥ��͡��֥륯�ꥢ�� */
#define GICD_ISPENDRn    (GICD_BASE + 0x0200)  /* ����ߥ��åȥڥ�ǥ��� */
#define GICD_ICPENDRn    (GICD_BASE + 0x0280)  /* ����ߥ��ꥢ���ڥ�ǥ��� */
#define GICD_ISACTIVERn  (GICD_BASE + 0x0300)  /* ����ߥ��åȥ����ƥ��֥쥸������ */
#define GICD_IPRIORITYRn (GICD_BASE + 0x0400)  /* �����ͥ���٥쥸���� */
#define GICD_ITARGETSRn  (GICD_BASE + 0x0800)  /* ����ߥ������åȥ쥸����/CA9��SPI�������åȥ쥸���� */
#define GICD_ICFGRn      (GICD_BASE + 0x0C00)  /* ����ߥ���ե�����졼�����쥸���� */
#define GICD_SGIR        (GICD_BASE + 0x0F00)  /* ���եȥ���������ߥ쥸����  */

#define GICD_PPIS        (GICD_BASE + 0x0D00)  /* PPI���ơ����� */
#define GICD_SPIS        (GICD_BASE + 0x0D04)  /* SPI���ơ����� */

#define GICD_CTLR_ENABLE 0x01

/*
 *  �������Υץ��å��λ���
 */
#define GICD_ITARGETSRn_CPU0  0x01
#define GICD_ITARGETSRn_CPU1  0x02
#define GICD_ITARGETSRn_CPU2  0x04
#define GICD_ITARGETSRn_CPU3  0x08

#define GICD_SGIR_CPU0  0x01
#define GICD_SGIR_CPU1  0x02
#define GICD_SGIR_CPU2  0x04
#define GICD_SGIR_CPU3  0x08
#define GICD_SGIR_CPUS  0x0f

#define GICD_SGIR_CPU_OFFSET 16

/*
 *  �����ͥ����
 */
#define GIC_MAX_PRIORITY  0x00
#define GIC_MIN_PRIORITY  GICC_PMR_MASK

/*
 *  ����ե�����졼�����쥸������������
 */
#define GICD_ICFGRn_EDGE     0x03   /* ���å������ */
#define GICD_ICFGRn_LEVEL    0x00   /* ��٥����� */
#define GICD_ICFGRn_N_N      0x00   /* N-N��ǥ�    */
#define GICD_ICFGRn_1_N      0x01   /* 1-N��ǥ�    */

/*
 *  GIC�ǥ��ݡ��Ȥ��Ƥ������߿�
 */
#define GIC_TMIN_INTNO      0U

#ifndef GIC_TMAX_INTNO
#define GIC_TMAX_INTNO    255U
#endif /* GIC_TMAX_INTNO */

#ifndef GIC_TNUM_INT
#define GIC_TNUM_INT      256U
#endif /* GIC_TNUM_INT */

/*
 *  �����Х����ߤγ����ֹ�
 */
#define TMIN_GLOBAL_INTNO   32U

/*
 * ������ֹ�(GIC�Ǥ��ֹ�)
 */
#define GIC_IRQNO_IPI0     0
#define GIC_IRQNO_IPI1     1

#ifndef TOPPERS_MACRO_ONLY

/*
 *  GIC CPU Interface ��Ϣ�Υɥ饤��
 */
/*
 *  CPU�γ����ͥ���٥ޥ���������
 */ 
Inline void
gicc_set_priority(int pri)
{
	sil_wrw_mem((void *)GICC_PMR,
				(pri << GICC_PMR_OFFSET));
}

/*
 *  CPU�γ����ͥ���٥ޥ��������
 */ 
Inline int
gicc_current_priority(void)
{
	return (sil_rew_mem((void *)(GICC_PMR)) >>
			GICC_PMR_OFFSET);    
}

/*
 *  ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 */
Inline void
gicc_end_int(uint8_t id)
{
	sil_wrw_mem((void *)(GICC_EOIR), id);
}

/*
 *  GIC�Υץ��å��γ����ͥ���٤ΤɤΥӥåȤ���Ѥ��뤫
 */
Inline void
gicc_set_bp(int mask_bit)
{
	sil_wrw_mem((void *)GICC_BPR, mask_bit);
}

/*
 *  GIC CPU Interface �ν����
 */
extern void gicc_init(void);

/*
  *  GIC CPU Interface �ν�λ
 */
extern void gicc_stop(void);

/*
 *  Distributor ��Ϣ�Υɥ饤��
 */

/*
 *  ����߶ػ�
 */
extern void gicd_disable_int(uint8_t id);

/*
 *  ����ߵ���
 */
extern void gicd_enable_int(uint8_t id);

/*
 *  ����ߥڥ�ǥ��󥰥��ꥢ
 */
extern void gicd_clear_pending(uint8_t id);

/*
 *  ����ߥڥ�ǥ��󥰥��å�
 */
extern void gicd_set_pending(uint8_t id);

/*
 *  ������׵�Υ����å�
 */
extern bool_t gicd_probe_int(uint8_t id);

/*
 *  ���������Υ��å�
 */
extern void gicd_config(uint8_t id, bool_t is_edge, bool_t is_1_n);

/*
 *  �����ͥ���٤Υ��å�
 *  ����ɽ�����Ϥ��� 
 */
extern void gicd_set_priority(uint8_t id, int pri);

/*
 *  ����ߥ������åȤ�����
 *  CPU��OR�ǻ���  
 */
extern void gicd_set_target(uint8_t id, uint8_t cpus);

/*
 *  Ditoributor �ν����
 */
extern void gicd_init(void);

/*
 *  Ditoributor �ν�����ν�λ
 */
extern void gicd_stop(void);

/*
 *  ���եȥ���������ߤ�ȯ��
 */
Inline void
gic_raise_sgi(int cpu, int id)
{
	CP15_DATA_SYNC_BARRIER();
	sil_wrw_mem((void *)GICD_SGIR, (cpu << GICD_SGIR_CPU_OFFSET)|id);
	CP15_DATA_SYNC_BARRIER();
}

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_GIC_H */
