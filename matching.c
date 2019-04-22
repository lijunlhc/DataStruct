#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef struct {
	char ch;
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
	if (S->base)
		S->top = S->base;
	return OK;
}

Status DestroyStack(SqStack *S) {
	if (S->base) {
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
ElemType GetTopSqStack(SqStack S) {
	if (S.top == S.base)
		exit(OVERFLOW);
	else
		return *(S.top - 1);
}

Status Matching() 
{
	SqStack S;
	int flag = 1;
	char c;
	ElemType e;

	InitSqStack(&S);

	printf("Please enter characters: ");
	e.ch = getchar();

	while (e.ch != '#' && flag) 
	{
		switch (e.ch) {
		case '[':
		case '(':
			PushSqStack(&S, e);
			printf("Push\n");
			break;
		case ')':
			if (!SqStackEmpty(S) && GetTopSqStack(S).ch == '(') {
				PopSqStack(&S, &e);
				printf("Pop\n");
			} else
				flag = 0;
			break;
		case ']':
			if (!SqStackEmpty(S) && GetTopSqStack(S).ch == '[') {
				PopSqStack(&S, &e);
				printf("Pop\n");
			} else
				flag = 0;
			break;
		}
		//printf("Please enter a character: ");
		e.ch = getchar();
	}
	if (SqStackEmpty(S) && flag) {
		printf("TRUE\n");
		return TRUE;
	} else {
		printf("FALSE\n");
		return FALSE;
	}

}

int main() {
	Matching();
	return 0;
}
