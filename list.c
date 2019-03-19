/*
 * test.c
 *
 *  Created on: 2019年3月19日
 *      Author: junli
 */

typedef enum {ATOM, LIST} ElemTag;
typedef struct {} AtomType;
typedef struct GLNode
{
	ElemTag tag;
	union
	{
		AtomType atom;
		struct
		{
			struct GLNode *hp, *tp;
		} ptr;
	};
} *GList;
#include <stdio.h>
int main()
{
	printf("Hello World\n");
	return 0;
}
