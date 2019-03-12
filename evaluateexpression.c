#include <stdio.h>
#include <stdlib.h>
#include "evaluateexpression.h"
#include "linkstack.h"
#include "sqstack.h"
#define TRUE 1
#define FALSE 0
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
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}
char EvaluateExpression()
{
    sqstack OPND;
    LinkStack OPTR;
    InitSqStack(&OPND);
    InitLinkStack(&OPTR);
    SElemType e = {'#'}, theta;
    int n;
    ElemType t, a, b;
    PushLinkStack(&OPTR, e);
    e.ch = getchar();
    while(e.ch != '#' || GetTopLinkStack(OPTR).ch != '#')
    {
        if(!In(e.ch))
        {
            ungetc(e.ch, stdin);
            scanf("%d", &n);
            t.num = n;
            PushLinkStack(&OPND, t);
            printf("Push OPND\n");
            e.ch = getchar();
        }
        else
            switch(Precede(GetTopLinkStack(OPTR).ch, e.ch))
            {
                case '<':
                    PushLinkStack(&OPTR, e);
                    printf("Push OPTR\n");
                    e.ch = getchar();
                    break;
                case '>':
                    PopLinkStack(&OPTR, &theta);
                    printf("Pop OPTR\n");
                    PopLinkStack(&OPND, &a);
                    printf("Pop OPND\n");
                    PopLinkStack(&OPND, &b);
                    printf("Pop OPND\n");
                    e.ch = Operate(a.ch, theta.ch, b.ch);
                    printf("ans = %c\n", e.ch);
                    PushLinkStack(&OPND, e);
                    printf("Push OPND\n");
                    break;
                case '=':
                    PopLinkStack(&OPTR, &e);
                    printf("Pop OPTR");
                    e.ch = getchar();
                    break;
            }
        //printf("%c\n", e.ch);
        //printf("%c\n", GetTopLinkStack(OPTR).ch);
    }
    printf("test\n");
    printf("%c\n", GetTopLinkStack(OPND).ch);
    return GetTopLinkStack(OPND).ch;
}
