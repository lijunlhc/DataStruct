/*
 * stack_link.c
 *
 *  Created on: 2019年3月10日
 *      Author: junli
 */

#include <stdlib.h>
#include "stack_link.h"
Status InitStack_Link(LinkStack *S) {
	*S = NULL;
	return OK;
}
Status Push_Link(LinkStack *S, SElemType e) {
	StackNode *p = (StackNode *)malloc(sizeof(SElemType));
	p->data = e;
	p->next = *S;
	*S = p;
	return OK;
}
Status Pop_Link(LinkStack *S, SElemType *e) {
	if(*S == NULL)
		return ERROR;
	*e = (*S)->data;
	StackNode *p = *S;
	*S = (*S)->next;
	free(p);
	return OK;
}
