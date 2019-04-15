/*
 * stack_link.c
 *
 *  Created on: 2019年3月10日
 *      Author: junli
 */

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct {
	char ch;
} SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack *S) {
	*S = NULL;
	return OK;
}

Status StackEmpty(LinkStack S) {
	if (S == NULL)
		return 1;
	else
		return 0;
}

Status Push(LinkStack *S, SElemType e) {
	StackNode *p = (StackNode *) malloc(sizeof(SElemType));
	p->data = e;
	p->next = *S;
	*S = p;
	return OK;
}

Status Pop(LinkStack *S, SElemType *e) {
	if (*S == NULL)
		return ERROR;
	*e = (*S)->data;
	StackNode *p = *S;
	*S = (*S)->next;
	free(p);
	return OK;
}

SElemType GetTop(LinkStack S) {
	if (S == NULL)
		exit(1);
	else
		return S->data;
}

Status LinkStackEmpty(LinkStack S) {
	if (S != NULL)
		return ERROR;
	else
		return OK;
}

int main() {
	printf("Hello World\n");
	return 0;
}
