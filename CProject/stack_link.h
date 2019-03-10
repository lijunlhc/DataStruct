/*
 * stack_link.h
 *
 *  Created on: 2019年3月10日
 *      Author: junli
 */

#ifndef STACK_LINK_H_
#define STACK_LINK_H_

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct {

} SElemType;
typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
} StackNode, *LinkStack;
Status InitStack_Link(LinkStack *S);
Status Push_Link(LinkStack *S, SElemType e);
Status Pop_Link(LinkStack *S, SElemType *e);

#endif /* STACK_LINK_H_ */
