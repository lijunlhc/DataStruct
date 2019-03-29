#include <stdio.h>
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct
{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
} AMGraph;

int main()
{
	printf("Hello World\n");
	return 0;
}
