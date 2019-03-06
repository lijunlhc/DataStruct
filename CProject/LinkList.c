/*
 * LinkList.c
 *
 *  Created on: 2019年3月5日
 *      Author: junli
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
Status InitList(LinkList L) {
	L = (LNode *) malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}
Status GetElem(LinkList L, int i, ElemType *e) {
	LNode *p = L->next;
	int j = 1;
	while (p && (j < i)) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}
LNode *LocateElem(LinkList L, ElemType e) {
	LNode * p = L->next;
	while (p && (p->data.coef != e.coef || p->data.expn != e.expn))
		p = p->next;
	return p;
}
Status ListInsert(LinkList L, int i, ElemType e) {
	LNode *p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode s;
	s.data = e;
	s.next = p->next;
	p->next = &s;
	return OK;
}
Status ListDelete(LinkList L, int i) {
	LNode *p = L;
	int j = 0;
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))
		return ERROR;
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}
void CreateList_H(LinkList L, int n) {
	L = (LNode *) malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < n; ++i) {
		LNode *p = (LNode *) malloc(sizeof(LNode));
		scanf("%f%d", &p->data.coef, &p->data.expn);
		p->next = L->next;
		L->next = p;
	}
}
void CreateList_R(LinkList L, int n) {
	L = (LNode *) malloc(sizeof(LNode));
	L->next = NULL;
	LNode *r = L;
	for (int i = 0; i < n; ++i) {
		LNode *p = (LNode *) malloc(sizeof(LNode));
		scanf("%f%d", &p->data.coef, &p->data.expn);
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
