#include <stdio.h>
#include <string.h>

#define MAXLEN 255
typedef struct 
{
    char ch[MAXLEN+1];
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

void Virus_detection()
{
	SString Virus;
	SString Person;
	SString temp;
	char Vir[20];
	int num;
	int flag;
	int m;
	int i;
	int j;

	FILE *ifp = fopen("病毒感染检测输入数据.txt", "r");
	FILE *ofp = fopen("病毒感染检测输出结果.txt", "w");
	
	fscanf(ifp, "%d", &num);
	
	while(num--)
	{
		fscanf(ifp, "%s", Virus.ch+1);
		fscanf(ifp, "%s", Person.ch+1);

		Virus.length = strlen(Virus.ch+1);
		Person.length = strlen(Person.ch+1);

		strcpy(Vir, Virus.ch+1);

		flag = 0;
		m = Virus.length;

		for(i = m + 1, j = 1; j <= m; j++)
			Virus.ch[i++] = Virus.ch[j];

		Virus.ch[2*m+1] = '\0';
		
		for(i = 0; i < m; i++)
		{
			for(j = 1; j <= m; j++)
				temp.ch[j] = Virus.ch[i+j];
			temp.ch[m+1]='\0';
			temp.length = strlen(temp.ch+1);

			flag = Index_BF(Person, temp, 1);
			if(flag)
				break;
		}
		if(flag)
			fprintf(ofp, "%20s%20s%10s\n", Vir, Person.ch+1, "YES");
		else
			fprintf(ofp, "%20s%20s%10s\n", Vir, Person.ch+1, "NO");
	}
	fclose(ifp);
	fclose(ofp);
}

int main()
{
	Virus_detection();
	return 0;
}
