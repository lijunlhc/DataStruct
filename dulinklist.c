/*
 * DuLinkList.c
 *
 *  Created on: 2019年3月6日
 *      Author: junli
 */
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct {
	int num;
} ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, *DuLinkList;

Status InitDuList(DuLinkList *L) {
	*L = (DuLNode *) malloc(sizeof(DuLNode));
	(*L)->next = *L;
	(*L)->prior = *L;
	return OK;
}

Status ClearList_DuL(DuLinkList *L) {
	DuLNode *p, *q;
	p = (*L)->next;
	
	while(p != *L) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = (*L)->prior = *L;
	return OK;
}

void DestroyList_Dul(DuLinkList *L) {
	ClearList_DuL(L);
	free(*L);
	*L = NULL;
}

Status ListEmpty_Dul(DuLinkList L) {
	if(L && L->next == L && L->prior == L)
		return 1;
	else
		return 0;
}

int ListLength_DuL(DuLinkList L) {
	DuLNode *p;
	int count;

	if(L) {
		count = 0;
		p = L;
		while(p->next != L) {
			count++;
			p = p->next;
		}
	}
	return count;
}

DuLNode * GetElem_DuL(DuLinkList L, int i, ElemType *e) {
	DuLNode *p = L->next;
	int j = 1;
	while ((p != L) && (j < i)) {
		p = p->next;
		++j;
	}
	if (p == L || j > i)
		return NULL;
	*e = p->data;
	return p;
}

DuLNode *LocateElem_DuL(DuLinkList L, ElemType e) {
	DuLNode * p = L->next;
	while (p != L && (p->data.num != e.num))
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

int main() {
	printf("Hello\n");
	return 0;
}