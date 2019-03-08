/*
 * test_2.c
 *
 *  Created on: 2019年3月7日
 *      Author: junli
 */


#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"
int main() {
	SqList LA;
	SqList LB;
	SqList LC;
	InitList_SqL(&LA);
	InitList_SqL(&LB);
	InitList_SqL(&LC);
	ElemType e = {3};
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 5;
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 8;
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 11;
	ListInsert_SqL(&LA, LA.length + 1, e);
	e.num = 2;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 6;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 8;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 9;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 11;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 15;
	ListInsert_SqL(&LB, LB.length + 1, e);
	e.num = 20;
	ListInsert_SqL(&LB, LB.length + 1, e);
	MergeList_SqL_Ord(LA, LB, &LC);
	for(int i = 0; i < LC.length; ++i)
		printf("%d ", LC.elem[i].num);
	printf("\n");
	return 0;
}
