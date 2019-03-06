/*
 * DuLinkList.h
 *
 *  Created on: 2019年3月6日
 *      Author: junli
 */

#ifndef DULINKLIST_H_
#define DULINKLIST_H_

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct {
	float coef;
	int expn;
} ElemType;
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;
Status InitDuList(DuLinkList L);
DuLNode * GetElem_DuL(DuLinkList L, int i, ElemType *e);
DuLNode *LocateElem_DuL(DuLinkList L, ElemType e);
Status ListInsert_DuL(DuLinkList L, int i, ElemType e);
Status ListDelete_Dul(DuLinkList L, int i);

#endif /* DULINKLIST_H_ */
