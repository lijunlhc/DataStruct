/*
 * linkqueue.h
 *
 *  Created on: 2019年3月11日
 *      Author: junli
 */

#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

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
Status InitQueue(LinkQueue *Q);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);
QElemType GetHeadLinkQueue(LinkQueue Q);

#endif /* LINKQUEUE_H_ */
