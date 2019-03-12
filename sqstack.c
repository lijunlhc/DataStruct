/*
 * stack_sq.c
 *
 *  Created on: 2019年3月9日
 *      Author: junli
 */

#include <stdlib.h>

#include "sqstack.h"
Status InitSqStack(SqStack *S) {
	S->base = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}
Status PushSqStack(SqStack *S, ElemType e) {
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top++ = e;
	return OK;
}
Status PopSqStack(SqStack *S, ElemType *e) {
	if (S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}
Status GetTopSqStack(SqStack S, ElemType *e) {
	if(S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}
Status SqStackEmpty(SqStack S) {
	if(S.top == S.base)
		return OK;
	else
		return ERROR;
}
