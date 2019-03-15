#include <stdio.h>
#include "sort.h"
int main()
{
    SqList L;
    L.length = 19;
    for(int i = 1; i <= L.length; ++i)
        L.r[i].key = L.length - i + 1;
    for(int i = 1; i <= L.length; ++i)
        printf("%d ", L.r[i].key);
    printf("\n");
    SelectSort(&L);
    for(int i = 1; i <= L.length; ++i)
        printf("%d ", L.r[i].key);
    printf("\n");
    return 0;
}

