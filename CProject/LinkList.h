/*
 * LinkList.h
 *
 *  Created on: 2019年3月5日
 *      Author: junli
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct {
	float coef;
	int expn;
} ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;
Status InitList(LinkList L);
Status GetElem(LinkList L, int i, ElemType *e);
LNode *LocateElem(LinkList L, ElemType e);
Status ListInsert(LinkList L, int i, ElemType e);
Status ListDelete(LinkList L, int i);
void CreateList_H(LinkList L, int n);
void CreateList_R(LinkList L, int n);

#endif /* LINKLIST_H_ */
