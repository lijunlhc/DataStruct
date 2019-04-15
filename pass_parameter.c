#include <stdio.h>
#include <string.h>

#define N 10

void swap1(float m, float n) {
	float temp;
	temp = m;
	m = n;
	n = temp;
}

void swap2(float *m, float *n) {
	float t;
	t = *m;
	*m = *n;
	*n = t;
}

void swap3(float *m, float *n) {
	float *t;
	t = m;
	m = n;
	n = t;
}

void sub(char b[]) {
	strcpy(b, "world");
}

int max(int b[]) {
	int i, n;
	n = b[0];
	for(i = 1; i < N; i++)
		if(n < b[i])
			n = b[i];
	return n;
}

void sub2(int b[]) {
	int i, j, temp, m;
	m = N / 2;
	for(i = 0; i < m; i++) {
		j = N - 1 - i;
		temp = b[i];
		b[i] = b[j];
		b[j] = temp;
	}
}

int main() {
	/*float a, b;
	 scanf("%f%f", &a, &b);
	 swap1(a, b);
	 printf("%f %f\n", a, b);*/
	/*float a, b, *p1, *p2;
	 scanf("%f%f", &a, &b);
	 p1 = &a;
	 p2 = &b;
	 swap2(p1, p2);
	 printf("%f %f\n", a, b);*/
	/*float a, b, *p1, *p2;
	 scanf("%f%f", &a, &b);
	 p1 = &a;
	 p2 = &b;
	 swap3(p1, p2);
	 printf("%f %f\n", a, b);*/
	/*char a[10]="hello";
	sub(a);
	printf("%s\n", a);*/
	/*int a[10];
	int i, m;
	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);
	m = max(a);
	printf("the max number is: %d\n", m);*/
	/*int a[10], i;
	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sub2(a);
	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");*/
	return 0;
}
