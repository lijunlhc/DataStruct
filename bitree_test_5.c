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

void CPreOrderTraverse(BiTree T) {
	if(T) {
		if(T->data > 0) printf("->%d", T->data);
        	CPreOrderTraverse(T->lchild);
	        CPreOrderTraverse(T->rchild);
    }
}

void CreateBiTree(BiTree *T, FILE *fp) {
	int i;
	char c;
	int n;

	n = fscanf(fp, "%d", &i);
	if(n <= 0) {
		fscanf(fp, "%c", &c);
        	*T = NULL;
	}	
    	else {
        	*T = (BiTNode *)malloc(sizeof(BiTNode));
        	(*T)->data = i;
        	CreateBiTree(&(*T)->lchild, fp);
        	CreateBiTree(&(*T)->rchild, fp);
    	}
}

int main() {
    	BiTree T;
    	FILE *fp;

    	fp = fopen("input.txt", "r");
	CreateBiTree(&T, fp);
    	fclose(fp);

	//PreOrderTraverse(T);
	CPreOrderTraverse(T);
	printf("\n");
	return 0;
}
