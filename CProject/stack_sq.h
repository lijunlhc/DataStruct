/*
 * stack_sq.h
 *
 *  Created on: 2019年3月9日
 *      Author: junli
 */

#ifndef STACK_SQ_H_
#define STACK_SQ_H_

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSIZE 100
typedef struct {

} SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;
Status InitStack_Sq(SqStack *S);
Status Push_Sq(SqStack *S, SElemType e);
Status Pop_Sq(SqStack *S, SElemType *e);
Status GetTop_Sq(SqStack S, SElemType *e);

#endif /* STACK_SQ_H_ */
