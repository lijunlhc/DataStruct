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
	Q->base = (QElemType *) malloc(sizeof(QElemType) * MAXSIZE);
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e) {
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

QElemType GetHeadQueue(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}

Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return 1;
	else
		return 0;
}
void DancePartner(QElemType dancer[], int num) {
	SqQueue Mdancers;
	SqQueue Fdancers;
	InitQueue(&Mdancers);
	InitQueue(&Fdancers);
	QElemType p;
	for (int i = 0; i < num; ++i) {
		p = dancer[i];
		if (p.sex == 'F')
			EnQueue(&Fdancers, p);
		else
			EnQueue(&Mdancers, p);
	}
	printf("The dancing partners are:\n");
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
		DeQueue(&Fdancers, &p);
		printf("%s ", p.name);
		DeQueue(&Mdancers, &p);
		printf("%s\n", p.name);
	}
	if (!QueueEmpty(Fdancers)) {
		p = GetHeadQueue(Fdancers);
		printf("The first woman to get a partner is: %s\n", p.name);
	} else if (!QueueEmpty(Mdancers)) {
		p = GetHeadQueue(Mdancers);
		printf("The first man to get a partner is: %s\n", p.name);
	}
}

int main() {
	QElemType dancers[6] = { { "1", 'F' }, { "2", 'F' }, { "3", 'F' }, { "4",
			'M' }, { "5", 'M' }, { "6", 'M' } };
	DancePartner(dancers, 6);
	return 0;
}
