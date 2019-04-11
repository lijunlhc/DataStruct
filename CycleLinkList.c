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

void CreateList_R(LinkList *L, int n) {
	*L = (LNode *) malloc(sizeof(LNode));
	(*L)->next = *L;
	LNode *r = *L;
	for (int i = 0; i < n; ++i) {
		LNode *p = (LNode *) malloc(sizeof(LNode));
		p->data.num = i + 1;
		p->next = r->next;
		r->next = p;
		r = p;
	}
	LNode *t = r->next;
	r->next = r->next->next;
	*L = r->next;
	free(t);
}

void Josephus(LinkList *L, int n, int m) {
	LNode *cur = *L;
	LNode *pre;
	LNode *t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m - 1; j++) {
			pre = cur;
			cur = cur->next;
		}
		printf("%d ", cur->data.num);
		t = cur;
		pre->next = cur->next;
		cur = cur->next;
		free(t);
	}
}

int main() {
	LinkList L;
	CreateList_R(&L, 41);
	Josephus(&L, 41, 3);
    printf("\n");
	return 0;
}
