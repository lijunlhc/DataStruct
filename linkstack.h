/*
 * stack_link.h
 *
 *  Created on: 2019年3月10日
 *      Author: junli
 */

#ifndef LINKSTACK_H_
#define LINKSTACK_H_

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
Status InitLinkStack(LinkStack *S);
Status PushLinkStack(LinkStack *S, SElemType e);
Status PopLinkStack(LinkStack *S, SElemType *e);
SElemType GetTopLinkStack(LinkStack S);
Status LinkStackEmpty(LinkStack S);

#endif /* LINKSTACK_H_ */
