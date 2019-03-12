/*
 * queue_sq.h
 *
 *  Created on: 2019年3月11日
 *      Author: junli
 */

#ifndef SQQUEUE_H_
#define SQQUEUE_H_

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
Status InitSqQueue(SqQueue *Q);
int SqQueueLength(SqQueue Q);
Status EnSqQueue(SqQueue *Q, QElemType e);
Status DeSqQueue(SqQueue *Q, QElemType *e);
QElemType GetHeadSqQueue(SqQueue);
Status SqQueueEmpty(SqQueue Q);

#endif /* SQQUEUE_H_ */
