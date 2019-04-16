/*
 * sqqueue.c
 *
 *  Created on: 2019年3月11日
 *      Author: junli
 */

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define MAXQSIZE 100

typedef struct {
	char name[20];
    char sex;
} QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
} SqQueue;
#define TRUE 1
#define FALSE 0
Status InitSqQueue(SqQueue *Q) {
	Q->base = (QElemType *)malloc(sizeof(QElemType) * MAXQSIZE);
	if(!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}
int SqQueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status EnSqQueue(SqQueue *Q, QElemType e) {
	if((Q->rear + 1) % MAXQSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}
Status DeSqQueue(SqQueue *Q, QElemType *e) {
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}
QElemType GetHeadSqQueue(SqQueue Q) {
	if(Q.front != Q.rear)
		return Q.base[Q.front];
}
Status SqQueueEmpty(SqQueue Q) {
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int main() {
	printf("Hello World\n");
	return 0;
}
