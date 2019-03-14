#ifndef SORT_H_
#define SORT_H_
#define MAXSIZE 20
typedef int KeyType;
typedef struct {

} InfoType;
typedef struct {
    KeyType key;
    InfoType otherinfo;
} RedType;
typedef struct {
    RedType r[MAXSIZE + 1];
    int length;
} SqList;
void InsertSort(SqList *L);
#endif