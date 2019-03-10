/*
 * stack_sq.c
 *
 *  Created on: 2019年3月9日
 *      Author: junli
 */

#include <stdlib.h>
#include "stack_sq.h"
Status InitStack_Sq(SqStack *S) {
	S->base = (SElemType *) malloc(sizeof(SElemType) * MAXSIZE);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}
Status Push_Sq(SqStack *S, SElemType e) {
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top++ = e;
	return OK;
}
Status Pop_Sq(SqStack *S, SElemType *e) {
	if (S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}
Status GetTop_Sq(SqStack S, SElemType *e) {
	if(S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}
