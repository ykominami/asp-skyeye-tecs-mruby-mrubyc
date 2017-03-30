/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cTECS signature: sSample context:task
 *   ER             cTECS_sayHello( int32_t times );
 *   ER             cTECS_howAreYou( char_t* buf, int32_t len );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "nMrubyc_tsSample_tecsgen.h"

#include "kernel.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* MBP: MrubyBridgePlugin: MBP000 */
#include <stdio.h>
#include <stdlib.h>
#include "mrubyc.h"

#include "mrubyc/nMrubyc_sup.h"

#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#ifndef NULL
#define NULL 0
#endif
extern nMruby_tsSample_CB  SimpleBridge0_INIB;
extern nMruby_tsSample_CB  SimpleBridge2_INIB;

/* RData MBP001 */
static void 
tsSample_free( struct VM *vm, void *p )
{
	if( p )
		(void)mrbc_free( vm, p );
}
#if 0
/* RData MBP002 */
struct mrb_data_type data_type_tsSample =
{
	"tsSample",
	tsSample_free
};
#endif
/* RData MBP003 */
struct tecs_tsSample {
    CELLCB  *cbp;
};

/* name_to_cbp MBP010 */
const struct name_to_cbp_tsSample {
    char   *name;    /* Cell Name */
    CELLCB *cbp;
} Name_to_cbp_tsSample[] = {
	{ "SimpleBridge0", &SimpleBridge0_INIB },
	{ "SimpleBridge2", &SimpleBridge2_INIB },
	{ 0, 0 },
};


/* MBP100 */
mrb_value
MrubyBridge_tsSample_initialize( struct VM *vm, mrb_value self)
{
#if 0
	mrb_value	name;
	struct tecs_tsSample *tecs_cb;
	const struct name_to_cbp_tsSample *ntc;

	/* set DATA_TYPE earlier to avoid SEGV */
	DATA_TYPE( self ) = &data_type_tsSample;

	mrb_get_args(mrb, "o", &name );
	if( mrb_type( name ) != MRB_TT_STRING ){
		mrb_raise(mrb, E_NAME_ERROR, "cell name not string");
	}
	for( ntc = &Name_to_cbp_tsSample[0]; ntc->name != NULL; ntc++ ){
		if( strcmp( ntc->name, RSTRING_PTR( name ) ) == 0 )
			break;
	}
	if( ntc->name == 0 ){
		mrb_raise(mrb, E_ARGUMENT_ERROR, "cell not found");
	}
	tecs_cb = (struct tecs_tsSample *)mrb_malloc(mrb, sizeof(struct tecs_tsSample) );
	tecs_cb->cbp = ntc->cbp;
	DATA_PTR( self ) = (void *)tecs_cb;
#endif
	return self;
}

/* bridge function (MBP101) */
mrb_value
MrubyBridge_tsSample_sayHello( struct VM *vm, mrb_value self )
{
#if 0
	/* cellcbp (MBP105) */
	CELLCB	*p_cellcb = ((struct tecs_tsSample *)DATA_PTR(self))->cbp;
	/* variables for return & parameter (MBP110) */
#endif
	ER	ret_val;
#if 0
	mrb_int	mrb_times;
	int32_t	times;
	/* retrieve arguments (MBP111) */
	mrb_get_args(mrb, "i", &mrb_times );
	/* convert mrb to C (MBP112) */
	VALCHECK_Int32( mrb, mrb_times );
	times = (int32_t)mrb_times;
	/* calling target (MBP120) */
	ret_val = cTECS_sayHello( times );
#else
	ret_val = E_OK;
#endif
	/* return (MBP130) */
	return mrb_fixnum_value( ret_val );
}

/* bridge function (MBP101) */
mrb_value
MrubyBridge_tsSample_howAreYou( struct VM *vm, mrb_value *v )
{
#if 0
	/* cellcbp (MBP105) */
	CELLCB	*p_cellcb = ((struct tecs_tsSample *)DATA_PTR(self))->cbp;
	/* variables for return & parameter (MBP110) */
#endif
	ER	ret_val;
	mrb_value	mrb_buf;
	char_t*	buf;
	mrb_int	mrb_len;
	int32_t	len;
#if 0
	/* retrieve arguments (MBP111) */
	mrb_get_args(mrb, "oi", &mrb_buf, &mrb_len );
	/* convert mrb to C (MBP112) */
	VALCHECK_Int32( mrb, mrb_len );
	len = (int32_t)mrb_len;
	/* convert mrb to C for pointer types (MBP113) */
	buf = CheckAndGetCharPointerMod( mrb, mrb_buf, len );
	/* calling target (MBP120) */
	ret_val = cTECS_howAreYou( buf, len );
#else
	ret_val = E_OK;
#endif
	/* return (MBP130) */
	return mrb_fixnum_value( ret_val );
}
/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
