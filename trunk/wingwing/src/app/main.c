#include <stdio.h>
#include "stm32f10x.h"

volatile int _cnt;

int main(void) {
	while (1) {
		++_cnt;
		printf("hello~\n");
	}

	return 0;
}

