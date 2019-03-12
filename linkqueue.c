/*
 * linkqueue.c
 *
 *  Created on: 2019年3月11日
 *      Author: junli
 */
#include <stdlib.h>
#include "linkqueue.h"
Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e) {
	if(Q->front == Q->rear)
		return ERROR;
	QNode *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}
QElemType GetHeadLinkQueue(LinkQueue Q) {
	if(Q.front != Q.rear)
		return Q.front->next->data;
}
