/*
 * ElemType.c
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
	int num;
} ElemType;
typedef struct {
	ElemType *elem;
	int length;
} SqList;
Status InitList_SqL(SqList *L);
Status GetElem_SqL(SqList L, int i, ElemType *e);
int LocateElem_SqL(SqList L, ElemType e);
Status ListInsert_SqL(SqList *L, int i, ElemType e);
Status ListDelete_SqL(SqList *L, int i);
void MergeList_SqL(SqList *LA, SqList LB);
void MergeList_SqL_Ord(SqList LA, SqList LB, SqList *LC);
