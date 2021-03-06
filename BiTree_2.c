#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct {
    char ch;
} ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->lchild);
        printf("%c", T->data.ch);
        InOrderTraverse(T->rchild);
    }
}

void PreOrderTraverse(BiTree T) {
    if(T) {
        printf("%c", T->data.ch);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T) {
    if(T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c", T->data.ch);
    }
}

int NodeCount(BiTree T) {
    if(T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

void Copy(BiTree T, BiTree *NewT) {
    if(T == NULL) {
        *NewT = NULL;
        return;
    } else {
        *NewT = (BiTNode *)malloc(sizeof(BiTNode));
        (*NewT)->data = T->data;
        Copy(T->lchild, &(*NewT)->lchild);
        Copy(T->rchild, &(*NewT)->rchild);
    }
}

int Depth(BiTree T) {
    int m;
    int n;
    if(T == NULL)
        return 0;
    else {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if(m > n)
            return m + 1;
        else
            return n + 1;
    }
}

void CreateBiTree(BiTree *T, FILE *fp) {
    char ch;
    fscanf(fp, "%c", &ch);
    if(ch == '#')
        *T = NULL;
    else {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data.ch = ch;
        CreateBiTree(&(*T)->lchild, fp);
        CreateBiTree(&(*T)->rchild, fp);
    }
}

int LeafCount(BiTree T) {
    if(T == NULL)
        return 0;
    if(T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int main() {
    BiTree T;
    FILE *fp;
    fp = fopen("bitree_file.txt", "r");
	CreateBiTree(&T, fp);
    fclose(fp);
	InOrderTraverse(T);
	printf("\n");
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	return 0;
}
