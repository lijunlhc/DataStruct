#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define MAXSIZE 100

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct {
	BiTNode *base;
	BiTNode *top;
	int stacksize;
} SqStackNum;

void CreateExpTree(BiTree *T, BiTree opand1, BiTree opand2, int optr) {
    *T = (BiTNode *)malloc(sizeof(BiTNode));

    (*T)->data = optr;
    (*T)->lchild = opand1;
    (*T)->rchild = opand2;
}

Status InitSqStackNum(SqStackNum *S) {
	S->base = (BiTNode *) malloc(sizeof(BiTNode) * MAXSIZE);
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

Status PushSqStackNum(SqStackNum *S, BiTNode e) {
	if (S->top - S->base == S->stacksize)
		return ERROR;
	*S->top++ = e;
	return OK;
}
Status PopSqStackNum(SqStackNum *S, BiTNode *e) {
	if (S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}
BiTNode GetTopSqStackNum(SqStackNum S) {
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

void InitExpTree()
{
    SqStackNum EXPT;
    SqStackChar OPTR;
    char e, theta;
    BiTNode t, a, b;

    InitSqStackNum(&EXPT);
    InitSqStackChar(&OPTR);
    
    PushSqStackChar(&OPTR, e = getchar());
    e = getchar();
    while(e != '#' || GetTopSqStackChar(OPTR) != '#')
    {
        if(!In(e))
        {
            BiTNode T;
            CreateExpTree(&T, NULL, NULL, e);
            PushSqStackNum(&EXPT, T);
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
                    PopSqStackNum(&EXPT, &b);
                    PopSqStackNum(&EXPT, &a);
                    BiTNode T;
                    CreateExpTree(&T, &a, &b, theta);
                    PushSqStackNum(&EXPT, T);
                    break;
                case '=':
                    PopSqStackChar(&OPTR, &e);
                    e = getchar();
                    break;
            }
    }
}

int main() {
    printf("Hello\n");
    return 0;
}