/*
 * Polynomial.c
 *
 *  Created on: 2019年3月5日
 *      Author: junli
 */
#include <stdlib.h>
#include "Polynomial.h"
Status InitList(SqList *L) {
	L->elem = (Polynomial *) malloc(sizeof(Polynomial) * MAXSIZE);
	if (!(L->elem))
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}
Status GetElem(SqList L, int i, Polynomial *e) {
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem + i - 1;
	return OK;
}
int LocateElem(SqList L, Polynomial e) {
	for (int i = 0; i < L.length; i++)
		if ((L.elem->coef == e.coef) && (L.elem->expn == e.expn))
			return i + 1;
	return 0;
}
Status ListInsert(SqList *L, int i, Polynomial e) {
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
Status ListDelete(SqList *L, int i) {
	if ((i < 1) || (i > L->length))
		return ERROR;
	for (int j = i; j <= L->length - 1; j++)
		L->elem[j - 1] = L->elem[j];
	--(L->length);
	return OK;
}
