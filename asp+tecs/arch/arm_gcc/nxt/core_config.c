/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2007 by Embedded and Real-Time Systems Laboratory
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
 *        ������¸�⥸�塼���ARM�ѡ�
 */
#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  ����ƥ����Ȼ��ȤΤ�����ѿ�
 */
uint32_t excpt_nest_count;

#ifndef VECTOR_KERNEL
/*
 *  �㳰�٥����˽񤭹��ޤ줿������̿�᤬���Ȥ��륢�ɥ쥹
 * 
 */
uint32_t *arm_vector_ref_tbl_add[8];

/*
 * �㳰�˱������ϥ�ɥ�ε�ư����
 */
uint32_t arm_saved_exch_add[8];
#endif /* VECTOR_KERNEL */

/*
 *  �ץ��å���¸�ν����
 */
void
core_initialize()
{
    /*
     *  �����ͥ뵯ư�����󥿥�������ƥ����ȤȤ���ư����뤿��1��
     */ 
    excpt_nest_count = 1;
    
#ifndef VECTOR_KERNEL    
    {
        uint32_t i, vector_value;

        /*
         * �㳰�٥�������Ͽ����Ƥ���̿�ᤫ�黲�Ȥ���륢�ɥ쥹�ȡ�
         * ���Υ��ɥ쥹������(�ϥ�ɥ������)����¸���롥
         */
        for(i = 0; i < TNUM_EXCH; i++){
            vector_value = *(volatile uint32_t *)(VECTOR_START + (i*4));
            vector_value &= 0x00000fff;
            arm_vector_ref_tbl_add[i]  =  (uint32_t *)(vector_value + 8) + i;
            arm_saved_exch_add[i] = *(arm_vector_ref_tbl_add[i]);
        }
    }
#endif /* VECTOR_KERNEL */    
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
core_terminate(void)
{
#ifndef VECTOR_KERNEL
    uint32_t i;
    
    /*
     * �㳰�٥����򸵤��᤹
     */
    for(i = 0; i < TNUM_EXCH; i++){
        *arm_vector_ref_tbl_add[i]  = arm_saved_exch_add[i];
    }    
#endif /* VECTOR_KERNEL */   
}

/*
 *  CPU�㳰��ȯ�������Υ�����
 *
 *  CPU�㳰�ϥ�ɥ���椫�顤CPU�㳰����ݥ��󥿡�p_excinf�ˤ�����Ȥ�
 *  �ƸƤӽФ����Ȥǡ�CPU�㳰��ȯ�������򥷥��ƥ���˽��Ϥ��롥
 */
#ifdef SUPPORT_XLOG_SYS

void
xlog_sys(void *p_excinf)
{    
}

#endif /* SUPPORT_XLOG_SYS */

/*
 *  �㳰�٥�������ľ�ܼ¹Ԥ���ϥ�ɥ����Ͽ
 */ 
void
x_install_exc(EXCNO excno, FP exchdr)
{
#ifdef VECTOR_KERNEL
    *(((FP*)vector_ref_tbl) + excno) = exchdr;
#else
    *arm_vector_ref_tbl_add[excno] = (uint32_t)exchdr;
#endif /* VECTOR_KERNEL */    
}

#ifndef OMIT_DEFAULT_EXC_HANDLER
/*
 * ̤������㳰�����ä����ν���
 */
void
default_exc_handler(void){
    syslog_0(LOG_EMERG, "Unregistered Exception occurs.");
	while(1); /* TEST */
    ext_ker();
}
#endif /* OMIT_DEFAULT_EXC_HANDLER */
