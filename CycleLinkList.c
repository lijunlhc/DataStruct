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
	LNode *p = *L;
	LNode *pre;
	LNode *t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m - 1; j++) {
			pre = p;
			p = p->next;
		}
		printf("%d ", p->data.num);
		t = p;
		pre->next = p->next;
		p = p->next;
		free(t);
		//exit(0);
	}
}

/*void Josephus(int n, int m, LinkList L) {
	for (int i = 0; i < n - 1; i++) {     //执行n-1次
		for (int j = 0; j < m - 1; j++)
			Next();
		//循环m次使current指向被删除结点
		cout << “出列的人是 ” << GetElem_L() << endl;
		//出列人员的数据
		ListDelete();                    //删去每一趟的第m结点
	}*/

int main() {
	LinkList L;
	CreateList_R(&L, 41);
	//LNode *p = L;
	/*while(p->next != L) {
		printf("%d ", p->data.num);
		p = p->next;
	}
	printf("%d ", p->data.num);*/
	Josephus(&L, 41, 3);
	return 0;
}
