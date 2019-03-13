#ifndef SSTRING_H_
#define SSTRING_H_
#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN + 1];
    int length;
} SString;
int Index_BF(SString S, SString T, int pos);
#endif