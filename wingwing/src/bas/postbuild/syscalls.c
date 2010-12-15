/*
 * syscalls.c
 *
 *  Created on: 2010. 12. 15.
 *      Author: Sanghoon Kim
 */

/* for caddr_t (typedef char * caddr_t;) */
#include <sys/types.h>

extern int __HEAP_START; // Linker script 에서 __HEAP_START이 제공되어야 한다.

caddr_t _sbrk(int incr) {
	static unsigned char *heap = NULL;
	unsigned char *prev_heap;

	if (heap == NULL) {
		heap = (unsigned char *) &__HEAP_START;
	}
	prev_heap = heap;
	/* check removed to show basic approach */

	heap += incr;

	return (caddr_t) prev_heap;
}
