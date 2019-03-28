#include <stdio.h>

#define LEN 10

void InsertSort(int a[], int length)
{
    int i, j;
    for(i = 2; i <= length; ++i)
    {
        if(a[i] < a[i-1])
        {
            a[0] = a[i];
            a[i] = a[i-1];
            for(j = i - 2; a[0] < a[j]; --j)
                a[j+1] = a[j];
            a[j+1] = a[0];
        }
        printf("第%d趟排序结果：", i-1);
        for(j = 1; j <= length; ++j)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}

void BInsertSort(int a[], int length)
{
    int i, j, low, high, m;
    for(i = 2; i <= length; ++i)
    {
        a[0] = a[i];
        low = 1;
        high = i - 1;
        while(low <= high)
        {
            m = (low + high) / 2;
            if(a[0] < a[m])
                high = m - 1;
            else
                low = m + 1;
        }
        for(j = i - 1; j >= high + 1; --j)
            a[j+1] = a[j];
        a[high + 1] = a[0];
        printf("第%d趟排序结果：", i-1);
        for(j = 1; j <= length; ++j)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}

void ShellInsert(int a[], int length, int dk)
{
    int i, j;
    for(i = dk + 1; i <= length; ++i)
        if(a[i] < a[i - dk])
        {
            a[0] = a[i];
            for(j = i - dk; j > 0 && a[0] < a[j]; j -= dk)
                a[j+dk] = a[j];
            a[j+dk] = a[0];
        }
}
void ShellSort(int a[], int length, int dt[], int t)
{
    int k, j;
    for(int k = 0; k < t; ++k)
    {
        ShellInsert(a, length, dt[k]);
        printf("第%d趟排序结果：", k+1);
        for(j = 1; j <= length; ++j)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}

void BubbleSort(int a[], int length)
{
    int m = length - 1;
    int flag = 1;
    while((m > 0) && (flag == 1))
    {
        flag = 0;
        int t;
        for(int j = 1; j <= m; j++)
            if(a[j] > a[j+1])
            {
                flag = 1;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        --m;
        printf("第%d趟排序结果：", length-m-1);
        for(int j = 1; j <= length; ++j)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}

int Partition(int a[], int low, int high)
{
    a[0] = a[low];
    int pivotkey = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= pivotkey)
            --high;
        a[low] = a[high];
        while(low < high && a[low] <= pivotkey)
            ++low;
        a[high] = a[low];
    }
    a[low] = a[0];
    printf("pivotkey = %d: ", pivotkey);
    for(int j = 1; j <= LEN; ++j)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
    return low;
}
void QSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pivotkey = Partition(a, low, high);
        QSort(a, low, pivotkey);
        QSort(a, pivotkey + 1, high);
    }
}
void QuickSort(int a[], int length)
{
    QSort(a, 1, length);
}

int main()
{
    int a[LEN+1] = {0, 12, 2, 16, 30, 28, 10, 16, 20, 6, 18};
    int i;
    for(i = 1; i <= LEN; i++)
        printf("%d ", a[i]);
    printf("\n");
    //int dk[3] = {5, 3, 1};
    //ShellSort(a, LEN, dk, 3);
    //BInsertSort(a, LEN);
    //BubbleSort(a, LEN);
    QuickSort(a, LEN);
    for(i = 1; i <= LEN; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}