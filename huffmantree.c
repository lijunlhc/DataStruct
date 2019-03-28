#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status;

typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

Status Select(HuffmanTree HT, int end, int *order_1, int *order_2)
{
    HuffmanTree p;
    int i, count;
    int m, n, tmp;
    
    if(end<2)
        return ERROR;
    
    for(i=1,count=1; i<=end; i++)                       //遍历找出前两个未编入树的结点 
    {
        if(HT[i].parent==0)
        {
            if(count==1)
                m = i;
            if(count==2)
                n = i;
            count++;
        }
        
        if(count>2)
            break;
    }
    
    if(HT[m].weight>HT[n].weight)                       //令m结点的权重小于等于n结点的权重 
    {
        tmp = n;
        n = m;
        m = tmp;
    }
    
    i = (m>n ? m : n) + 1;
    while(i<=end)                                       //继续遍历，寻找更小更靠前的结点
    {   
        if(HT[i].parent==0)
        {
            if(HT[i].weight<HT[m].weight)
            {
                n = m;
                m = i;
            }
            else
            {
                if(HT[i].weight>=HT[m].weight && HT[i].weight<HT[n].weight)
                    n = i;
            }       
        }
        
        i++;
    }
    
    *order_1 = HT[m].weight<=HT[n].weight ? m : n;
    *order_2 = HT[m].weight>HT[n].weight ? m : n;
    
    return OK;
}

void CreateHuffmanTree(HuffmanTree *HT, int n)
{
    if(n <= 1)
        return;
    int m = 2 * n - 1;
    *HT = (HTNode *)malloc(sizeof(HTNode)*(m+1));
    for(int i = 1; i <= m; ++i)
    {
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }
    for(int i = 1; i <= n; ++i)
        scanf("%d", &((*HT)[i].weight));
    int s1, s2;
    for(int i = n + 1; i <= m; ++i)
    {
        Select(*HT, i - 1, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}

int main()
{
    printf("Test\n");
    return 0;
}