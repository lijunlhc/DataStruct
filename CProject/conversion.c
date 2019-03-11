/*
 * conversion.c
 *
 *  Created on: 2019年3月11日
 *      Author: junli
 */
#include <stdio.h>
//#include "sqstack.h"
#include "linkstack.h"
void conversion(int N) {
	LinkStack S;
	InitLinkStack(&S);
	SElemType e;
	while(N) {
		e.num = N % 8;
		PushLinkStack(&S, e);
		N /= 8;
	}
	while(!LinkStackEmpty(S)) {
		PopLinkStack(&S, &e);
		printf("%d", e.num);
	}
	printf("\n");
}
