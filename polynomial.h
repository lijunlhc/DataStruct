/*
 * Polynomial.h
 *
 *  Created on: 2019年3月8日
 *      Author: junli
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

typedef struct PNode {
	float coef;
	int expn;
	struct PNode *next;
} PNode, *Polynomial;
void CreatePolyn(Polynomial *P, int n);
void AddPolyn(Polynomial *Pa, Polynomial *Pb);

#endif /* POLYNOMIAL_H_ */
