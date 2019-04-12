#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define MAXSIZE 100

typedef struct {
	int *elem;
	int length;
} SqList;

Status InitList_Sq(SqList *L) {
	L->elem = (int *) malloc(sizeof(int) * MAXSIZE);
	if (!(L->elem))
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}

Status ListInsert_Sq(SqList *L, int i, int e) {
	if ((i < 1) || (i > L->length + 1)) {
		printf("位置不合法\n");
		return ERROR;
	}
	if (L->length == MAXSIZE) {
		printf("顺序表已满");
		return ERROR;
	}
	for (int j = L->length - 1; j >= i - 1; j--)
		L->elem[j + 1] = L->elem[j];
	L->elem[i - 1] = e;
	++(L->length);
	return OK;
}

Status ListInsert_Sq_n(SqList *L, int i, int e, int n) {
	for (int j = 0; j < n; j++)
		ListInsert_Sq(L, i, e);
	return OK;
}

void display(SqList L) {
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
}

int main() {
	SqList L;
	InitList_Sq(&L);
	for (int i = 0; i < 10; i++)
		ListInsert_Sq(&L, L.length + 1, i);
	ListInsert_Sq(&L, 5, 100);
	ListInsert_Sq_n(&L, 5, 200, 5);
	display(L);
	return 0;
}
