#ifndef RADIXSORT_H_
#define RADIXSORT_H_
#define MAXNUM_KEY 8
#define RADIX 10
#define MAX_SPACE 10000
#define ord(ch) ((ch)-'0')
#define succ(x) ((x)+1)
typedef int KeyType;
typedef struct 
{

} InfoType;
typedef struct
{
    KeyType keys[MAXNUM_KEY];
    InfoType otheritems;
    int next;
} SLCell;`
typedef struct 
{
    SLCell r[MAX_SPACE];
    int keynum;
    int recnum;
} SLList;
typedef int ArrType[RADIX];
void Distribute(SLCell *r, int i, ArrType *f, ArrType *e);
void Collect(SLCell *r, int i, ArrType f, ArrType e);
void RadixSort(SLList *L);
#endif

