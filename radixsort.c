#include "radixsort.h"
void Distribute(SLCell *r, int i, ArrType *f, ArrType *e)
{
    for(int j = 0; j < RADIX; ++j)
        (*f)[j] = 0;
    for(int p = r[0].next; p; p = r[p].next)
    {
        int j = ord(r[p].keys[i]);
        if(!(*f)[j])
            (*f)[j] = p;
        else
            r[(*e)[j]].next = p;
        (*e)[j] = p;
    }
}
void Collect(SLCell *r, int i, ArrType f, ArrType e)
{
    int j;
    for(j = 0; !f[j]; j = succ(j));
    r[0].next = f[j];
    int t = e[j];
    while(j < RADIX)
    {
        for(j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j));
        if(f[j])
        {
            r[t].next = f[j];
            t = e[j];
        }
    }
    r[t].next = 0;
}
void RadixSort(SLList *L)
{
    for(int i = 0; i < L->recnum; ++i)
        L->r[i].next = i + 1;
    L->r[L->recnum].next = 0;
    ArrType f;
    ArrType e;
    for(int i = 0; i < L->keynum; ++i)
    {
        Distribute(L->r, i, &f, &e);
        Collect(L->r, i, f, e);
    }
}