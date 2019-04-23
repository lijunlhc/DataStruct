#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct {
    int num;
} ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList *L) 
{
    (*L) = (LNode *) malloc(sizeof(LNode));
    (*L)->next = NULL;
    return OK;
}

int CountElem(LinkList L, ElemType e) 
{
    LNode * p = L->next;
    int n = 0;
    while (p)
    {
        if(p->data.num == e.num)
            n++;
        p = p->next;
    }
    return n;
}

int ListDelete(LinkList *L, ElemType e)
{
    LNode *p = *L, *pre;
    int count = 0;
    while(p->next)
    {
        pre = p;
        p = p->next;
        if(p->data.num == e.num)
        {
            pre->next = p->next;
            free(p);
            p = pre;
            count++;
        }
    }
    return count;
}

void display(LinkList L)
{
    LNode *p = L->next;
    while(p)
    {
        printf("%s: %p\t%s: %d\t%s: %p\n", "存储地址", p, "数据域", p->data.num, "地址域", p->next);
        p = p->next;
    }
}

int main()
{
    int a[10] = {3,3,5,7,8,3,0,-5,3,3};
    LinkList L;
    InitList(&L);
    LNode *p, *q;
    p = L;
    for(int i = 0; i < 10; i++)
    {
        q = (LNode *)malloc(sizeof(LNode));
        q->data.num = a[i];
        q->next = NULL;
        p->next = q;
        p = p->next;
    }
    display(L);
    printf("%d\n", ListDelete(&L, (ElemType){-5}));
    display(L);
    //printf("总共有%d个3\n", CountElem(L, (ElemType){3}));
    return 0;
}
