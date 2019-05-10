#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

void PreOrderTraverse(BiTree T) {
    if(T) {
        printf("->%d", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void CreateBiTree(BiTree *T, FILE *fp) {
    int n;
    fscanf(fp, "%d", &n);
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
