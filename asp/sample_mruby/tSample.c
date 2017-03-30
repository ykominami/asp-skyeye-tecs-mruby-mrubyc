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
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: tSample.c 283 2009-05-08 06:52:59Z ertl-takuya $
 */

/* 
 *  サンプルプログラム(1)の本体
 *
 * 呼び口関数 #_TCPF_#
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
 *  サービスコールのエラーのログ出力
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
 *  メインタスク
 */
/* 属性の設定 *//* #[<ENTRY_FUNC>]# eMainTask_main
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
	 *  シリアルポートの初期化
	 *
	 *  システムログタスクと同じシリアルポートを使う場合など，シリアル
	 *  ポートがオープン済みの場合にはここでE_OBJエラーになるが，支障は
	 *  ない．
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
