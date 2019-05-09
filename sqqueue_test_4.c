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
	char *base;
	int front;
	int rear;
} SqQueue;

Status InitQueue(SqQueue *Q) {
	Q->base = (char *)malloc(sizeof(char) * MAXSIZE);
	if(!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, char e) {
	if((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, char *e) {
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

char GetHeadQueue(SqQueue Q) {
	if(Q.front != Q.rear)
		return Q.base[Q.front];
}

Status QueueEmpty(SqQueue Q) {
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

void Josephus() {
    SqQueue Q;
    int count;
    char t;

    InitQueue(&Q);
    for(char i = 'a'; i <= 'f'; i++)
        EnQueue(&Q, i);

    count = 1;    
    while(QueueLength(Q) > 1) {
        DeQueue(&Q, &t);
        if(count < 3)
        {
            EnQueue(&Q, t);
            count++;
        }
        else {
            printf("out: %c\t", t);
            count = 1;
        }
    }
    printf("\nthe victor is: %c\n", GetHeadQueue(Q));
}

int main() {
    Josephus();
    return 0;
}