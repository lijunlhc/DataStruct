#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef struct {
	char *base;
	char *top;
	int stacksize;
} SqStack;

Status InitSqStack(SqStack *S) {
	S->base = (char *) malloc(sizeof(char) * MAXSIZE);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}

Status SqStackEmpty(SqStack S) {
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

Status PushSqStack(SqStack *S, char e) {
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top++ = e;
	return OK;
}
Status PopSqStack(SqStack *S, char *e) {
	if (S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}

char GetTopSqStack(SqStack S) {
	if (S.top == S.base)
		exit(OVERFLOW);
	else
		return *(S.top - 1);
}

Status matching(char *str) 
{
	SqStack S;
	int flag = 1;
	char e;

	InitSqStack(&S);

	while (*str) 
	{
		switch (*str) {
		case '(':
			PushSqStack(&S, *str);
			break;
		case ')':
			if (!SqStackEmpty(S) && GetTopSqStack(S) == '(') {
				PopSqStack(&S, &e);
			} 
            else
				flag = 0;
			break;
		}
		str++;
	}
	if (SqStackEmpty(S) && flag)
		return TRUE;
    else
		return FALSE;
}

void decode1(char *str) {
    SqStack S;
    char e;

    InitSqStack(&S);
    while(*str) {
        if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
            PushSqStack(&S, *str);
        str++;
    }
    while(!SqStackEmpty(S)) {
        PopSqStack(&S, &e);
        printf("%c", e);
    }
}

int main() {
    //char *str="((((NNNNNbbb)m)))";
    char *str1="&&&m++++88888o,,,,$$$$T55555555e99v88o883l&&&++++I0";
    // if(matching(str))
    //     printf("匹配成功\n");
    // else
    //     printf("匹配失败\n");

    decode1(str1);
    printf("\n");
    return(0);
}
