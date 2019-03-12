#include <stdio.h>
#include "evaluateexpression.h"
#include "linkstack.h"
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

char Operate(char a, char theta, char b)
{
    switch(theta)
    {
        case '+': 
            printf("%d\n", a + b);
            return (char)((int)a + (int)b);
        case '-':
            return (char)((int)a - (int)b);
        case '*':
            return (char)((int)a * (int)b);
        case '/':
            return (char)((int)a / (int)b);
    }
}
char EvaluateExpression()
{
    LinkStack OPND;
    LinkStack OPTR;
    InitLinkStack(&OPND);
    InitLinkStack(&OPTR);
    SElemType e = {'#'};
    SElemType a, b, theta;
    PushLinkStack(&OPTR, e);
    e.ch = getchar();
    while(e.ch != '#' || GetTopLinkStack(OPTR).ch != '#')
    {
        if(!In(e.ch))
        {
            PushLinkStack(&OPND, e);
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
