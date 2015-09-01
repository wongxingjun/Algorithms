#include <stdio.h>                    
#include <stdlib.h>
#include <string.h>
#define M 1002
int reverse(char* s)
{
    int len=strlen(s);
    char* temp=(char*)malloc(sizeof(char)*len);
    strcpy(temp,s);
    int i;
    for(i=len-1; i>=0; i--)
    {
        s[len-i-1]=temp[i];
    }
    free(temp);
    return 0;
}
int addLong(char* a,char* b,int* c)
{
    int alen=strlen(a);
    int blen=strlen(b);
    int flag=M-1;
    int i;
    int inc=0;
    if(alen>blen)
    {
        for(i=blen;i<=alen-1;i++)
            b[i]='0';
    }
    else
    {
        for(i=alen;i<=blen-1;i++)
            a[i]='0';
    }
    int maxlen=alen>blen?alen:blen;
    for(i=0; i<maxlen; i++)
    {
        c[flag--]=(a[i]-'0'+b[i]-'0'+inc)%10;
        inc=(a[i]-'0'+b[i]-'0'+inc)/10;
    }
    if(inc>0)
    {
        c[flag]=inc;
        flag--;
    }
    return flag+1;
}
int main()
{
    char a[M],b[M];
    int c[M+5],ncase,i,flag;
    scanf("%d",&ncase);
    for(i=0; i<ncase; i++)
    {
        scanf("%s%s",a,b);
        printf("Case %d:\n",i+1);
        printf("%s + %s = ",a,b);
        reverse(a);
        reverse(b);
        flag=addLong(a,b,c);
        for(;flag<=M-1;flag++)
            printf("%d",c[flag]);
        if(i==ncase-1)
            printf("\n");
        else
            printf("\n\n");
    }
    return 0;
}
