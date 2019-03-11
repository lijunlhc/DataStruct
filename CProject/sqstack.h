/*
 * stack_sq.h
 *
 *  Created on: 2019年3月9日
 *      Author: junli
 */

#ifndef SQSTACK_H_
#define SQSTACK_H_

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSIZE 100
typedef struct {
	int num;
} SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;
Status InitSqStack(SqStack *S);
Status PushSqStack(SqStack *S, SElemType e);
Status PopSqStack(SqStack *S, SElemType *e);
Status GetTopSqStack(SqStack S, SElemType *e);
Status SqStackEmpty(SqStack S);

#endif /* SQSTACK_H_ */
