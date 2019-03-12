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
int EvaluateExpression()
{
    SqStack OPND;
    LinkStack OPTR;
    InitSqStack(&OPND);
    InitLinkStack(&OPTR);
    SElemType e = {'#'}, theta;
    ElemType t, a, b;
    PushLinkStack(&OPTR, e);
    e.ch = getchar();
    while(e.ch != '#' || GetTopLinkStack(OPTR).ch != '#')
    {
        if(!In(e.ch))
        {
            ungetc(e.ch, stdin);
            scanf("%d", &t.num);
            PushSqStack(&OPND, t);
            e.ch = getchar();
        }
        else
            switch(Precede(GetTopLinkStack(OPTR).ch, e.ch))
            {
                case '<':
                    PushLinkStack(&OPTR, e);
                    e.ch = getchar();
                    break;
                case '>':
                    PopLinkStack(&OPTR, &theta);
                    PopSqStack(&OPND, &b);
                    PopSqStack(&OPND, &a);
                    t.num = Operate(a.num, theta.ch, b.num);
                    PushSqStack(&OPND, t);
                    break;
                case '=':
                    PopLinkStack(&OPTR, &e);
                    e.ch = getchar();
                    break;
            }
    }
    GetTopSqStack(OPND, &t);
    return t.num;
}
