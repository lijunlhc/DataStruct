#include <stdio.h>
#include <stdlib.h>

typedef struct PNode {
	float coef;
	int expn;
	struct PNode *next;
} PNode, *Polynomial;

void CreatePolyn(Polynomial *P, int n) {
	*P = (PNode *)malloc(sizeof(PNode));
	(*P)->next = NULL;
	for(int i = 1; i <= n; ++i) {
		PNode *s = (PNode *)malloc(sizeof(PNode));
		scanf("%f%d", &(s->coef), &(s->expn));
		PNode *pre = *P;
		PNode *q = (*P)->next;
		while(q && q->expn < s->expn) {
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}

void AddPolyn(Polynomial *Pa, Polynomial *Pb) {
	PNode *p1 = (*Pa)->next;
	PNode *p2 = (*Pb)->next;
	PNode *p3 = *Pa;
	while(p1 && p2) {
		if(p1->expn == p2->expn) {
			float sum = p1->coef + p2->coef;
			if(sum != 0) {
				p1->coef = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				PNode *r = p2;
				p2 = p2->next;
				free(r);
			} 
            else {
				PNode *r = p1;
				p1 = p1->next;
				free(r);
				r = p2;
				p2 = p2->next;
				free(r);
			}
		} 
        else if(p1->expn < p2->expn) {
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		} 
        else {
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;
	free(*Pb);
}

int main() {
    Polynomial Pa, Pb;
    CreatePolyn(&Pa, 4);
    CreatePolyn(&Pb, 3);
    AddPolyn(&Pa, &Pb);
    PNode *p = Pa->next;
    while(p) {
        printf("%f %d\n", p->coef, p->expn);
        p = p->next;
    }
    return 0;
}
