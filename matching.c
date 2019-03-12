/*
 * matching.c
 *
 *  Created on: 2019年3月11日
 *      Author: junli
 */

#include <stdio.h>
#include "matching.h"
#include "linkstack.h"
Status Matching() {
	LinkStack S;
	InitLinkStack(&S);
	int flag = 1;
	char c;
    printf("Please enter a character: ");
	scanf("%c", &c);
	SElemType e = {c};
	while(e.ch != '#' && flag) {
		switch(e.ch) {
		case '[':
		case '(':
			PushLinkStack(&S, e);
            printf("Push\n");
			break;
		case ')':
			if(!LinkStackEmpty(S) && GetTopLinkStack(S).ch == '(')
            {

				PopLinkStack(&S, &e);
                printf("Pop\n");
            }
			else
				flag = 0;
			break;
		case ']':
			if(!LinkStackEmpty(S) && GetTopLinkStack(S).ch == '[')
            {
				PopLinkStack(&S, &e);
                printf("Pop\n");
            }
			else
				flag = 0;
			break;
		}
        //printf("Please enter a character: ");
		scanf("%c", &c);
        e.ch = c;
	}
	if(LinkStackEmpty(S) && flag)
    {
        printf("TRUE\n");
		return TRUE;
    }
	else
    {
        printf("FALSE\n");
		return FALSE;
    }

}
