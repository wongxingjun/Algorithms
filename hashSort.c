#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
char List[26]={'A','B','C','D','E','F','G','H','I','J','K','L',
	'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
	char s[MAX];
	scanf("%s",s);
	printf("%s\n",s);
	int i,j;
	int num[26]={0};
	for(i=0;i<strlen(s);i++)
		num[s[i]-'A']++;
	for(j=0;j<26;j++)
	{
		for(i=0;i<num[j];i++)
			printf("%c",List[j]);
	}
	return 0;
}

