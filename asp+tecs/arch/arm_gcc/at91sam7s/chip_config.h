/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2007-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: chip_config.h 1635 2009-09-16 01:17:30Z ertl-honda $
 */

/*
 *  ���åװ�¸�⥸�塼���AT91SAM7S�ѡ�
 *
 *  �����ͥ�Υ��åװ�¸���Υ��󥯥롼�ɥե����롥kernel_impl.h�Υ���
 *  ���åȰ�¸���ΰ����դ��Ȥʤ롥
 */

#ifndef TOPPERS_CHIP_CONFIG_H
#define TOPPERS_CHIP_CONFIG_H

/*
 *  ���åץ����ƥ�Υϡ��ɥ������񸻤����
 */
#include "at91sam7s.h"

/*
 *  �٥������롼����򥫡��ͥ�ǻ��Ĥ������
 */
#define VECTOR_KERNEL

/*
 *  �٥������롼���������ʤ����Υ٥��������ɥ쥹����Ƭ����
 */ 
#define VECTOR_START  0x00

/*
 * ������Ԥ�̿��
 */
#define ASM_TARGET_WAIT_INTERRUPT nop

/*
 *  ASP�����ͥ�ư����Υ���ޥåפȴ�Ϣ�������
 */
#define RAM_START       SRAM_BASE_ADDRESSS
#define RAM_SIZE        SRAM_SIZE

#define FIQ_DATA_SIZE   256U

/*
 *  �ǥե���Ȥ��󥿥�������ƥ������ѤΥ����å��ΰ�����
 */
#define DEFAULT_ISTKSZ      0x1000U   /* 4KB */
#define DEFAULT_ISTK        (void *)(RAM_START+RAM_SIZE-FIQ_DATA_SIZE - DEFAULT_ISTKSZ)

                                                   
/*
 *  ���������Ԥ��Τ��������������SIL�Υ������åȰ�¸����
 */
#define SIL_DLY_TIM1    420
#define SIL_DLY_TIM2    195

/*
 *  ����ߥϥ�ɥ��ֹ�˴ؤ������
 */ 
#define TMIN_INHNO 0U
#define TMAX_INHNO 31U
#define TNUM_INH   32U

/*
 *  ������ֹ�˴ؤ������
 */ 
#define TMIN_INTNO 0U
#define TMAX_INTNO 31U
#define TNUM_INT   32U

#ifndef TOPPERS_MACRO_ONLY

/*
 *  ������ֹ���ϰϤ�Ƚ��
 *
 *  �ӥåȥѥ���������Τ��ưפˤ��뤿��ˡ�8�Ϸ��֤ˤʤäƤ��롥
 */
#define VALID_INTNO(intno) (TMIN_INTNO <= (intno) && (intno) <= TMAX_INTNO)
#define VALID_INTNO_DISINT(intno)	VALID_INTNO(intno)
#define VALID_INTNO_CFGINT(intno)	VALID_INTNO(intno)
#define VALID_INTNO_ATTISR(intno)   VALID_INTNO(intno)

/*
 *  ����ߥϥ�ɥ����Ͽ�ѥơ��֥�
 *   ���֤ϥ���ե�����졼������������ 
 */
extern const FP inh_tbl[TNUM_INH];

/*
 *  ����ߥϥ�ɥ������
 */
Inline void
x_define_inh(INHNO inhno, FP int_entry)
{
}

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 */
#define INT_ENTRY(inhno, inthdr)    inthdr
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) extern void inthdr(void);

/*
 *  TOPPERSɸ�����߽�����ǥ�μ¸�
 */

/*
 *  �����ͥ���٥ޥ����γ���ɽ��������ɽ�����Ѵ�
 *
 *  ������֥����Υ������ե����뤫�饤�󥯥롼�ɤ�����Τ���ˡ���
 *  ���㥹�Ȥ��ʤ�������Ѱդ��Ƥ��롥
 */
#ifndef TOPPERS_MACRO_ONLY
#define EXT_IPM(iipm)    ((PRI)(-iipm))     /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)     ((uint8_t)(-ipm))  /* ����ɽ��������ɽ���� */
#else /* TOPPERS_MACRO_ONLY */
#define EXT_IPM(iipm)    (-iipm)            /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)     (-ipm)             /* ����ɽ��������ɽ���� */
#endif /* TOPPERS_MACRO_ONLY */

/*
 * �Ƴ���ߤγ�����׵�ػߥե饰�ξ���
 */
extern uint32_t idf;

/*
 *  �����ͥ���٥ޥ������饤�֥��
 *
 *  AT91SAM7S�ϳ����ͥ���٥ޥ�����IRC��ǥϡ��ɥ�����Ū�˻��Ĥ���
 *  ���եȥ�����¦�����ͤ��ɤ߽񤭤Ǥ��ʤ����ᡤ������׵�ػߥե�
 *  ���ˤ������ͥ���٥ޥ�����¸�����
 */

/*
 *  ���ߤγ����ͥ���٥ޥ�������
 */
extern PRI ipm;

/*
 *  �����ͥ���٥ޥ�����˥��åȤ��롤������׵�ػߥե饰����
 *  �Υơ��֥�
 */
extern const uint32_t ipm_mask_tbl[8];

#endif /* TOPPERS_MACRO_ONLY */  

/*
 *  IPM��imp_mask_tbl�Υ���ǥå������Ѵ�����ޥ���
 */
#define INDEX_IPM(ipm)  (-(ipm))

#ifndef TOPPERS_MACRO_ONLY

/*
 *  (��ǥ���)�����ͥ���٥ޥ���������
 * 
 *  ���ꤵ�줿ͥ���٤����ꤵ�줿������׵�ػߥե饰�Υơ��֥���ͤȡʥ��
 *  ���Ρ˳Ƴ���ߤγ�����׵�ػߥե饰�ξ��֤��ݻ������ѿ����ͤȤ�
 *  OR��IRC�γ�����׵�ػߥե饰�˥��åȤ������ꤷ��ͥ���٤������ѿ�
 *  ipm����¸���롥
 */
Inline void
x_set_ipm(PRI intpri)
{
    uint32_t ipm_mask = ipm_mask_tbl[INDEX_IPM(intpri)];

    /*
     *  AT91SAM7S�γ���ߥ���ȥ���ϥ��͡��֥�쥸������
     *  ���ꥢ���쥸���������뤿�ᡤ��ö���Ƥγ���ߤ�ػߤ��Ƥ��顤
     *  ����γ���ߤΤߵ��Ĥ���ɬ�פ�����
     */
    /* ������߶ػ� */
    at91sam7s_disable_int(~0U);

    /* �ޥ������ꤵ��Ƥ��ʤ�����ߤΤߵ��� */
    at91sam7s_enable_int(~(ipm_mask|idf));

    ipm = intpri;
}

#define t_set_ipm(intpri) x_set_ipm(intpri)
#define i_set_ipm(intpri) x_set_ipm(intpri)

/*
 *  (��ǥ���)�����ͥ���٥ޥ����λ���
 *
 *  ipm���ͤ��֤�
 */
Inline PRI
x_get_ipm(void)
{
    return(ipm);
}

#define t_get_ipm() x_get_ipm()
#define i_get_ipm() x_get_ipm()

/*
 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ�
 */
extern uint32_t	bitpat_cfgint;

/*
 * �ʥ�ǥ��Ρ˳�����׵�ػߥե饰�Υ��å�
 *
 *  ���ꤵ�줿��������ֹ�γ�����׵�ػߥե饰�Υ��åȤ��ơ�����ߤ�
 *  �ػߤ��롥�ޤ����ʥ�ǥ��Ρ˳�����׵�ػߥե饰���������idf����
 *  ������ӥåȤ�򥻥åȤ��롥
 *  ������׵��ޥ������뵡ǽ�򥵥ݡ��Ȥ��Ƥ��ʤ����ˤϡ�false���֤�
 */
Inline bool_t
x_disable_int(INTNO intno)
{
    if ((bitpat_cfgint & INTNO_BITPAT(intno)) == 0U) {
        return(false);
    }
    at91sam7s_disable_int(INTNO_BITPAT(intno));
    idf |= INTNO_BITPAT(intno);
    return(true);
}

#define t_disable_int(intno)  x_disable_int(intno)
#define i_disable_int(intno)  t_disable_int(intno)

/* 
 * (��ǥ���)����׵�ػߥե饰�β��
 *
 * ���ꤵ�줿��������ֹ�γ�����׵�ػߥե饰�Υ��ꥢ���ơ�����ߤ�
 * ���Ĥ��롥�ޤ����ʥ�ǥ��Ρ˳�����׵�ػߥե饰���������idf����
 * ������ӥåȤ�򥯥ꥢ���롥
 * ������׵��ޥ������뵡ǽ�򥵥ݡ��Ȥ��Ƥ��ʤ����ˤϡ�false���֤�
 */
Inline bool_t
x_enable_int(INTNO intno)
{
    if ((bitpat_cfgint & INTNO_BITPAT(intno)) == 0U) {
        return(false);
    }    
    at91sam7s_enable_int(INTNO_BITPAT(intno));
    idf &= ~INTNO_BITPAT(intno);
    return(true);
}

#define t_enable_int(intno) x_enable_int(intno)
#define i_enable_int(intno) x_enable_int(intno)

/*
 * ������׵�Υ��ꥢ
 */
Inline void
x_clear_int(INTNO intno)
{
    at91sam7s_clear_int(INTNO_BITPAT(intno));
}

#define t_clear_int(intno) x_clear_int(intno) 
#define i_clear_int(intno) x_clear_int(intno) 


/*
 *  ������׵�Υ����å�
 */
Inline bool_t
x_probe_int(INTNO intno)
{
    return(at91sam7s_probe_int(INTNO_BITPAT(intno)));
}

#define t_probe_int(intno) x_probe_int(intno)
#define i_probe_int(intno) x_probe_int(intno)

/*
 *  ������׵�饤���°��������
 *
 */
extern void    x_config_int(INTNO intno, ATR intatr, PRI intpri);

/*
 *  ����ߥϥ�ɥ���������ɬ�פ�IRC���
 *
 *  AT91SAM7S�Ǥϡ�ɬ�פʽ����Ϥʤ�
 */
Inline void
i_begin_int(INTNO intno)
{
    
}

/*
 *  ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 *
 *  AT91SAM7S�Ǥϡ�ɬ�פʽ����Ϥʤ�
 */
Inline void
i_end_int(INTNO intno)
{
    
}

/*
 *  �������åȥ����ƥ��¸�ν����
 */
extern void target_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���
 */
extern void target_exit(void) NoReturn;

/*
 *  ����ߥϥ�ɥ��chip_support.S��
 */
extern void interrupt_handler(void);

/*
 *  ̤����γ���ߤ����ä����ν���
 */
extern void default_int_handler(void);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ������¸�⥸�塼���ARM�ѡ�
 */
#include "arm_gcc/common/core_config.h"

#endif /* TOPPERS_CHIP_CONFIG_H */
