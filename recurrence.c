/*
 * test.c
 *
 *  Created on: 2019年4月15日
 *      Author: junli
 */
#include <stdio.h>

int sum = 0;
int X(int n) {
	sum++;
	if (n <= 3)
		return 1;
	else
		return X(n - 2) + X(n - 4) + 1;
}

int c = 0;
void move(char x, int n, char z) {
	printf("%d, %d, %c, %c\n", ++c, n, x, z);
}

void Hanoi(int n, char A, char B, char C) {
	if (n == 1)
		move(A, 1, C);
	else {
		Hanoi(n - 1, A, C, B);
		move(A, n, C);
		Hanoi(n - 1, B, A, C);
	}
}

int main() {
	/*printf("%d\n", X(X(8)));
	 printf("sum = %d\n", sum);*/
	Hanoi(3, 'a', 'b', 'c');
	return 0;
}
