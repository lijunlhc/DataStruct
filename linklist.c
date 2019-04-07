#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct {
    int num;
} ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList_Link(LinkList *L) {
    (*L) = (LNode *) malloc(sizeof(LNode));
    (*L)->next = NULL;
    return OK;
}

Status DestroyList_Link(LinkList *L) {
    LinkList p;
    while(*L) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return OK;
}

Status ClearList_Link(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while(p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

int ListLength_Link(LinkList L) {
    LinkList p;
    p = L->next;
    int i = 0;
    while(p) {
        i++;
        p = p->next;
    }
    return i;
}

int ListEmpty_Link(LinkList L) {
    if(L->next)
        return 0;
    else
        return 1;
}

Status GetElem_Link(LinkList L, int i, ElemType *e) {
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

LNode *LocateElem_Link(LinkList L, ElemType e) {
    LNode * p = L->next;
    while (p && (p->data.num != e.num))
        p = p->next;
    return p;
}

Status ListInsert_Link(LinkList *L, int i, ElemType e) {
    LNode *p = *L;
    int j = 0;
    while (p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_Link(LinkList *L, int i) {
    LNode *p = *L;
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

void CreateList_H(LinkList *L, int n) {
    (*L) = (LNode *) malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int i = 0; i < n; ++i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        scanf("%d", &p->data.num);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateList_R(LinkList *L, int n) {
    (*L) = (LNode *) malloc(sizeof(LNode));
    (*L)->next = NULL;
    LNode *r = *L;
    for (int i = 0; i < n; ++i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        scanf("%d", &p->data.num);
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

void MergeList_Link_Ord(LinkList *LA, LinkList *LB, LinkList *LC) {
	LNode *pa = (*LA)->next;
	LNode *pb = (*LB)->next;
	(*LC) = (*LA);
	LNode *pc = *LC;
	while(pa && pb) {
		if(pa->data.num <= pb->data.num) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(*LB);
}

void TraverseList(LinkList p) {
	if(p) {
		TraverseList(p->next);
	}
}

int main() {
	LinkList LA, LB, LC;
	CreateList_R(&LA, 3);
	CreateList_R(&LB, 6);
	MergeList_Link_Ord(&LA, &LB, &LC);
	LNode *p = LC->next;
	while(p) {
		printf("%d ", p->data.num);
		p = p->next;
	}
	printf("\n");
	return 0;
}