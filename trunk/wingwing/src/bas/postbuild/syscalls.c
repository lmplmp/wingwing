/*
 * syscalls.c
 *
 *  Created on: 2010. 12. 15.
 *      Author: Sanghoon Kim
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>

#include <stm32f10x.h>

/**
 * Increase program data space. Malloc and related functions depend on this
 */
caddr_t _sbrk(int incr) {
	static unsigned char *heap = NULL;
	unsigned char *prev_heap;

	extern int __HEAP_START; // Linker script 에서 __HEAP_START이 제공되어야 한다.

	if (heap == NULL) {
		heap = (unsigned char *) &__HEAP_START;
	}
	prev_heap = heap;
	/* check removed to show basic approach */

	heap += incr;

	return (caddr_t) prev_heap;
}

volatile int ITM_RxBuffer = ITM_RXBUFFER_EMPTY;

/**
 * Read a character to a file. `libc' subroutines will use this system routine
 * for input from all files, including stdin Returns -1 on error or blocks
 * until the number of characters have been read.
 */
int _read(int file, char *ptr, int len) {
	int n;
	int num = 0;
	switch (file) {
	case STDIN_FILENO:
		for (n = 0; n < len; n++) {
			int c = ITM_ReceiveChar();
			if (c < 0)
				break;

			*ptr++ = (unsigned char) c;
			num++;
		}
		break;
	default:
		errno = EBADF;
		return -1;
	}
	return num;
}

/**
 * Write a character to a file. `libc' subroutines will use this system routine
 * for output to all files, including stdout Returns -1 on error or number
 * of bytes sent
 */
int _write(int file, char *ptr, int len) {
	int i;
	for (i = 0; i < len; ++i) {
		ITM_SendChar(ptr[i]);
	}
	return len;
}

int _close(int file) {
	return -1;
}

/**
 * Status of an open file. For consistency with other minimal implementations
 * in these examples, all files are regarded as character special devices.
 * The `sys/stat.h' header file required is distributed in the `include'
 * subdirectory for this C library.
 */
int _fstat(int file, struct stat *st) {
	st->st_mode = S_IFCHR;
	return 0;
}

/**
 * Query whether output stream is a terminal.
 * For consistency with the other minimal implementations
 */
int _isatty(int file) {
	switch (file) {
	case STDOUT_FILENO:
	case STDERR_FILENO:
	case STDIN_FILENO:
		return 1;
	default:
		//errno = ENOTTY;
		errno = EBADF;
		return 0;
	}
}

/**
 * Set position in a file. Minimal implementation:
 */
int _lseek(int file, int ptr, int dir) {
	return 0;
}
