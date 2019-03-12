#include <stdio.h>
#include "dancepartner.h"
int main()
{
    QElemType dancer[5] = {{"Qiang Qiang", 'M'}, {"Chao Chao", 'M'}, {"Peng Peng", 'M'}, {"Hong Hong", 'F'}, {"Jing Jing", 'F'}};
    DancePartner(dancer, 5);
    return 0;
}

