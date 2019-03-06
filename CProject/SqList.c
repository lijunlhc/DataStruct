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
	e = L.elem + i - 1;
	return OK;
}
int LocateElem_SqL(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if ((L.elem->coef == e.coef) && (L.elem->expn == e.expn))
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
