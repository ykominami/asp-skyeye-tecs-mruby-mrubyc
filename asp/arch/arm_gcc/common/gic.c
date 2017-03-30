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
 *  @(#) $Id: gic.c 2486 2013-02-21 14:02:05Z ertl-honda $
 */

#include "kernel_impl.h"

/*
 *  CPU Interface ��Ϣ
 */

/*
 *  CPU Interface �ν����
 */
void
gicc_init(void)
{
	/* CPU���󥿥ե�������̵���� */
	sil_wrw_mem((void *)GICC_CTLR, 0);

	/* ����ͥ���٤����� */
	gicc_set_priority(GIC_MIN_PRIORITY);

	/* �����ͥ���٤����ӥå�ͭ���� */
	gicc_set_bp(0);

	/* �ڥ�ǥ��󥰤��Ƥ����ǽ��������Τǡ�EOI �ˤ�ꥯ�ꥢ */
	sil_wrw_mem((void *)GICC_EOIR,
				sil_rew_mem((void *)GICC_IAR));

	/* CPU���󥿥ե�������ͭ���� */
#ifdef GIC_USE_FIQ
	sil_wrw_mem((void *)GICC_CTLR,
				(GICC_CTLR_FIQEn|GICC_CTLR_ENABLEGRP1|GICC_CTLR_ENABLEGRP0));
#else /* GIC_USE_FIQ */
	sil_wrw_mem((void *)GICC_CTLR, GICC_CTLR_EN);
#endif /* GIC_USE_FIQ */
}

/*
 *  CPU Interface �ν�λ
 */
void
gicc_stop(void)
{
#ifndef GICC_NO_INIT
	sil_wrw_mem((void *)(GICC_CTLR), 0);
#endif /* GICC_NO_INIT */
}

/*
 *  Distoributor ��Ϣ
 */

/*
 *  ����߶ػ�
 */
void
gicd_disable_int(uint8_t id)
{
	uint16_t offset_addr;
	uint16_t offset_bit;

	offset_addr = (id / 32) * 4;
	offset_bit  = id % 32;

	sil_wrw_mem((void *)(GICD_ICENABLERn + offset_addr), (1 << offset_bit));
}

/*
 *  ����ߵ���
 */
void
gicd_enable_int(uint8_t id)
{
	uint16_t offset_addr;
	uint16_t offset_bit;

	offset_addr = (id / 32) * 4;
	offset_bit  = id % 32;

	sil_wrw_mem((void *)(GICD_ISENABLERn + offset_addr), (1 << offset_bit));
}

/*
 *  ����ߥڥ�ǥ��󥰥��ꥢ
 */
void
gicd_clear_pending(uint8_t id)
{
	uint16_t offset_addr;
	uint16_t offset_bit;

	offset_addr = (id / 32) * 4;
	offset_bit  = id % 32;

	sil_wrw_mem((void *)(GICD_ICPENDRn + offset_addr), (1 << offset_bit));
}

/*
 *  ����ߥڥ�ǥ��󥰥��å�
 */
void
gicd_set_pending(uint8_t id)
{
	uint16_t offset_addr;
	uint16_t offset_bit;

	offset_addr = (id / 32) * 4;
	offset_bit  = id % 32;

	sil_wrw_mem((void *)(GICD_ISPENDRn + offset_addr), (1 << offset_bit));
}

/*
 *  ������׵�Υ����å�
 */
bool_t
gicd_probe_int(uint8_t id)
{
	uint32_t state;
	uint16_t offset_addr;
	uint16_t offset_bit;

	offset_addr = (id / 32) * 4;
	offset_bit  = id % 32;

	state = sil_rew_mem((void *)(GICD_ISPENDRn + offset_addr));

	if ((state & (1 << offset_bit)) == (1 << offset_bit)) {
		return(true);
	}
	else {
		return(false);
	}
}

/*
 *  ����ߥ���ե�����졼���������
 */
void
gicd_config(uint8_t id,  bool_t is_edge, bool_t is_1_n)
{
	uint16_t offset_addr;
	uint16_t offset_bit;
	uint32_t cfgr_reg_val;
	uint8_t  config;

	if (is_edge) {
		config = GICD_ICFGRn_EDGE;
	}
	else {
		config = GICD_ICFGRn_LEVEL;
	}

	if (is_1_n) {
		config |= GICD_ICFGRn_1_N;
	}
	else {
		config |= GICD_ICFGRn_N_N;
	}
	
	
	offset_addr = (id / 16) * 4;
	offset_bit  = (id % 16) * 2;

	cfgr_reg_val  = sil_rew_mem((void *)(GICD_ICFGRn + offset_addr));
	cfgr_reg_val &= ~(0x03U << offset_bit);
	cfgr_reg_val |= (0x03U & config) << offset_bit;
	sil_wrw_mem((void *)(GICD_ICFGRn + offset_addr), cfgr_reg_val);

#ifdef GIC_USE_FIQ
	offset_addr = (id / 32) * 4;
	offset_bit  = id % 32;

	sil_wrw_mem((void *)(GICD_IGROUPRn + offset_addr),
				sil_rew_mem((void *)(GICD_IGROUPRn+ offset_addr)) & ~(1 << offset_bit));
#endif /* GIC_USE_FIQ */
}

/*
 *  �����ͥ���٤Υ��å�
 *  ����ɽ�����Ϥ���
 */
void
gicd_set_priority(uint8_t id, int pri)
{
	uint16_t offset_addr;
	uint16_t offset_bit;
	uint32_t pr_reg_val;

	offset_addr = (id / 4) * 4;
	offset_bit  = ((id % 4) * 8) + GICC_PMR_OFFSET;

	pr_reg_val  = sil_rew_mem((void *)(GICD_IPRIORITYRn + offset_addr));
	pr_reg_val &= ~(GICC_PMR_MASK << offset_bit);
	pr_reg_val |= (GICC_PMR_MASK & pri) << (offset_bit);
	sil_wrw_mem((void *)(GICD_IPRIORITYRn + offset_addr), pr_reg_val);
}

/*
 *  DIC����ߥ������åȤ�����
 *  cpus�ϥ������åȤȤ���CPU�Υӥåȥѥ�����ǻ���
 *   CPU0 : 0x01
 *   CPU1 : 0x02
 *   CPU2 : 0x04
 *   CPU3 : 0x08
 */
void
gicd_set_target(uint8_t id, uint8_t cpus)
{
	uint32_t offset_addr;
	uint32_t offset_bit;
	uint32_t itr_reg_val;

	offset_addr = (id / 4) * 4;
	offset_bit  = (id % 4) * 8;

	itr_reg_val  = sil_rew_mem((void *)(GICD_ITARGETSRn + offset_addr));
	itr_reg_val &= ~(0xf << offset_bit);
	itr_reg_val |= (cpus << offset_bit);
	sil_wrw_mem((void *)(GICD_ITARGETSRn + offset_addr), itr_reg_val);
}

/*
 *  Distributor �����
 */
void
gicd_init(void)
{
	int i;

	/* Distributor ��̵���� */
	sil_wrw_mem((void *)(GICD_CTLR), 0);

#ifdef GIC_USE_FIQ
	/* ����ߤ����ƥ��롼��1(IRQ)�� */
	for(i = 0; i < GIC_TNUM_INT/32; i++){
		sil_wrw_mem((void *)(GICD_IGROUPRn + (4 * i)), 0xffffffff);
	}
#endif /* GIC_USE_FIQ */

	/* ����ߤ����ƶػ� */
	for(i = 0; i < GIC_TNUM_INT/32; i++){
		sil_wrw_mem((void *)(GICD_ICENABLERn + (4 * i)), 0xffffffff);
	}

	/* �ڥ�ǥ��󥰤򥯥ꥢ */
	for(i = 0; i < GIC_TNUM_INT/32; i++){
		sil_wrw_mem((void *)(GICD_ICPENDRn + (4 * i)), 0xffffffff);
	}

	/* ͥ���ٺ��������  */
	for(i = 0; i < GIC_TNUM_INT/4; i++){
		sil_wrw_mem((void *)(GICD_IPRIORITYRn + (4 * i)), 0xffffffff);
	}

	/* �������åȽ����������CPU0�ء� */
	for(i = TMIN_GLOBAL_INTNO/4; i < GIC_TNUM_INT/4; i++){
		sil_wrw_mem((void *)(GICD_ITARGETSRn + (4 * i)), 0x01010101);
	}

	/* �⡼�ɽ����(1-N Level) */
	for(i = 0; i < GIC_TNUM_INT/16; i++){
		sil_wrw_mem((void *)(GICD_ICFGRn + (4 * i)), 0x55555555);
	}

	/* Distibutor ��ͭ���� */
	sil_wrw_mem((void *)(GICD_CTLR), GICD_CTLR_ENABLE);
}

/*
 *  Distributor ��λ
 */
void
gicd_stop(void)
{
	/* Distributor ��̵���� */
	sil_wrw_mem((void *)(GICD_CTLR), 0);
}

#ifdef TOPPERS_SAFEG_SECURE
int spurious_cnt;

/*
 *  ID�ֹ�1022�γ����(Spurious)�����ä���硤
 *  Active�ʳ���ߤ����뤫�����å����ơ�Active�ʳ���ߤ������
 *  ����ID��꥿���󤹤롥
 *  Secure¦�γ���ߤ����ä��ˤ⤫����餺�� ID�ֹ�1022�γ����(Spurious)�Ȥ���
 *  ���Τ���븽��(�Զ��?) ���б�
 */
unsigned int
check_spurious_1022(void){
	unsigned int val, id;
	int i, e;

	spurious_cnt++;
	for(i = 0; i < GIC_TNUM_INT/32; i++) {
		val = sil_rew_mem((void *)GICD_ISACTIVERn + (4 * i));
		if (val != 0x00){
			for(e = 0; e < 32; e++) {
				if ((val & (1 << e)) != 0){
					id = (i * 32 + e);
					/* �����°�������ꤵ��Ƥ����(���Ѥ��Ƥ������ߤʤ�) */
					if (cfgint_tbl[id] == 1U) {
						return id;
					}
				}
			}
		}
	}
	return 1022;
}
#endif /* TOPPERS_SAFEG_SECURE */
