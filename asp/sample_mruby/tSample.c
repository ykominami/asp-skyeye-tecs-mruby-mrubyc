/*
 *  mruby on SkyEye
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2009 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2012 by Ubiquitous Computing and Networking Laboratory
 *                Ritsumeikan Univ., JAPAN
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
 *  @(#) $Id: tSample.c 283 2009-05-08 06:52:59Z ertl-takuya $
 */

/* 
 *  ����ץ�ץ����(1)������
 *
 * �ƤӸ��ؿ� #_TCPF_#
 * require port : signature: sKernel context: task
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delay_time );
 *   ER             rotateReadyQueue( PRI priority );
 *   ER             exitTask( );
 *   ER             getTaskId( ID* p_task_id );
 *   ER             getTime( SYSTIM* p_system_time );
 *   ER             getMicroTime( SYSUTM* p_system_micro_time );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   ER             disableTaskException( );
 *   ER             enableTaskException( );
 *   ER             changeInterruptPriorityMask( PRI interrupt_priority );
 *   ER             getInterruptPriorityMask( PRI* p_interrupt_priority );
 *   ER             exitKernel( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 * require port : signature: siKernel context: non-task
 *   ER             ciKernel_rotateReadyQueue( PRI priority );
 *   ER             ciKernel_getTaskId( ID* p_task_id );
 *   ER             ciKernel_getMicroTime( SYSUTM* p_system_micro_time );
 *   ER             ciKernel_lockCpu( );
 *   ER             ciKernel_unlockCpu( );
 *   ER             ciKernel_exitKernel( );
 *   bool_t         ciKernel_senseContext( );
 *   bool_t         ciKernel_senseLock( );
 *   bool_t         ciKernel_senseDispatch( );
 *   bool_t         ciKernel_senseDispatchPendingState( );
 *   bool_t         ciKernel_senseKernel( );
 *   bool_t         ciKernel_senseDispatchPendingStateCPU( const void* p_exception_infomation );
 *   bool_t         ciKernel_senseTaskExceptionPendingStateCPU( const void* p_exception_infomation );
 * call port : cSerialPort  signature: sSerialPort context: task
 *   ER             cSerialPort_open( );
 *   ER             cSerialPort_close( );
 *   ER_UINT        cSerialPort_read( char_t* buf, uint_t len );
 *   ER_UINT        cSerialPort_write( const char_t* buf, uint_t len );
 *   ER             cSerialPort_control( uint_t ioctl );
 *   ER             cSerialPort_refer( T_SERIAL_RPOR* pk_rpor );
 * call port : cSysLog  signature: sSysLog context: task
 *   ER             cSysLog_write( uint_t prio, const SYSLOG* p_syslog );
 *   ER_UINT        cSysLog_read( SYSLOG* p_syslog );
 *   ER             cSysLog_mask( uint_t logmask, uint_t lowmask );
 *   ER             cSysLog_refer( T_SYSLOG_RLOG* pk_rlog );
 *
 * #[</PREAMBLE>]# */ 

#include "tSample_tecsgen.h"
#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "kernel_cfg.h"
#include "tSample.h"

/*
 *  �����ӥ�������Υ��顼�Υ�����
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define	SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))

/*
 *  �ᥤ�󥿥���
 */
/* °�������� *//* #[<ENTRY_FUNC>]# eMainTask_main
 * name:         eMainTask_main
 * global_name:  tSample_eMainTask_main
 * oneway:       
 * #[/ENTRY_FUNC>]# */
void
eMainTask_main()
{
	ER_UINT	ercd;	

	SVC_PERROR(cSysLog_mask(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Sample program starts.");
	/*
	 *  ���ꥢ��ݡ��Ȥν����
	 *
	 *  �����ƥ����������Ʊ�����ꥢ��ݡ��Ȥ�Ȥ����ʤɡ����ꥢ��
	 *  �ݡ��Ȥ������ץ�Ѥߤξ��ˤϤ�����E_OBJ���顼�ˤʤ뤬���پ��
	 *  �ʤ���
	 */
	ercd = cSerialPort_open();
	if (ercd < 0 && MERCD(ercd) != E_OBJ) {
		syslog(LOG_ERROR, "%s (%d) reported by `cSerialPort_open'.",
									itron_strerror(ercd), SERCD(ercd));
	}
	SVC_PERROR(cSerialPort_control(IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV));

/*    cMrubyBody_main();
	syslog(LOG_NOTICE, "Sample program ends.");
	SVC_PERROR(ciKernel_exitKernel());
	assert(0);*/
}
