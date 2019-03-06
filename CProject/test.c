#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
int main() {
	LinkList list = (LNode *)malloc(sizeof(LNode));
	CreateList_H(list, 2);
	return 0;
}
