#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define MAXSIZE 100

typedef struct {
	int *base;
	int *top;
	int stacksize;
} SqStackNum;

Status InitSqStackNum(SqStackNum *S) {
	S->base = (int *) malloc(sizeof(int) * MAXSIZE);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}

Status SqStackNumEmpty(SqStackNum S) {
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

int StackNumLength(SqStackNum S) {
	return S.top - S.base;
}

Status ClearStackNum(SqStackNum *S) {
	if(S->base)
		S->top = S->base;
	return OK;
}

Status DestroyStackNum(SqStackNum *S) {
	if(S->base) {
		free(S->base);
		S->stacksize = 0;
		S->base = S->top = NULL;
	}
	return OK;
}

Status PushSqStackNum(SqStackNum *S, int e) {
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top++ = e;
	return OK;
}
Status PopSqStackNum(SqStackNum *S, int *e) {
	if (S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}
int GetTopSqStackNum(SqStackNum S) {
	return *(S.top - 1);
}

typedef struct {
	char *base;
	char *top;
	int stacksize;
} SqStackChar;

Status InitSqStackChar(SqStackChar *S) {
	S->base = (char *) malloc(sizeof(char) * MAXSIZE);
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}

Status SqStackCharEmpty(SqStackChar S) {
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

int StackCharLength(SqStackChar S) {
	return S.top - S.base;
}

Status ClearStackChar(SqStackChar *S) {
	if(S->base)
		S->top = S->base;
	return OK;
}

Status DestroyStackChar(SqStackChar *S) {
	if(S->base) {
		free(S->base);
		S->stacksize = 0;
		S->base = S->top = NULL;
	}
	return OK;
}

Status PushSqStackChar(SqStackChar *S, char e) {
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top++ = e;
	return OK;
}
Status PopSqStackChar(SqStackChar *S, char *e) {
	if (S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}
char GetTopSqStackChar(SqStackChar S) {
	return *(S.top - 1);
}

int In(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':
            return TRUE;
        default:
            return FALSE;
    }
}

char Precede(char TOPTR, char NOPTR)
{
    switch(TOPTR)
    {
        case '+':
            switch(NOPTR)
            {
                case '+':
                    return '>';
                    break;
                case '-':
                    return '>';
                    break;
                case '*':
                    return '<';
                    break;
                case '/':
                    return '<';
                    break;
                case '(':
                    return '<';
                    break;
                case ')':
                    return '>';
                    break;
                case '#':
                    return '>';
                    break;
            }
            break;
        case '-':
            switch(NOPTR)
            {
                case '+':
                    return '>';
                    break;
                case '-':
                    return '>';
                    break;
                case '*':
                    return '<';
                    break;
                case '/':
                    return '<';
                    break;
                case '(':
                    return '<';
                    break;
                case ')':
                    return '>';
                    break;
                case '#':
                    return '>';
                    break;
            }
            break;
        case '*':
            switch(NOPTR)
            {
                case '+':
                    return '>';
                    break;
                case '-':
                    return '>';
                    break;
                case '*':
                    return '>';
                    break;
                case '/':
                    return '>';
                    break;
                case '(':
                    return '<';
                    break;
                case ')':
                    return '>';
                    break;
                case '#':
                    return '>';
                    break;
            }
            break;
        case '/':
            switch(NOPTR)
            {
                case '+':
                    return '>';
                    break;
                case '-':
                    return '>';
                    break;
                case '*':
                    return '>';
                    break;
                case '/':
                    return '>';
                    break;
                case '(':
                    return '<';
                    break;
                case ')':
                    return '>';
                    break;
                case '#':
                    return '>';
                    break;
            }
            break;
        case '(':
            switch(NOPTR)
            {
                case '+':
                    return '<';
                    break;
                case '-':
                    return '<';
                    break;
                case '*':
                    return '<';
                    break;
                case '/':
                    return '<';
                    break;
                case '(':
                    return '<';
                    break;
                case ')':
                    return '=';
                    break;
                case '#':
                    break;
            }
            break;
        case ')':
            switch(NOPTR)
            {
                case '+':
                    return '>';
                    break;
                case '-':
                    return '>';
                    break;
                case '*':
                    return '>';
                    break;
                case '/':
                    return '>';
                    break;
                case '(':
                    break;
                case ')':
                    return '>';
                    break;
                case '#':
                    return '>';
                    break;
            }
            break;
        case '#':
            switch(NOPTR)
            {
                case '+':
                    return '<';
                    break;
                case '-':
                    return '<';
                    break;
                case '*':
                    return '<';
                    break;
                case '/':
                    return '<';
                    break;
                case '(':
                    return '<';
                    break;
                case ')':
                    break;
                case '#':
                    return '=';
                    break;
            }
            break;
    }
}

int Operate(int a, char theta, int b)
{
    switch(theta)
    {
        case '+': 
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
    }
}

int EvaluateExpression()
{
    SqStackNum OPND;
    SqStackChar OPTR;
    char e, theta;
    int t, a, b;

    InitSqStackNum(&OPND);
    InitSqStackChar(&OPTR);
    
    PushSqStackChar(&OPTR, e = getchar());
    e = getchar();
    while(e != '#' || GetTopSqStackChar(OPTR) != '#')
    {
        if(!In(e))
        {
            ungetc(e, stdin);
            scanf("%d", &t);
            PushSqStackNum(&OPND, t);
            e = getchar();
        }
        else
            switch(Precede(GetTopSqStackChar(OPTR), e))
            {
                case '<':
                    PushSqStackChar(&OPTR, e);
                    e = getchar();
                    break;
                case '>':
                    PopSqStackChar(&OPTR, &theta);
                    PopSqStackNum(&OPND, &b);
                    PopSqStackNum(&OPND, &a);
                    t = Operate(a, theta, b);
                    PushSqStackNum(&OPND, t);
                    break;
                case '=':
                    PopSqStackChar(&OPTR, &e);
                    e = getchar();
                    break;
            }
    }
    t = GetTopSqStackNum(OPND);
    return t;
}

int main() {
    int ans;
    ans = EvaluateExpression();
    printf("ans = %d\n", ans);
    return 0;
}