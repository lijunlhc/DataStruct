/*
 * LinkList.c
 *
 *  Created on: 2019年3月5日
 *      Author: junli
 */
#include <stdlib.h>
#include "LinkList.h"
Status InitList(LinkList L) {
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}
