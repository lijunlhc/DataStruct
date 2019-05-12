#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct CSNode {
	char data;
	struct CSNode *firstchild;
	struct CSNode *nextsibling;
} CSNode, *CSTree; 

Status CreateTree_CS(FILE *fp, CSTree *T) {
	char ch;

	fscanf(fp, "%c", &ch);
	if(ch == '#')
		*T = NULL;
	else {
		*T = (CSTree)malloc(sizeof(CSNode));
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateTree_CS(fp, &(*T)->firstchild);
		CreateTree_CS(fp, &(*T)->nextsibling);
	}

	return OK;
}

void PreOrderTraverse_CS(CSTree T) {
	if(T) {
		printf("%c ", T->data);
		PreOrderTraverse_CS(T->firstchild);
		PreOrderTraverse_CS(T->nextsibling);
	}
}

void LevelOrderTraverse_CS(CSTree T) {
	int i, j;
	CSTree Q[100];

	i = j = 0;
	if(T)
		Q[j++] = T;
	while(i < j) {
		while(Q[i]) {
			printf("%c ", Q[i]->data);
			if(Q[i]->firstchild)
				Q[j++] = Q[i]->firstchild;
			Q[i] = Q[i]->nextsibling;
		}
		i++;
	}
}

void LevelOrderTraverse_CS_Upper(CSTree T) {
    int i, j;
    CSTree Q[100];

    i = j = 0;
    if(T)
        Q[j++] = T;
    while(i < j) {
        while(Q[i]) {
			if(Q[i]->data > 'A' && Q[i]->data < 'Z')
            	printf("%c ", Q[i]->data);
            if(Q[i]->firstchild)
                Q[j++] = Q[i]->firstchild;
            Q[i] = Q[i]->nextsibling;
        }
        i++;
    }
}

int main() {
    CSTree T;
    FILE *fp;

    fp = fopen("input.dat", "r");
    CreateTree_CS(fp, &T);
    fclose(fp);

    printf("层次遍历是:\n");
    LevelOrderTraverse_CS(T);
	printf("\n");

    printf("先根遍历是:\n");
    PreOrderTraverse_CS(T);
    printf("\n");

	return 0;
}
