/*
 * Book.c
 *
 *  Created on: 2019年3月5日
 *      Author: junli
 */

//#define MAXSIZE 10000
typedef struct {
	char no[20];
	char name[50];
	float price;
} Book;
typedef struct {
	Book *elem;
	int length;
} SqList;
