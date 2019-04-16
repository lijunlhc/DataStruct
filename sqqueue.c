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

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef struct {
	char name[20];
    char sex;
} QElemType;

typedef struct {
	QElemType *base;
	int front;
	int rear;
} SqQueue;

Status InitQueue(SqQueue *Q) {
	Q->base = (QElemType *)malloc(sizeof(QElemType) * MAXSIZE);
	if(!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e) {
	if((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e) {
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

QElemType GetHeadQueue(SqQueue Q) {
	if(Q.front != Q.rear)
		return Q.base[Q.front];
}

Status QueueEmpty(SqQueue Q) {
	if(Q.front == Q.rear)
		return 1;
	else
		return 0;
}

int main() {
	printf("Hello\n");
	return 0;
}
