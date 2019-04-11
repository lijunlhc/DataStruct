#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define MAXSIZE 100

typedef struct {
	int num;
} ElemType;

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
} SqStack;

Status InitSqStack(SqStack *S) {
	S->base = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}

Status SqStackEmpty(SqStack S) {
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

int StackLength(SqStack S) {
	return S.top - S.base;
}

Status ClearStack(SqStack *S) {
	if(S->base)
		S->top = S->base;
	return OK;
}

Status DestroyStack(SqStack *S) {
	if(S->base) {
		free(S->base);
		S->stacksize = 0;
		S->base = S->top = NULL;
	}
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
	if (S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}

int main() {
	printf("测试\n");
	return 0;
}
