/*
 * Polynomial.c
 *
 *  Created on: 2019年3月5日
 *      Author: junli
 */
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSIZE 10
typedef struct {
	float coef;
	int expn;
} Polynomial;
typedef struct {
	Polynomial *elem;
	int length;
} SqList;
Status InitList(SqList *L);
Status GetElem(SqList L, int i, Polynomial *e);
int LocateElem(SqList L, Polynomial e);
Status ListInsert(SqList *L, int i, Polynomial e);
Status ListDelete(SqList *L, int i);
