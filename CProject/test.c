#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"
int main() {
	SqList LA;
	SqList LB;
	InitList_SqL(&LA);
	InitList_SqL(&LB);
	ElemType e = {7};
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 5;
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 3;
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 11;
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 2;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 6;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 3;
	ListInsert_SqL(&LB, LB.length + 1, e);
	MergeList_SqL(&LA, LB);
	for(int i = 0; i < LA.length; ++i)
		printf("%d\n", LA.elem[i].num);
	return 0;
}
