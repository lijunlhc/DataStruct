#include <stdio.h>
#include "sort.h"
int main()
{
    SqList L;
    L.length = 10;
    for(int i = 1; i <= L.length; ++i)
        L.r[i].key = L.length - i + 1;
    for(int i = 1; i <= L.length; ++i)
        printf("%d ", L.r[i].key);
    printf("\n");
    InsertSort(&L);
    for(int i = 1; i <= L.length; ++i)
        printf("%d ", L.r[i].key);
    printf("\n");
    return 0;
}

