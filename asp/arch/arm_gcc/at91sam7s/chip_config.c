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
 *  @(#) $Id: chip_config.c 1635 2009-09-16 01:17:30Z ertl-honda $
 */

/*
 * ���åװ�¸�⥸�塼���AT91SAM7S�ѡ�
 */

#include "kernel_impl.h"
#include <sil.h>

/*
 * �Ƴ���ߤγ�����׵�ػߥե饰�ξ���
 */
uint32_t idf;

/*
 * ���ߤγ����ͥ���٥ޥ�������
 */
PRI ipm;
 
/*
 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ�
 */
uint32_t	bitpat_cfgint;

/*
 *  �������åȰ�¸�ν����
 */
void
target_initialize(void)
{
    int i;
    
    /*
     *  ARM��¸�ν����
     */
    core_initialize();


    /*
     * ��������ϻ��˳�����װ���Ƚ�ꤹ�뤿��SVR�˳�����ֹ�򥻥åȤ���
     */
    /*
     * ������߶ػ�
     */
    sil_wrw_mem((void*)(TADR_AIC_BASE+TOFF_AIC_ICCR), ~0U);

    /*
     * EOICR�򥻥å�
     */
    sil_wrw_mem((void*)(TADR_AIC_BASE+TOFF_AIC_EOICR), 0U);
    
    
    for(i = 0; i < TNUM_INT; i++){
        sil_wrw_mem((void*)(TADR_AIC_BASE+TOFF_AIC_SVR+(i*4)), (uint32_t)i);
    }
    
    /*
     * �Ƴ���ߤγ�����׵�ػߥե饰���ػ�
     */
    idf = ~0U;

    /*
     * �����ͥ���٥ޥ�����0
     */ 
    ipm = 0U;

    /*
     * ���Ƥγ���ߤ�ޥ���
     */ 
    at91sam7s_disable_int(~0U);

    /*
     *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ����������롥
     */
    bitpat_cfgint = 0U;
    
#ifndef VECTOR_KERNEL    
    /*
     *  �㳰�٥����ơ��֥�س���ߥϥ�ɥ����Ͽ
     */
    x_install_exc(EXCH_NO_IRQ, interrupt_handler);
    x_install_exc(EXCH_NO_UNDEF, undef_handler);
    x_install_exc(EXCH_NO_SWI, swi_handler);
    x_install_exc(EXCH_NO_PABORT, prefetch_handler);
    x_install_exc(EXCH_NO_DABORT, data_abort_handler);
    x_install_exc(EXCH_NO_FIQ, fiq_handler);
#endif /* VECTOR_KERNEL */
     
    /*
     *  target_fput_log ����ǽ�ˤʤ�褦��UART������
     */
    at91sam7s_init_uart();    
}

/*
 *  �������åȰ�¸�ν�λ����
 */
void
target_exit(void)
{
    extern void    software_term_hook(void);
    void (*volatile fp)(void) = software_term_hook;

   /*
     *  software_term_hook�ؤΥݥ��󥿤򡤰�övolatile����Τ���fp����
     *  �����Ƥ���Ȥ��Τϡ�0�Ȥ���Ӥ���Ŭ���Ǻ������ʤ��褦�ˤ��뤿
     *  ��Ǥ��롥
     */
    if (fp != 0) {
        (*fp)();
    }

    /*
     *  ARM��¸�ν�λ����
     */
    core_terminate();

    /*
     *  ���٤Ƥγ���ߤ�ޥ������롥
     */
    at91sam7s_disable_int(~0U);

    /*
     *  ��ȯ�Ķ���¸�ν�λ����
     */
    at91sam7s_exit();

    while(1);
}

/*
 *  �������åȰ�¸��ʸ������
 */
void
target_fput_log(char_t c)
{
    if (c == '\n') {
        at91sam7s_putc('\r');
    }
    at91sam7s_putc(c);
}

/*
 *  ������׵�饤���°��������
 *
 *  ASP�����ͥ�Ǥ����Ѥ����ꤷ�ơ��ѥ�᡼�����顼�ϥ����������ǥ�����
 *  �����Ƥ��롥FI4�����ͥ�����Ѥ�����ˤϡ����顼���֤��褦�ˤ��٤�
 *  �Ǥ�����
 *
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
    assert(VALID_INTNO(intno));
    assert(TMIN_INTPRI <= intpri && intpri <= TMAX_INTPRI);

	/*
	 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ�������
	 */
	bitpat_cfgint |= INTNO_BITPAT(intno);
    
    /* 
     * ���ä������ߤ�ػߤ���
     */    
    x_disable_int(intno);

    /*
     * ��٥�ȥꥬ/���å��ȥꥬ������
     * IRQ�Τߥ��ݡ��Ȥ���
     */
    uint32_t smr_val;

    if((intatr & TA_POSEDGE) != 0U) {
        /*
         * �ݥ��ƥ��֥��å�
         */
        smr_val = AIC_SRCTYPE_EXT_POSITIVE_EDGE;
    }else if((intatr & TA_HIGHLEVEL) != 0U) {
        /*
         * �ϥ���٥�ȥꥬ
         */
        smr_val = AIC_SRCTYPE_EXT_HIGH_LEVEL ;
    }else if((intatr & TA_EDGE) != 0U) {
        /*
         * ���å��ȥꥬ
         */
        smr_val = AIC_SRCTYPE_INT_EDGE_TRIGGERED;
    }else{
        /*
         * ��٥�ȥꥬ
         */
        smr_val = AIC_SRCTYPE_INT_LEVEL_SENSITIVE;
    }
    
    sil_wrw_mem((void*)(TADR_AIC_BASE+TOFF_AIC_SMR+intno*4U), smr_val|INT_IPM(intpri));
    
    if ((intatr & TA_ENAINT) != 0U){
        (void)x_enable_int(intno);
    }    
}

#ifndef OMIT_DEFAULT_INT_HANDLER
/*
 * ̤����γ���ߤ����ä����ν���
 */
void
default_int_handler(void){
    syslog_0(LOG_EMERG, "Unregistered Interrupt occurs.");
    target_exit();
}
#endif /* OMIT_DEFAULT_INT_HANDLER */
