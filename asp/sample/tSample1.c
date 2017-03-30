/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: tSample1.c 300 2009-05-08 12:20:30Z ertl-takuya $
 */

/* 
 *  ����ץ�ץ����(1)������
 *
 *  ASP�����ͥ�δ���Ū��ư����ǧ���뤿��Υ���ץ�ץ���ࡥ
 *
 *  �ץ����γ���:
 *
 *  �桼�����󥿥ե�������������ĥᥤ�󥿥����ʥ�����ID: MAIN_TASK��ͥ
 *  ����: MAIN_PRIORITY�ˤȡ�3�Ĥ�����¹Ԥ���륿�����ʥ�����ID:
 *  TASK1��TASK3�����ͥ����: MID_PRIORITY�ˤǹ�������롥�ޤ�����ư��
 *  ����2�äμ����ϥ�ɥ�ʼ����ϥ�ɥ�ID: CYCHDR1�ˤ��Ѥ��롥
 *
 *  ����¹Ԥ���륿�����ϡ�task_loop����롼�פ�¹Ԥ����٤ˡ���������
 *  �¹���Ǥ��뤳�Ȥ򤢤�魯��å�������ɽ�����롥
 *
 *  �����ϥ�ɥ�ϡ����Ĥ�ͥ���١�HIGH_PRIORITY��MID_PRIORITY��
 *  LOW_PRIORITY�ˤΥ�ǥ����塼���ž�����롥�ץ����ε�ưľ��ϡ�
 *  �����ϥ�ɥ����߾��֤ˤʤäƤ��롥
 *
 *  �ᥤ�󥿥����ϡ����ꥢ��I/O�ݡ��Ȥ����ʸ�����Ϥ�Ԥ���ʸ�����Ϥ�
 *  �ԤäƤ���֤ϡ�����¹Ԥ���륿�������¹Ԥ���Ƥ���ˡ����Ϥ��줿
 *  ʸ�����б�����������¹Ԥ��롥���Ϥ��줿ʸ���Ƚ����δط��ϼ����̤ꡥ
 *  Control-C�ޤ���'Q'�����Ϥ����ȡ��ץ�����λ���롥
 *
 *  '1' : �оݥ�������TASK1���ڤ괹����ʽ������ˡ�
 *  '2' : �оݥ�������TASK2���ڤ괹���롥
 *  '3' : �оݥ�������TASK3���ڤ괹���롥
 *  'a' : �оݥ�������cTask_activate�ˤ�굯ư���롥
 *  'A' : �оݥ��������Ф��뵯ư�׵��cTask_cancelActivate�ˤ�ꥭ��󥻥뤹�롥
 *  'e' : �оݥ�������exitTask��ƤӽФ�������λ�����롥
 *  't' : �оݥ�������cTask_terminate�ˤ�궯����λ���롥
 *  '>' : �оݥ�������ͥ���٤�HIGH_PRIORITY�ˤ��롥
 *  '=' : �оݥ�������ͥ���٤�MID_PRIORITY�ˤ��롥
 *  '<' : �оݥ�������ͥ���٤�LOW_PRIORITY�ˤ��롥
 *  'G' : �оݥ�������ͥ���٤�cTask_getPriority���ɤ߽Ф���
 *  's' : �оݥ�������sleep��ƤӽФ����������Ԥ��ˤ����롥
 *  'S' : �оݥ�������sleepTimeout10��)��ƤӽФ����������Ԥ��ˤ����롥
 *  'w' : �оݥ�������cTask_wakeup�ˤ�굯�����롥
 *  'W' : �оݥ��������Ф��뵯���׵��cTask_cancelWakeup�ˤ�ꥭ��󥻥뤹�롥
 *  'l' : �оݥ�������cTask_releaseWait�ˤ�궯��Ū���Ԥ�����ˤ��롥
 *  'u' : �оݥ�������cTask_suspend�ˤ�궯���Ԥ����֤ˤ��롥
 *  'm' : �оݥ������ζ����Ԥ����֤�cTask_resume�ˤ�������롥
 *  'd' : �оݥ�������delay(10��)��ƤӽФ��������ַв��Ԥ��ˤ����롥
 *  'x' : �оݥ��������㳰�ѥ�����0x0001���㳰�������׵᤹�롥
 *  'X' : �оݥ��������㳰�ѥ�����0x0002���㳰�������׵᤹�롥
 *  'y' : �оݥ�������disableTaskException��ƤӽФ������������㳰��ػߤ��롥
 *  'Y' : �оݥ�������enableTaskException��ƤӽФ������������㳰����Ĥ��롥
 *  'r' : 3�Ĥ�ͥ���١�HIGH_PRIORITY��MID_PRIORITY��LOW_PRIORITY�ˤΥ�
 *        �ǥ����塼���ž�����롥
 *  'c' : �����ϥ�ɥ��ư��Ϥ����롥
 *  'C' : �����ϥ�ɥ��ư����ߤ����롥
 *  'b' : ���顼��ϥ�ɥ��5�ø�˵�ư����褦ư��Ϥ����롥
 *  'B' : ���顼��ϥ�ɥ��ư����ߤ����롥
 *  'z' : �оݥ�������CPU�㳰��ȯ��������ʥ�������λ������ˡ�
 *  'Z' : �оݥ�������CPU��å����֤�CPU�㳰��ȯ��������ʥץ�����
 *        ��λ����ˡ�
 *  'V' : getMicroTime����ǽɾ���ѥ����ƥ�����2���ɤࡥ
 *  'v' : ȯ�Ԥ��������ƥॳ�����ɽ������ʥǥե���ȡˡ�
 *  'q' : ȯ�Ԥ��������ƥॳ�����ɽ�����ʤ���
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
 * call port : cTask  signature: sTask context: task
 *   ER             cTask_activate( subscript );
 *   ER_UINT        cTask_cancelActivate( subscript );
 *   ER             cTask_terminate( subscript );
 *   ER             cTask_changePriority( subscript, PRI priority );
 *   ER             cTask_getPriority( subscript, PRI* p_priority );
 *   ER             cTask_refer( subscript, T_RTSK* pk_task_status );
 *   ER             cTask_wakeup( subscript );
 *   ER_UINT        cTask_cancelWakeup( subscript );
 *   ER             cTask_releaseWait( subscript );
 *   ER             cTask_suspend( subscript );
 *   ER             cTask_resume( subscript );
 *   ER             cTask_raiseException( subscript, TEXPTN pattern );
 * call port : cCyclic  signature: sCyclic context: task
 *   ER             cCyclic_start( );
 *   ER             cCyclic_stop( );
 *   ER             cCyclic_refer( T_RCYC* pk_cyclic_handler_status );
 * call port : cAlarm  signature: sAlarm context: task
 *   ER             cAlarm_start( RELTIM alarm_time );
 *   ER             cAlarm_stop( );
 *   ER             cAlarm_refer( T_RALM* pk_alarm_status );
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

#include "tSample1_tecsgen.h"
#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "kernel_cfg.h"
#include "tSample1.h"

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
 *  �¹Լ¹Ԥ���륿�����ؤΥ�å������ΰ�
 */
char_t	message[3];

/*
 *  �롼�ײ��
 */
ulong_t	task_loop;		/* ��������ǤΥ롼�ײ�� */
ulong_t	tex_loop;		/* �㳰�����롼������ǤΥ롼�ײ�� */

/*
 *  �¹Լ¹Ԥ���륿����
 */
void eSampleTask_main(int_t subscript)
{
	volatile ulong_t	i;
	int_t		n = 0;
	int_t		tskno = subscript + 1; 
	const char	*graph[] = { "|", "  +", "    *" };
	char_t		c;

	SVC_PERROR(enableTaskException());
	while (1) {
		syslog(LOG_NOTICE, "task%d is running (%03d).   %s",
										tskno, ++n, graph[tskno-1]);
		for (i = 0; i < task_loop; i++);
		c = message[tskno-1];
		message[tskno-1] = 0;
		switch (c) {
		case 'e':
			syslog(LOG_INFO, "#%d#exitTask()", tskno);
			SVC_PERROR(exitTask());
			assert(0);
		case 's':
			syslog(LOG_INFO, "#%d#sleep()", tskno);
			SVC_PERROR(sleep());
			break;
		case 'S':
			syslog(LOG_INFO, "#%d#sleepTimeout(10000)", tskno);
			SVC_PERROR(sleepTimeout(10000));
			break;
		case 'd':
			syslog(LOG_INFO, "#%d#delay(10000)", tskno);
			SVC_PERROR(delay(10000));
			break;
		case 'y':
			syslog(LOG_INFO, "#%d#disableTaskException()", tskno);
			SVC_PERROR(disableTaskException());
			break;
		case 'Y':
			syslog(LOG_INFO, "#%d#enableTaskException()", tskno);
			SVC_PERROR(enableTaskException());
			break;
#ifdef CPUEXC1
		case 'z':
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			break;
		case 'Z':
			SVC_PERROR(lockCpu());
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			SVC_PERROR(unlockCpu());
			break;
#endif /* CPUEXC1 */
		default:
			break;
		}
	}
}

/*
 *  �¹Ԥ��Ƽ¹Ԥ���륿�����ѤΥ������㳰�����롼����
 */
void
eSampleException_main(int_t subscript, TEXPTN pattern)
{
	volatile ulong_t	i;
	int_t	tskno = (int_t) subscript;

	syslog(LOG_NOTICE, "task%d receives exception 0x%04x.", tskno + 1, pattern);
	for (i = 0; i < tex_loop; i++);

	if ((pattern & 0x8000U) != 0U) {
		syslog(LOG_INFO, "#%d#ext_tsk()", tskno);
		SVC_PERROR(exitTask());
		assert(0);
	}
}

/*
 *  CPU�㳰�ϥ�ɥ�
 */
#ifdef CPUEXC1

void
cpuexc_handler(void *p_excinf)
{
	ID		tskid;

	syslog(LOG_NOTICE, "CPU exception handler (p_excinf = %08p).", p_excinf);
	if (ciKernel_senseContext() != true) {
		syslog(LOG_WARNING,
					"ciKernel_senseContext() is not true in CPU exception handler.");
	}
	if (ciKernel_senseDispatchPendingState() != true) {
		syslog(LOG_WARNING,
					"ciKernel_senseDispatchPendingState() is not true in CPU exception handler.");
	}
	syslog(LOG_INFO, "ciKernel_senseLock() = %d ciKernel_senseDispatch() = %d ciKernel_senseContext() = %d",
		   ciKernel_senseLock(), ciKernel_senseDispatch(), ciKernel_senseContext());
	syslog(LOG_INFO, "xsns_dpn = %d xsns_xpn = %d",
		   ciKernel_senseDispatchPendingStateCPU(p_excinf),
		   ciKernel_senseDispatchPendingStateCPU(p_excinf));

	if (xsns_xpn(p_excinf)) {
		syslog(LOG_NOTICE, "Sample program ends with exception.");
		SVC_PERROR(ciKernel_senseKernel());
		assert(0);
	}

	SVC_PERROR(ciKernel_getTaskId(&tskid));
	SVC_PERROR(iras_tex(tskid, 0x8000U));
	
}

#endif /* CPUEXC1 */

/*
 *  �����ϥ�ɥ�
 *
 *  HIGH_PRIORITY��MID_PRIORITY��LOW_PRIORITY �γ�ͥ���٤Υ�ǥ����塼
 *  ���ž�����롥
 */
/* #[<ENTRY_FUNC>]# eiCyclicHandler_main
 * name:         eiCyclicHandler_main
 * global_name:  tSample1_eiCyclicHandler_main
 * oneway:       
 * #[/ENTRY_FUNC>]# */
void
eiCyclicHandler_main()
{
	SVC_PERROR(ciKernel_rotateReadyQueue(HIGH_PRIORITY));
	SVC_PERROR(ciKernel_rotateReadyQueue(MID_PRIORITY));
	SVC_PERROR(ciKernel_rotateReadyQueue(LOW_PRIORITY));
}

/*
 *  ���顼��ϥ�ɥ�
 *
 *  HIGH_PRIORITY��MID_PRIORITY��LOW_PRIORITY �γ�ͥ���٤Υ�ǥ����塼
 *  ���ž�����롥
 */
/* #[<ENTRY_FUNC>]# eiAlarmHandler_main
 * name:         eiAlarmHandler_main
 * global_name:  tSample1_eiAlarmHandler_main
 * oneway:       
 * #[/ENTRY_FUNC>]# */
void
eiAlarmHandler_main()
{
	SVC_PERROR(ciKernel_rotateReadyQueue(HIGH_PRIORITY));
	SVC_PERROR(ciKernel_rotateReadyQueue(MID_PRIORITY));
	SVC_PERROR(ciKernel_rotateReadyQueue(LOW_PRIORITY));
}
/*
 *  �ᥤ�󥿥���
 */
/* °�������� *//* #[<ENTRY_FUNC>]# eMainTask_main
 * name:         eMainTask_main
 * global_name:  tSample1_eMainTask_main
 * oneway:       
 * #[/ENTRY_FUNC>]# */
void
eMainTask_main()
{
	char_t	c;
	volatile ulong_t	i;
	int_t	tskno = 1;
	ER_UINT	ercd;	
	PRI		tskpri;
	SYSTIM	stime1, stime2;
#ifdef TOPPERS_SUPPORT_GET_UTM
	SYSUTM	utime1, utime2;
#endif /* TOPPERS_SUPPORT_GET_UTM */

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

	/*
 	 *  �롼�ײ��������
	 *
	 *  TASK_LOOP���ޥ����������Ƥ����硤¬�ꤻ���ˡ�TASK_LOOP����
	 *  �����줿�ͤ򡤥�������ǤΥ롼�ײ���Ȥ��롥
	 *
	 *  MEASURE_TWICE���ޥ����������Ƥ����硤1���ܤ�¬���̤�Τ�
	 *  �ơ�2���ܤ�¬���̤�Ȥ���1���ܤ�¬���Ĺ��λ��֤��Ф뤿�ᡥ
	 */
#ifdef TASK_LOOP
	task_loop = TASK_LOOP;
#else /* TASK_LOOP */

#ifdef MEASURE_TWICE
	task_loop = LOOP_REF;
	SVC_PERROR(getTime(&stime1));
	for (i = 0; i < task_loop; i++);
	SVC_PERROR(getTime(&stime2));
#endif /* MEASURE_TWICE */

	task_loop = LOOP_REF;
	SVC_PERROR(getTime(&stime1));
	for (i = 0; i < task_loop; i++);
	SVC_PERROR(getTime(&stime2));
	task_loop = LOOP_REF * 400UL / (stime2 - stime1);

#endif /* TASK_LOOP */
	tex_loop = task_loop / 5;

	/*
 	 *  �������ε�ư
	 */

	SVC_PERROR(cTask_activate( 1 ));
	SVC_PERROR(cTask_activate( 2 ));
	SVC_PERROR(cTask_activate( 3 ));

	/*
 	 *  �ᥤ��롼��
	 */
	do {
		SVC_PERROR(cSerialPort_read(&c, 1));
		switch (c) {
		case 'e':
		case 's':
		case 'S':
		case 'd':
		case 'y':
		case 'Y':
		case 'z':
		case 'Z':
			message[tskno-1] = c;
			break;
		case '1':
			tskno = 1;
			break;
		case '2':
			tskno = 2;
			break;
		case '3':
			tskno = 3;
			break;
		case 'a':
			syslog(LOG_INFO, "#cTask_activate(%d)", tskno);
			SVC_PERROR(cTask_activate(tskno));
			break;
		case 'A':
			syslog(LOG_INFO, "#cTask_cancelActivate(%d)", tskno);
			SVC_PERROR(cTask_cancelActivate(tskno));

			if (ercd >= 0) {
				syslog(LOG_NOTICE, "cTask_cancelActivate(%d) returns %d", tskno, ercd);
			}
			break;
		case 't':
			syslog(LOG_INFO, "#cTask_terminate(%d)", tskno);
			SVC_PERROR(cTask_terminate(tskno));
			break;
		case '>':
			syslog(LOG_INFO, "#cTask_changePriority(%d, HIGH_PRIORITY)", tskno);
			SVC_PERROR(cTask_changePriority(tskno, HIGH_PRIORITY));
			break;
		case '=':
			syslog(LOG_INFO, "#cTask_changePriority(%d, MID_PRIORITY)", tskno);
			SVC_PERROR(cTask_changePriority(tskno, MID_PRIORITY));
			break;
		case '<':
			syslog(LOG_INFO, "#(cTask_changePriority(%d, LOW_PRIORITY)", tskno);
			SVC_PERROR(cTask_changePriority(tskno, LOW_PRIORITY));
			break;
		case 'G':
			syslog(LOG_INFO, "#cTask_getPriority(%d, &tskpri)", tskno);
			SVC_PERROR(ercd = cTask_getPriority(tskno, &tskpri));
			if (ercd >= 0) {
				syslog(LOG_NOTICE, "priority of task %d is %d", tskno, tskpri);
			}
			break;
		case 'w':
			syslog(LOG_INFO, "#cTask_wakeup(%d)", tskno);
			SVC_PERROR(cTask_wakeup(tskno));
			break;
		case 'W':
			syslog(LOG_INFO, "#cTask_cancelWakeup(%d)", tskno);
			SVC_PERROR(ercd = cTask_cancelWakeup(tskno));
			if (ercd >= 0) {
				syslog(LOG_NOTICE, "cTask_cancelWakeup(%d) returns %d", tskno, ercd);
			}
			break;
		case 'l':
			syslog(LOG_INFO, "#cTask_releaseWait(%d)", tskno);
			SVC_PERROR(cTask_releaseWait(tskno));
			break;
		case 'u':
			syslog(LOG_INFO, "#cTask_suspend(%d)", tskno);
			SVC_PERROR(cTask_suspend(tskno));
			break;
		case 'm':
			syslog(LOG_INFO, "#cTask_resume(%d)", tskno);
			SVC_PERROR(cTask_resume(tskno));
			break;
		case 'x':
			syslog(LOG_INFO, "#cTask_raiseException(%d, 0x0001U)", tskno);
			SVC_PERROR(cTask_raiseException(tskno, 0x0001U));
			break;
		case 'X':
			syslog(LOG_INFO, "#cTask_raiseException(%d, 0x0002U)", tskno);
			SVC_PERROR(cTask_raiseException(tskno, 0x0002U));
			break;
		case 'r':
			syslog(LOG_INFO, "#rotateReadyQueue(three priorities)");
			SVC_PERROR(rotateReadyQueue(HIGH_PRIORITY));
			SVC_PERROR(rotateReadyQueue(MID_PRIORITY));
			SVC_PERROR(rotateReadyQueue(LOW_PRIORITY));
			break;
		case 'c':
			syslog(LOG_INFO, "#cCyclic_start(1)");
			SVC_PERROR(cCyclic_start());
			break;
		case 'C':
			syslog(LOG_INFO, "#cCyclic_stop(1)");
			SVC_PERROR(cCyclic_stop());
			break;
		case 'b':
			syslog(LOG_INFO, "#cAlarm_start(1, 5000)");
			SVC_PERROR(cAlarm_start(5000));
			break;
		case 'B':
			syslog(LOG_INFO, "#cAlarm_stop()(1)");
			SVC_PERROR(cAlarm_stop());
			break;
		case 'V':
#ifdef TOPPERS_SUPPORT_GET_UTM
			SVC_PERROR(getMicroTime(&utime1));
			SVC_PERROR(getMicroTime(&utime2));
			syslog(LOG_NOTICE, "utime1 = %ld, utime2 = %ld",
										(ulong_t) utime1, (ulong_t) utime2);
#else /* TOPPERS_SUPPORT_GET_UTM */
			syslog(LOG_NOTICE, "getMicroTime is not supported.");
#endif /* TOPPERS_SUPPORT_GET_UTM */
			break;
		case 'v':
			SVC_PERROR(cSysLog_mask(LOG_UPTO(LOG_INFO),
										LOG_UPTO(LOG_EMERG)));
			break;
		case 'q':
			SVC_PERROR(cSysLog_mask(LOG_UPTO(LOG_NOTICE),
										LOG_UPTO(LOG_EMERG)));
			break;
#ifdef BIT_KERNEL
		case ' ':
			SVC_PERROR(lockCpu());
			{
				extern ER	bit_kernel(void);

				SVC_PERROR(ercd = bit_kernel());
				if (ercd >= 0) {
					syslog(LOG_NOTICE, "bit_kernel passed.");
				}
			}
			SVC_PERROR(unlockCpu());
			break;
#endif /* BIT_KERNEL */
		default:
			break;
		}
	} while (c != '\003' && c != 'Q');

	syslog(LOG_NOTICE, "Sample program ends.");
	SVC_PERROR(ciKernel_exitKernel());
	assert(0);
}
