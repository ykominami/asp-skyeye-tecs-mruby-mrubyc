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
 *  @(#) $Id: arm.c 2410 2012-08-30 08:22:53Z ertl-honda $
 */

#include "kernel_impl.h"

#if (__TARGET_ARCH_ARM == 6) || (__TARGET_ARCH_ARM == 7)
/*
 *  D����å���򳫻�
 */
void
dcache_enable(void)
{
	uint32_t bits;

	CP15_CONTROL_READ(bits);

	/* ���Ǥ�ON�ʤ�꥿���� */
	if (bits & CP15_CONTROL_C_BIT){
		return;
	}

	dcache_invalidate();

	bits |= CP15_CONTROL_C_BIT;
	CP15_CONTROL_WRITE(bits);
}

/*
 *  D����å������ߤ���̵���Ȥ��롥
 *  CA9�Ǥϡ�D����å��夬̵���ʾ��֤�Clean and Invalidate()��¹Ԥ���ȡ�
 *  ˽�����뤿�ᡤD����å���ξ��֤�Ƚ�Ǥ��ơ�̵���ʾ��ϡ�Invalidate
 *  �Τߤ�Ԥ��� 
 */
void
dcache_disable(void)
{
	uint32_t bits;

	CP15_CONTROL_READ(bits);
	if( bits & CP15_CONTROL_C_BIT ){
		bits &= ~CP15_CONTROL_C_BIT;
		CP15_CONTROL_WRITE(bits);
		dcache_clean_and_invalidate();
	}
	else{
		dcache_invalidate();
	}
}

/*
 *  I����å���γ���
 */
void
icache_enable(void)
{
	uint32_t bits;

	CP15_CONTROL_READ(bits);

	/*
	 *  ���Ǥ�ͭ���ʤ�꥿����
	 */
	if(bits & CP15_CONTROL_I_BIT){
		return;
	}

	icache_invalidate();

	bits |= CP15_CONTROL_I_BIT;
	CP15_CONTROL_WRITE(bits);
}

/*
 *  I����å�������
 */
void
icache_disable(void)
{
	uint32_t bits;

	CP15_CONTROL_READ(bits);
	bits &= ~CP15_CONTROL_I_BIT;
	CP15_CONTROL_WRITE(bits);

	icache_invalidate();
}

/*
 *  I/D����å����ξ����ͭ����
 */
void
cache_enable(void)
{
	dcache_enable();
	icache_enable();
}

/*
 *  I/D����å����ξ����̵����
 */
void
cache_disable(void)
{
	dcache_disable();
	icache_disable();
}

/*
 *  MMU��Ϣ�Υɥ饤��
 */
#define DOMAIN_NO  1
#define SIZE_1M    0x00100000
#define PAGE_TABLE_SIZE  0x00004000 /* 4KB */

/*
 * �ڡ����ơ��֥�
 */
static uint8_t PageTable[PAGE_TABLE_SIZE]  __attribute__ ((aligned (0x4000)));

/*
 * ����˽���,����Υޥåԥ󥰤�Ԥ�
 * �ޥåԥ󥰤�ñ�̤�1MB 
 */
void
mmu_map_memory(MEMORY_ATTRIBUTE *m_attribute)
{
	uint32_t size;
	uintptr_t va;
	uintptr_t pa;
	uint32_t ttb;
	uint32_t *sptr;
	uint32_t fix_val;
	
	size = m_attribute->size;
	va   = m_attribute->va;
	pa   = m_attribute->pa;

	/* MBñ�̤ˤʤ�褦�˥����������� */
	size = (size + 0x000FFFFF) & ~0x000FFFFF;

	/*
	 * �ڡ����ơ��֥�Υ١������ɥ쥹�����
	 */
	CP15_TTB0_READ(ttb);

	fix_val =  (m_attribute->s << 16) | (m_attribute->tex << 12) | (m_attribute->ap << 10)
		        | (m_attribute->c << 3) | (m_attribute->b << 2) | (1 << 1);
#if __TARGET_ARCH_ARM == 7
	fix_val |= (m_attribute->ns << 19);
#endif /* __TARGET_ARCH_ARM == 7 */
	sptr  = (uint32_t *)((ttb & 0xFFFFC000) | (((va & 0xFFF00000) >> 20) << 2));

	while(size > 0) {
		*sptr = pa | fix_val;

		sptr++;
		va   += SIZE_1M;
		pa   += SIZE_1M;
		size -= SIZE_1M;
	}
}

/*
 *  MMU�ν����
 */
void
mmu_init(void)
{
	uint32_t bits = 0;

	/* �ץ�ե��å��Хåե��򥯥ꥢ */
	pbuffer_flash();

	/* TTBR0���Ѥ���褦�˻��� */
	CP15_TTBCR_WRITE(0);

	/*
	 * �Ѵ��ơ��֥�(TT)�Ȥ��ơ�PageTable����Ѥ���
	 * Shared�ӥåȤ򥻥å�
	 */
#if __TARGET_ARCH_ARM == 6
	CP15_TTB0_WRITE((((uintptr_t)PageTable)|CP15_TTB0_RGN_S|CP15_TTB0_RGN_WBWA));
#else /* __TARGET_ARCH_ARM == 7 */
	CP15_TTB0_WRITE((((uintptr_t)PageTable)|CP15_TTB0_RGN_S|CP15_TTB0_RGN_WBWA|CP15_TTB0_IRGN_WBWA));
#endif /* __TARGET_ARCH_ARM == 7 */

	/* �ץ�ե��å��Хåե��򥯥ꥢ */
	pbuffer_flash();

	/*
	 *  �������åȰ�¸���Ǥ�MMU�ν����
	 */
	target_mmu_init();

	/*
	 * �ɥᥤ���ֹ�򥻥å�
	 */
	CP15_DOMAINS_WRITE(DOMAIN_NO);

	/*
	 *  CONTROL���ץ��å��� M�ӥåȡ�XP�ӥåȤ򥻥åȤ��ơ�
	 *  MMU��ͭ���ˤ���
	 */
	CP15_CONTROL_READ(bits);
	bits |= CP15_CONTROL_M_BIT | CP15_CONTROL_XP_BIT;
	CP15_CONTROL_WRITE(bits);
}
#endif /* (__TARGET_ARCH_ARM == 6) || (__TARGET_ARCH_ARM == 7) */
