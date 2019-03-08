/*
 * test_4.c
 *
 *  Created on: 2019年3月8日
 *      Author: junli
 */

#include <stdio.h>
#include "Polynomial.h"
int main()
{
	Polynomial Pa;
	Polynomial Pb;
	CreatePolyn(&Pa, 4);
	CreatePolyn(&Pb, 3);
	AddPolyn(&Pa, &Pb);
	while(Pa) {
		printf("%f, %d\n", Pa->next->coef, Pa->next->expn);
		Pa = Pa->next;
	}
	return 0;
}
