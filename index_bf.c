#include <stdio.h>
#include <string.h>

#define MAXLEN 255
typedef struct {
    char ch[MAXLEN + 1];
    int length;
} SString;

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

int main()
{
    SString S;
    strcpy(S.ch+1, "0000000001");
    S.length = strlen("0000000001");
    SString T;
    strcpy(T.ch+1, "0001");
    T.length = strlen("0001");
    int index = Index_BF(S, T, 1);
    printf("%d\n", index);
    return 0;
}