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
	scanf("%c", &c);
	SElemType e = {c};
	while(c != '#' && flag) {
		switch(c) {
		case '[':
		case '(':
			PushLinkStack(&S, e);
			break;
		case ')':
			if(!LinkStackEmpty(S) && GetTopLinkStack(S).ch == '(')
				PopLinkStack(&S, &e);
			else
				flag = 0;
			break;
		case ']':
			if(!LinkStackEmpty(S) && GetTopLinkStack(S).ch == '[')
				PopLinkStack(&S, &e);
			else
				flag = 0;
			break;
		}
		scanf("%c", &c);
		if(LinkStackEmpty(S) && flag)
			return TRUE;
		else
			return FALSE;
	}
}
