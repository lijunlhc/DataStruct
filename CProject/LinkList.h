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

} ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
Status InitList(LinkList L);

#endif /* LINKLIST_H_ */
