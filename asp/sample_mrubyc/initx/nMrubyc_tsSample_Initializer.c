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
#include "nMrubyc_tsSample_Initializer_tecsgen.h"

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
mrb_value  MrubyBridge_tsSample_initialize( struct VM *vm, mrb_value self);
mrb_value  MrubyBridge_tsSample_sayHello( struct VM *vm, mrb_value self );
mrb_value  MrubyBridge_tsSample_howAreYou( struct VM *vm, mrb_value self );
/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInitialize
 * entry port: eInitialize
 * signature:  nMrubyc_sInitializeTECSBridge
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitialize_initializeBridge
 * name:         eInitialize_initializeBridge
 * global_name:  nMrubyc_tsSample_Initializer_eInitialize_initializeBridge
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
/* eInitialize_initializeBridge(CELLIDX idx, mrb_vm* mrb, struct RClass * TECS) */
eInitialize_initializeBridge(CELLIDX idx, struct VM *vm, struct RClass * TECS)
{
	mrb_class *mrbc_cl;

    CELLCB *p_cellcb = GET_CELLCB( idx );  /* no error check */     /* MBP700 */
/*    struct RClass	*rc;*/

putStr("MSI\n");
/*    rc = mrb_define_class_under( mrb, TECS, "TsSample", mrb->object_class );*/
	mrbc_cl = mrbc_class_alloc(vm, "TsSample", mrbc_class_object);
/*    mrb_define_method( mrb, rc, "initialize", MrubyBridge_tsSample_initialize, MRB_ARGS_REQ(1) );*/
    mrbc_define_method( vm, mrbc_cl, "initialize", MrubyBridge_tsSample_initialize );
/*    MRB_SET_INSTANCE_TT(rc, MRB_TT_DATA);*/
/*	mrb_define_method( mrb, rc, "sayHello", MrubyBridge_tsSample_sayHello, MRB_ARGS_REQ( 1 ) );*/
	mrb_define_method( vm, mrbc_cl, "sayHello", MrubyBridge_tsSample_sayHello );
/*	mrb_define_method( mrb, rc, "howAreYou", MrubyBridge_tsSample_howAreYou, MRB_ARGS_REQ( 2 ) );*/
	mrb_define_method( vm, mrbc_cl, "howAreYou", MrubyBridge_tsSample_howAreYou );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
