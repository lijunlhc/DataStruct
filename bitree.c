#include <stdio.h>
#include <stdlib.h>

//typedef struct {} TElemType;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
	}
}

void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		printf("%c", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
}

void CreateBiTree(BiTree *T)
{
	char ch;
	ch = getchar();
	if(ch == '#')
		(*T) = NULL;
	else
	{
		(*T) = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&((*T)->lchild));
		CreateBiTree(&((*T)->rchild));
	}
}

void Copy(BiTree T, BiTree *NewT)
{
	if(T == NULL)
	{
		*NewT = NULL;
		return;
	}
	else
	{
		*NewT = (BiTNode *)malloc(sizeof(BiTNode));
		(*NewT)->data = T->data;
		Copy(T->lchild, &((*NewT)->lchild));
		Copy(T->rchild, &((*NewT)->rchild));
	}
}

int Depth(BiTree T)
{
	if(T == NULL)
		return 0;
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if(m > n)
			return (m+1);
		else
			return (n+1);
	}
}

int NodeCount(BiTree T)
{
	if(T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int main()
{
	BiTree T;
	CreateBiTree(&T);
	InOrderTraverse(T);
	printf("\n");
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	return 0;
}
