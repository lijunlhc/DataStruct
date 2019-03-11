/*
 * stack_link.c
 *
 *  Created on: 2019年3月10日
 *      Author: junli
 */

#include <stdlib.h>

#include "linkstack.h"
Status InitLinkStack(LinkStack *S) {
	*S = NULL;
	return OK;
}
Status PushLinkStack(LinkStack *S, SElemType e) {
	StackNode *p = (StackNode *)malloc(sizeof(SElemType));
	p->data = e;
	p->next = *S;
	*S = p;
	return OK;
}
Status PopLinkStack(LinkStack *S, SElemType *e) {
	if(*S == NULL)
		return ERROR;
	*e = (*S)->data;
	StackNode *p = *S;
	*S = (*S)->next;
	free(p);
	return OK;
}
SElemType GetTopLinkStack(LinkStack S) {
	if(S != NULL)
		return S->data;
}
Status LinkStackEmpty(LinkStack S) {
	if(S != NULL)
		return ERROR;
	else
		return OK;
}
