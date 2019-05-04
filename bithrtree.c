#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct {} TElemType;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	int LTag, RTag;
} BiThrNode, *BiThrTree;

BiThrNode * pre;

void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);
		if(!p->lchild) {
			p->LTag = 1;
			p->lchild = pre;
		}
		else 
			p->LTag = 0;
		if(!pre->rchild) {
			pre->RTag = 1;
			pre->rchild = p;
		}
		else 
			pre->RTag = 0;
		pre = p;
		InThreading(p->rchild);
	}
}

void InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	*Thrt = (BiThrNode *)malloc(sizeof(BiThrNode));
	(*Thrt)->LTag = 0;
	(*Thrt)->RTag = 1;
	(*Thrt)->rchild = *Thrt;
	if(!T)
		(*Thrt)->lchild = *Thrt;
	else {
		(*Thrt)->lchild = T;
		pre = *Thrt;
		InThreading(T);
		pre->rchild = *Thrt;
		pre->RTag = 1;
		(*Thrt)->rchild = pre;
	}
}

void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrNode *p = T->lchild;
    while(p != T)
    {
        while(p->LTag == 0)
            p = p->lchild;
        printf("%c", p->data);
        while(p->RTag == 1 && p->rchild != T)
        {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}

int main()
{
	printf("Hello\n");
	return 0;
}
