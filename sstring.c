#include "sstring.h"
int Index_BF(SString S, SString T, int pos)
{
    int i = pos;
    int j = 1;
    while(i <= S.length && j <= T.length)
    {
        if(S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;
}
int Index_KMP(SString S, SString T, int pos)
{
    int i = pos;
    int j = 1;
    while(i <= S.length && j <= T.length)
    {
        if(j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];7 
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;
}