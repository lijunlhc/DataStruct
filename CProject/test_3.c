/*
 * test_3.c
 *
 *  Created on: 2019年3月8日
 *      Author: junli
 */

#include <stdio.h>
#include "LinkList.h"
int main() {
	LinkList LA;
	InitList(&LA);
	printf("Initialize LA\n");
	CreateList_R(&LA, 4);
	LinkList LB;
	InitList(&LB);
	printf("Initialize LB\n");
	CreateList_R(&LB, 7);
	LinkList LC;
	InitList(&LC);
	MergeList_Link_Ord(&LA, &LB, &LC);
	ElemType e;
	for(int i = 1; i <=11; ++i) {
		GetElem(LC, i, &e);
		printf("%d ", e.num);
	}
	return 0;
}
