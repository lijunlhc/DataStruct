/*
 * DuLinkList.c
 *
 *  Created on: 2019年3月6日
 *      Author: junli
 */
#include <stdlib.h>
#include "DuLinkList.h"
Status InitDuList(DuLinkList L) {
	L = (DuLNode *) malloc(sizeof(DuLNode));
	L->next = NULL;
	L->prior = NULL;
	return OK;
}
DuLNode * GetElem_DuL(DuLinkList L, int i, ElemType *e) {
	DuLNode *p = L->next;
	int j = 1;
	while (p && (j < i)) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return NULL;
	*e = p->data;
	return p;
}
DuLNode *LocateElem_DuL(DuLinkList L, ElemType e) {
	DuLNode * p = L->next;
	while (p && (p->data.coef != e.coef || p->data.expn != e.expn))
		p = p->next;
	return p;
}
Status ListInsert_DuL(DuLinkList L, int i, ElemType e) {
	ElemType e_tmp;
	DuLNode *p;
	if (!(p = GetElem_DuL(L, i, &e_tmp)))
		return ERROR;
	DuLNode *s = (DuLNode *) malloc(sizeof(DuLNode));
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
Status ListDelete_Dul(DuLinkList L, int i) {
	ElemType e_tmp;
	DuLNode *p;
	if (!(p = GetElem_DuL(L, i, &e_tmp)))
		return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}
