#include "sort.h"
void InsertSort(SqList *L)
{
    int i;
    int j;
    for(i = 2; i <= (*L).length; ++i)
        if((*L).r[i].key < (*L).r[i-1].key)
        {
            (*L).r[0] = (*L).r[i];
            (*L).r[i] = (*L).r[i-1];
            for(j = i - 2; (*L).r[0].key < (*L).r[j].key; --j)
                (*L).r[j+1] = (*L).r[j];
            (*L).r[j+1] = (*L).r[0];
        }
}
void BInsertSort(SqList *L)
{
    for(int i = 2; i <= (*L).length; ++i)
    {
        (*L).r[0] = (*L).r[i];
        int low = 1;
        int high = i - 1;
        while(low <= high)
        {
            int m = (low + high) / 2;
            if((*L).r[0].key < (*L).r[m].key)
                high = m - 1;
            else
                low = m + 1;
        }
        int j;
        for(j = i - 1; j >= high + 1; --j)
            (*L).r[j+1] = (*L).r[j];
        (*L).r[high + 1] = (*L).r[0];
    }
}
void ShellInsert(SqList *L, int dk)
{
    for(int i = dk + 1; i <= (*L).length; ++i)
        if((*L).r[i].key < (*L).r[i - dk].key)
        {
            (*L).r[0] = (*L).r[i];
            int j;
            for(j = i - dk; j > 0 && (*L).r[0].key < (*L).r[j].key; j -= dk)
                (*L).r[j+dk] = (*L).r[j];
            (*L).r[j+dk] = (*L).r[0];
        }
}
void ShellSort(SqList *L, int dt[], int t)
{
    for(int k = 0; k < t; ++k)
        ShellInsert(&(*L), dt[k]);
}
void BubbleSort(SqList *L)
{
    int m = (*L).length - 1;
    int flag = 1;
    while((m > 0) && (flag == 1))
    {
        flag = 0;
        RedType t;
        for(int j = 1; j <= m; j++)
            if((*L).r[j].key > (*L).r[j+1].key)
            {
                flag = 1;
                t = (*L).r[j];
                (*L).r[j] = (*L).r[j+1];
                (*L).r[j+1] = t;
            }
        --m;
    }
}
int Partition(SqList *L, int low, int high)
{
    (*L).r[0] = (*L).r[low];
    KeyType pivotkey = (*L).r[low].key;
    while(low < high)
    {
        while(low < high && (*L).r[high].key >= pivotkey)
            --high;
        (*L).r[low] = (*L).r[high];
        while(low < high && (*L).r[low].key <= pivotkey)
            ++low;
        (*L).r[high] = (*L).r[low];
    }
    (*L).r[low] = (*L).r[0];
    return low;
}
void QSort(SqList *L, int low, int high)
{
    if(low < high)
    {
        int pivotkey = Partition(L, low, high);
        QSort(L, low, pivotkey);
        QSort(L, pivotkey + 1, high);
    }
}
void QuickSort(SqList *L)
{
    QSort(L, 1, (*L).length);
}
void SelectSort(SqList *L)
{
    for(int i = 1; i < (*L).length; ++i)
    {
        int k = i;
        for(int j = i + 1; j <= (*L).length; ++j)
            if((*L).r[j].key < (*L).r[k].key)
                k = j;
        RedType t;
        if(k != i)
        {
            t = (*L).r[i];
            (*L).r[i] = (*L).r[k];
            (*L).r[k] = t;
        }
    }
}