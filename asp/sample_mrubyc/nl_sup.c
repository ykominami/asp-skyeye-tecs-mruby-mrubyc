#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>

#include <kernel.h>
#include <t_syslog.h>
#include "nl_sup.h"
#include "kernel_cfg.h"
#include "sil.h"
#include "target_serial.h"

void putStr(char *str)
{
	char *c = str;

	while( *c != '\0' )
	{
		putChar( *c++ );
	}
}

void putChar(char c)
{
	sil_wrw_mem((void*)(USART0_THR),c);
}

size_t	fwrite(const void *buf , size_t _size, size_t _n, int fp)
{
	syslog( LOG_NOTICE, "%s" , buf );
}

#undef errno
extern int errno;
int _fstat(int file, struct stat *st) {
	switch(file) {
	case STDIN_FILENO:
	case STDOUT_FILENO:
	case STDERR_FILENO:
		st->st_mode = S_IFCHR;
		return 0;
	}

	errno = EBADF;
	return -1;
}

int _isatty(int file) {
	switch(file) {
	case STDIN_FILENO:
	case STDOUT_FILENO:
	case STDERR_FILENO:
		return 1;
	}

	errno = EBADF;
	return -1;
}

int _getpid(void) {
    assert(0);
    return 1;
}

int _kill(int pid, int sig) {
    assert(0);
    errno = EINVAL;
    return -1;
}

void _exit(int status) {
    assert(0);
/*    ext_ker();*/
    while(1);
}

/* MPF_FOR_NEWLIB_ID */

#include <reent.h>
#include <unistd.h>
#include <kernel.h>
#include "kernel_cfg.h"
#include <arch/arm_gcc/common/core_config.h>

extern uint32_t _kernel_excpt_nest_count;

static char *storage = NULL;

int memory_init(void)
{
  int ret = false;
  ER ercd;
  if (storage == NULL) 
  {
	ercd = get_mpf( MPF_FOR_NEWLIB_ID , &storage );
	if( ercd != E_OK )
	{
		/* error  */
		syslog(LOG_EMERG , "_sbrk_r 0(%d)[%d](%d|%d)[%d]" , ercd , sns_ctx() , _kernel_excpt_nest_count ,_kernel_excpt_nest_count > 0L , t_sense_lock() );
	}
	else
	{
		ret = true;
	}
  }
  return ret;
}

void *_sbrk_r(struct _reent *ptr, ptrdiff_t incr)
{
  static size_t pos = 0;
  char *result;

  if (pos + incr >= BLOCK_SIZE_OF_MPF_FOR_NEWLIB)
  {
/*	syslog(LOG_EMERG , "_sbrk_r 1");*/
    return NULL;
  }
  result = storage + pos;
  pos += incr;
/*  syslog(LOG_EMERG , "_sbrk_r 2");*/
  return result;
}

void __malloc_lock (struct _reent *ptr)
{
  (void)ptr;
  if (!sns_ker())
  {
    dis_dsp();
  }
}

void __malloc_unlock (struct _reent *ptr)
{
  (void)ptr;
  if (!sns_ker())
  {
    ena_dsp();
  }
}

#if 0
/* JSPのnewlibrt.cの実装 */
void *_sbrk_r(struct _reent *ptr, size_t nbyte)
{
	extern char end;
	static char *heap_ptr = &end;
	static char *heap_end = (char*)~0L;
	char *base;

	if (!iniflg)
	{
		volatile char _auto;
		if (&end < &_auto && &_auto < heap_end)
			heap_end = (char*)&_auto;
	}

	if (heap_ptr + nbyte + 32 > heap_end)
	{
		ptr->_errno = errno = ENOMEM;
		return (void*)-1;
	}

	base = heap_ptr;
	heap_ptr += nbyte;
	return base;
}
#endif /* 0 */


#if 0
/* sqlite3_toppers */
/* libc_syscall.c */

/*
 *  Newlibのmalloc/freeを使うための下請け関数
 *  他の環境に移植する場合は、ライブラリの仕様に合わせて実装しなおす
 *  必要がある。
 */

#include <reent.h>
#include <unistd.h>
#include <kernel.h>
#include "kernel_cfg.h"


/* ヒープサイズ */
#ifndef HEAP_SIZE
# define HEAP_SIZE 0x100000
/* # define HEAP_SIZE 0x10000 */
#endif

void *_sbrk_r(struct _reent *ptr, ptrdiff_t incr)
{
  static uint64_t storage[HEAP_SIZE / sizeof(uint64_t)];
  static size_t pos = 0;
  char *result;

  if (pos + incr >= sizeof(storage))
    return NULL;

  incr = (incr + sizeof(uint64_t) - 1) / sizeof(uint64_t) * sizeof(uint64_t);
  result = (char*)storage + pos;
  pos += incr;
  return result;
}

void __malloc_lock (struct _reent *ptr)
{
  (void)ptr;
  if (!sns_ker())
    dis_dsp();
}

void __malloc_unlock (struct _reent *ptr)
{
  (void)ptr;
  if (!sns_ker())
    ena_dsp();
}

#endif /* 0 */

