/*
 * ElemType.c
 *
 *  Created on: 2019年3月5日
 *      Author: junli
 */
#include <stdlib.h>
#include "SqList.h"
Status InitList_SqL(SqList *L) {
	L->elem = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
	if (!(L->elem))
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}
Status GetElem_SqL(SqList L, int i, ElemType *e) {
	if (i < 1 || i > L.length)
		return ERROR;
	*e = *(L.elem + i - 1);
	return OK;
}
int LocateElem_SqL(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.elem[i].num == e.num)
			return i + 1;
	return 0;
}
Status ListInsert_SqL(SqList *L, int i, ElemType e) {
	if ((i < 1) || (i > L->length + 1))
		return ERROR;
	if (L->length == MAXSIZE)
		return ERROR;
	for (int j = L->length - 1; j >= i - 1; j--)
		L->elem[j + 1] = L->elem[j];
	L->elem[i - 1] = e;
	++(L->length);
	return OK;
}
Status ListDelete_SqL(SqList *L, int i) {
	if ((i < 1) || (i > L->length))
		return ERROR;
	for (int j = i; j <= L->length - 1; j++)
		L->elem[j - 1] = L->elem[j];
	--(L->length);
	return OK;
}
void MergeList_SqL(SqList *LA, SqList LB)
{
	int m = LA->length;
	int n = LB.length;
	ElemType e;
	for(int i = 1; i <= n; i++)
	{
		GetElem_SqL(LB, i, &e);
		if(!LocateElem_SqL(*LA, e))
			ListInsert_SqL(LA, ++m, e);
	}
}
void MergeList_SqL_Ord(SqList LA, SqList LB, SqList * LC) {
	LC->length = LA.length + LB.length;
	LC->elem = (ElemType *)malloc(sizeof(ElemType) * LC->length);
	ElemType * pc = LC->elem;
	ElemType * pa = LA.elem;
	ElemType * pb = LB.elem;
	ElemType * pa_last = LA.elem + LA.length - 1;
	ElemType * pb_last = LB.elem + LB.length - 1;
	while((pa <= pa_last) && (pb <= pb_last)) {
		if(pa->num <= pb->num)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while(pa <= pa_last)
		*pc++ = *pa++;
	while(pb <= pb_last)
		*pc++ = *pb++;
}
