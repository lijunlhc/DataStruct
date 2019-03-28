#include <stdio.h>
#include <string.h>
int Index_BF(char S[], char T[], int pos)
{
    int i = pos;
    int j = 0;
    int length_S = strlen(S);
    int length_T = strlen(T);
    while(i < length_S && j < length_T)
    {
        if(S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= length_T)
        return i - length_T + 1;
    else
        return 0;
}
void Virus_detection()
{
	FILE *ifp = fopen("病毒感染检测输入数据.txt", "r");
	FILE *ofp = fopen("病毒感染检测输出结果.txt", "w");
	int num;
	fscanf(ifp, "%d", &num);
	char virus[20];
	char person[20];
	char vir[20];
	int flag;
	int m;
	int i, j;
	char temp[20];
	while(num--)
	{
		fscanf(ifp, "%s", virus);
		fscanf(ifp, "%s", person);
		strcpy(vir, virus);
		flag = 0;
		m = strlen(virus);
		for(i = m, j = 0; j < m; j++)
			virus[i++] = virus[j];
		virus[2*m] = '\0';
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < m; j++)
				temp[j] = virus[i+j];
			temp[m]='\0';
			flag = Index_BF(person, temp, 0);
			if(flag)
				break;
		}
		if(flag)
			fprintf(ofp, "%20s%20s%10s\n", vir, person, "YES");
		else
			fprintf(ofp, "%20s%20s%10s\n", vir, person, "NO");
	}
	fclose(ifp);
	fclose(ofp);
}
int main()
{
	Virus_detection();
	return 0;
}
