#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

#undef errno
extern int errno;
int _fstat(int file, struct stat *st) {
	switch(file) {
	case STDIN_FILENO:
	case STDOUT_FILENO:
	case STDERR_FILENO:
	case SIO_UART_FILENO:
	case SIO_BT_FILENO:
	case SIO_STD_FILENO:
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
	case SIO_UART_FILENO:
	case SIO_BT_FILENO:
	case SIO_STD_FILENO:
		return 1;
	}

	errno = EBADF;
	return -1;
}

int _getpid(void) {
    assert(false);
    return 1;
}

int _kill(int pid, int sig) {
    assert(false);
    errno = EINVAL;
    return -1;
}

void _exit(int status) {
    assert(false);
    ext_ker();
    while(1);
}

int _open_r(struct _reent *ptr, const char *file, int flags, int mode) {
    return cal_svc(TFN_NEWLIB_OPEN_R, (intptr_t)ptr, (intptr_t)file, (intptr_t)flags, (intptr_t)mode, 0);
}

ssize_t _read_r(struct _reent *ptr, int fd, void *buf, size_t cnt) {
    return cal_svc(TFN_NEWLIB_READ_R, (intptr_t)ptr, (intptr_t)fd, (intptr_t)buf, (intptr_t)cnt, 0);
}

/**
 * Override the default allocator in newlib
 */

static void *mem_pool;

void _initialize_ev3api_newlib() {
#if 0
	ER ercd;
	ID domid;
	ercd = get_did(&domid);
	assert(ercd == E_OK);
	assert(domid == TDOM_APP); // Newlib should not be used by CSL.
#endif

	// TODO: Thread safe
	assert(mem_pool == NULL);
	if (mem_pool == NULL) {
		brickinfo_t brickinfo;
		ER ercd = fetch_brick_info(&brickinfo);
		assert(ercd == E_OK);
		mem_pool = brickinfo.app_heap;
		assert(mem_pool != NULL);
	}
}

