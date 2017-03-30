/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 * 呼び口関数 #_TCPF_#
 * call port : cSerialPort  signature: sSerialPort context: task
 *   ER             cSerialPort_open( );
 *   ER             cSerialPort_close( );
 *   ER_UINT        cSerialPort_read( char_t* buffer, uint_t length );
 *   ER_UINT        cSerialPort_write( const char_t* buffer, uint_t length );
 *   ER             cSerialPort_control( uint_t ioControl );
 *   ER             cSerialPort_refer( T_SERIAL_RPOR* pk_rpor );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "nMruby_tMruby_tecsgen.h"
#include <string.h>

#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/data.h>
#include <mruby/compile.h>


#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

void print_hint(void);
void mrb_init_mrb(CELLCB *p_cellcb, mrb_state *mrb);
/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMrubyBody
 * entry port: eMrubyBody
 * signature:  sMrubyBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMrubyBody_main
 * name:         eMrubyBody_main
 * global_name:  nMruby_tMruby_eMrubyBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMrubyBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	mrb_state *mrb;
	
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}

	print_hint();
	/* new interpreter instance */
	mrb = mrb_open();
	if (mrb == NULL) {
		fprintf(stderr, "Invalid mrb_state, exiting test driver\n");
		return;
	}
#ifdef MRUBY_BRIDGE
extern void tMrubyBridge_init( mrb_state *mrb );
	tMrubyBridge_init( mrb );
#endif //MRUBY_BRIDGE
	mrb_init_mrb(p_cellcb, mrb);
	mrb_close(mrb);
}


/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

void
mrb_init_mrb(CELLCB	*p_cellcb, mrb_state *mrb)
{
  int n = mrb_read_irep(mrb, ATTR_irep);
  mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_top_self(mrb));
  if (mrb->exc) {
    mrb_p(mrb, mrb_obj_value(mrb->exc));
    exit(0);
  }
}


extern void debug_print(char * str);
extern void debug_print_address(char * str, int address);
extern void debug_print_int(char * str, int data);
#include <errno.h>
void *
_sbrk(size_t incr)
{
	extern char __cs3_heap_end;
	extern char __end;
	static char *heap_end = &__end;
	char *prev_heap_end;
	
	prev_heap_end = heap_end;

	if (heap_end + incr > &__cs3_heap_end) {
		errno = ENOMEM;
		return (void *)-1;
	}
	heap_end += incr;
	
#ifdef DEBUG_MALLOC	
	debug_print_int("incr",incr);
	debug_print_address("prev_heap_end",(int) prev_heap_end);
	dly_tsk(50);
#endif
	return (void *) prev_heap_end;
}

int write( int fd, const void *buffer, unsigned int count){
	/* シリアルポートが結合されている場合のみ呼び出す*/
	if(is_cSerialPort_joined()){
		cSerialPort_write(buffer, count);
	}
};

//void _exit(){}

void _close(){}
void _lseek(){}
void _read(){}
void _getpid(){}
void _kill(){}
void _fstat(){}
void _isatty(){}
void _gettimeofday(){}

/* Print a short remark for the user */
void print_hint(void)
{
	printf("mrbtest - Embeddable Ruby and TECS Test\n");
	printf("\nThis is a very early version, please test and report errors.\n");
	printf("Thanks :)\n\n");
}