/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "nMrubyc_tsKernel_Initializer_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* MBP: MrubyBridgePlugin: MBP000 */
#include <stdio.h>
#include <stdlib.h>
#include "mrubyc.h"

#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#ifndef NULL
#define NULL 0
#endif
//  Prototype MBP400
mrb_value  MrubyBridge_tsKernel_initialize( mrb_vm *vm, mrb_value self);
mrb_value  MrubyBridge_tsKernel_sleep( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_sleepTimeout( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_delay( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_exitTask( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_getTaskId( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_rotateReadyQueue( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_getTime( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_getMicroTime( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_lockCpu( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_unlockCpu( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_disableDispatch( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_enableDispatch( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_disableTaskException( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_enableTaskException( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_changeInterruptPriorityMask( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_getInterruptPriorityMask( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_exitKernel( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_senseContext( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_senseLock( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_senseDispatch( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_senseDispatchPendingState( mrb_vm *vm, mrb_value self );
mrb_value  MrubyBridge_tsKernel_senseKernel( mrb_vm *vm, mrb_value self );
/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInitialize
 * entry port: eInitialize
 * signature:  nMrubyc_sInitializeTECSBridge
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitialize_initializeBridge
 * name:         eInitialize_initializeBridge
 * global_name:  nMrubyc_tsKernel_Initializer_eInitialize_initializeBridge
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
/* eInitialize_initializeBridge(CELLIDX idx, mrb_state* mrb, struct RClass * TECS) */
eInitialize_initializeBridge(CELLIDX idx, mrb_vm * vm, struct RClass * TECS)
{
	mrb_class *mrbc_cl;

    CELLCB *p_cellcb = GET_CELLCB( idx );  /* no error check */     /* MBP700 */
/*    struct RClass	*rc;*/

/*    rc = mrb_define_class_under( mrb, TECS, "TsKernel", mrb->object_class );*/
    mrbc_cl = mrb_class_alloc( vm, "TsKernel", mrbc_class_object );
/*    mrb_define_method( mrb, rc, "initialize", MrubyBridge_tsKernel_initialize, MRB_ARGS_REQ(1) );*/
    mrbc_define_method( vm, mrbc_cl, "initialize", MrubyBridge_tsKernel_initialize );
/*    MRB_SET_INSTANCE_TT(rc, MRB_TT_DATA);*/
/*	mrb_define_method( mrb, rc, "sleep", MrubyBridge_tsKernel_sleep, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "sleep", MrubyBridge_tsKernel_sleep );
/*	mrb_define_method( mrb, rc, "sleepTimeout", MrubyBridge_tsKernel_sleepTimeout, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "sleepTimeout", MrubyBridge_tsKernel_sleepTimeout );
/*	mrb_define_method( mrb, rc, "delay", MrubyBridge_tsKernel_delay, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "delay", MrubyBridge_tsKernel_delay );
/*	mrb_define_method( mrb, rc, "exitTask", MrubyBridge_tsKernel_exitTask, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "exitTask", MrubyBridge_tsKernel_exitTask );
/*	mrb_define_method( mrb, rc, "getTaskId", MrubyBridge_tsKernel_getTaskId, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "getTaskId", MrubyBridge_tsKernel_getTaskId );
/*	mrb_define_method( mrb, rc, "rotateReadyQueue", MrubyBridge_tsKernel_rotateReadyQueue, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "rotateReadyQueue", MrubyBridge_tsKernel_rotateReadyQueue );
/*	mrb_define_method( mrb, rc, "getTime", MrubyBridge_tsKernel_getTime, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "getTime", MrubyBridge_tsKernel_getTime );
/*	mrb_define_method( mrb, rc, "getMicroTime", MrubyBridge_tsKernel_getMicroTime, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "getMicroTime", MrubyBridge_tsKernel_getMicroTime );
/*	mrb_define_method( mrb, rc, "lockCpu", MrubyBridge_tsKernel_lockCpu, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "lockCpu", MrubyBridge_tsKernel_lockCpu );
/*	mrb_define_method( mrb, rc, "unlockCpu", MrubyBridge_tsKernel_unlockCpu, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "unlockCpu", MrubyBridge_tsKernel_unlockCpu );
/*	mrb_define_method( mrb, rc, "disableDispatch", MrubyBridge_tsKernel_disableDispatch, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "disableDispatch", MrubyBridge_tsKernel_disableDispatch );
/*	mrb_define_method( mrb, rc, "enableDispatch", MrubyBridge_tsKernel_enableDispatch, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "enableDispatch", MrubyBridge_tsKernel_enableDispatch );
/*	mrb_define_method( mrb, rc, "disableTaskException", MrubyBridge_tsKernel_disableTaskException, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "disableTaskException", MrubyBridge_tsKernel_disableTaskException );
/*	mrb_define_method( mrb, rc, "enableTaskException", MrubyBridge_tsKernel_enableTaskException, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "enableTaskException", MrubyBridge_tsKernel_enableTaskException );
/*	mrb_define_method( mrb, rc, "changeInterruptPriorityMask", MrubyBridge_tsKernel_changeInterruptPriorityMask, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "changeInterruptPriorityMask", MrubyBridge_tsKernel_changeInterruptPriorityMask );
/*	mrb_define_method( mrb, rc, "getInterruptPriorityMask", MrubyBridge_tsKernel_getInterruptPriorityMask, MRB_ARGS_REQ( 1 ) );*/
	mrbc_define_method( vm, mrbc_cl, "getInterruptPriorityMask", MrubyBridge_tsKernel_getInterruptPriorityMask );
/*	mrb_define_method( mrb, rc, "exitKernel", MrubyBridge_tsKernel_exitKernel, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "exitKernel", MrubyBridge_tsKernel_exitKernel );
/*	mrb_define_method( mrb, rc, "senseContext", MrubyBridge_tsKernel_senseContext, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "senseContext", MrubyBridge_tsKernel_senseContext );
/*	mrb_define_method( mrb, rc, "senseLock", MrubyBridge_tsKernel_senseLock, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "senseLock", MrubyBridge_tsKernel_senseLock );
/*	mrb_define_method( mrb, rc, "senseDispatch", MrubyBridge_tsKernel_senseDispatch, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "senseDispatch", MrubyBridge_tsKernel_senseDispatch );
/*	mrb_define_method( mrb, rc, "senseDispatchPendingState", MrubyBridge_tsKernel_senseDispatchPendingState, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "senseDispatchPendingState", MrubyBridge_tsKernel_senseDispatchPendingState );
/*	mrb_define_method( mrb, rc, "senseKernel", MrubyBridge_tsKernel_senseKernel, MRB_ARGS_NONE() );*/
	mrbc_define_method( vm, mrbc_cl, "senseKernel", MrubyBridge_tsKernel_senseKernel );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
