#include <stdio.h>
#include "dancepartner.h"
void DancePartner(QElemType dancer[], int num)
{
    SqQueue Mdancers;
    SqQueue Fdancers;
    InitSqQueue(&Mdancers);
    InitSqQueue(&Fdancers);
    QElemType p;
    for(int i = 0; i < num; ++i)
    {
        p = dancer[i];
        if(p.sex == 'F')
            EnSqQueue(&Fdancers, p);
        else
            EnSqQueue(&Mdancers, p);
    }
    printf("The dancing partners are:\n");
    while(!SqQueueEmpty(Fdancers) && !SqQueueEmpty(Mdancers))
    {
        DeSqQueue(&Fdancers, &p);
        printf("%s ", p.name);
        DeSqQueue(&Mdancers, &p);
        printf("%s\n", p.name);
    }
    if(!SqQueueEmpty(Fdancers))
    {
        p = GetHeadSqQueue(Fdancers);
        printf("The first woman to get a partner is: %s\n", p.name);
    }
    else if(!SqQueueEmpty(Mdancers))
    {
        p = GetHeadSqQueue(Mdancers);
        printf("The first man to get a partner is: %s\n", p.name);
    }
}