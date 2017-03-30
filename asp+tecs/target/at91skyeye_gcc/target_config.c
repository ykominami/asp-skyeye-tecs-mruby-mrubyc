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
 *  @(#) $Id: target_config.c 951 2008-04-14 08:51:11Z ertl-honda $
 */

/*
 * ���åװ�¸�⥸�塼���AT91SKYEYE�ѡ�
 */

#include "kernel_impl.h"
#include <sil.h>
#include "target_serial.h"
#include <stdlib.h>

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
uint32_t bitpat_cfgint;

/*
 *  �������åȰ�¸�ν����
 */
void
target_initialize(void)
{
	/*
	 *  ARM��¸�ν����
	 */
	core_initialize();
    
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
	at91skyeye_disable_int(~0U);

	/*
	 * ���٤Ƥγ���ߤ����
	 */
	at91skyeye_clear_int(~0U);

	/*
	 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ����������롥
	 */
	bitpat_cfgint = 0U;
    
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
	at91skyeye_disable_int(~0U);

	/*
	 *  ��ȯ�Ķ���¸�ν�λ����
	 */
	at91skyeye_exit();

	exit(0);
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

extern void software_init_hook(void);

/*
 *  ����ѥ���Υ������ȥ��åץ롼���󤫤�ƤӽФ���롥
 *  sta_ker()��ƤӽФ��ƥ����ͥ�򥹥����Ȥ����롥 
 */
int
main(void)
{
	/*
	 *  software_init_hook ��ƽФ���0 �Ǥʤ�����
	 *
	 *  ���եȥ������Ķ����ä˥饤�֥��ˤ˰�¸����ɬ�פʽ������
	 *  ����������ϡ�software_init_hook �Ȥ����ؿ����Ѱդ����
	 *  �褤��
	 */
	if(software_init_hook != NULL) {
		software_init_hook();
	}
	sta_ker();
	return 1;
}
