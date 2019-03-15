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
void BInsertSort(SqList *L);
void ShellInsert(SqList *L, int dk);
void ShellSort(SqList *L, int dt[], int t);
void BubbleSort(SqList *L);
int Partition(SqList *L, int low, int high);
void QSort(SqList *L, int low, int high);
void QuickSort(SqList *L);
void SelectSort(SqList *L);
#endif