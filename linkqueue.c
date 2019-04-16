/*
 * linkqueue.c
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

typedef struct {
	int num;
} QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q) {
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status QueueEmpty(LinkQueue Q) {
	return Q.front == Q.rear;
}

Status GetHead(LinkQueue Q, QElemType *e) {
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e) {
	QNode *p = (QNode *) malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e) {
	if (Q->front == Q->rear)
		return ERROR;
	QNode *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

int main() {
	printf("Hello World\n");
}
