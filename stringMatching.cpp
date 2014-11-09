#include<iostream>
#define MAX 255
using namespace std;
typedef unsigned char SString[MAX+1];

void StrAssign(SString &T, char *strs)
{
    int i;
    T[0] = 0;
    for(i = 0; strs[i]; i++)
        T[i+1] = strs[i];
    T[0] = i;
}


int Index(SString S,SString T,int pos=1 )
{
    int i=pos;
    int j=1;
    while(i<=S[0]&&j<=T[0])
    {
        if(S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+2;
            j=1;
        }
    }
    if(j>T[0])
        return i-T[0];
    else return 0;
}//Index

void get_next(SString T,int next[])
{
    int  i=1;
    next[1]=0;
    int  j=0;
    while(i<T[0])
        if(j==0||T[i]==T[j])
        {
            ++i;
            ++j;
            if(T[i]!=T[j])
                next[i]=j;
            else next[i]=next[j];
        }
        else j=next[j];
}//get_next


int Index_KMP(SString S,SString T, int next[],int pos=1)
{
    int i=pos;
    int j=1;
    while(i<=S[0]&&j<=T[0])
    {
        if(j==0||S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else  j=next[j];
    }
    if(j>T[0])
        return i-T[0];
    else return 0;
}//Index_KMP

void BF(SString S,SString T,int pos=1)
{
    cout<<"BF algorithm result is:"<<endl;
    if(Index( S, T,pos )>0)
        cout<<"From "<< Index( S, T,pos )<<"matches"<<endl;
    else cout<<"Match failure"<<endl;
}


void KMP(SString S,SString T,int next[],int pos=1 )
{
    cout<<"KMP algorithm result is:"<<endl;
    if(Index_KMP( S, T,next,pos )>0)
        cout<<"From "<< Index_KMP( S, T,next,pos )<<"matches"<<endl;
    else cout<<"Match failure"<<endl;
}



int main()
{
    SString S,T;
    int choice;
    int next[MAX];
    char s1[MAX];
    char s2[MAX];
    cout<<"Input the string:"<<endl;
    cin>>s1;
    StrAssign(S, s1);
    cout<<"Input the sub string you want to look for:"<<endl;
    cin>>s2;
    StrAssign(T, s2);
    get_next(T, next);
    cout<<"Which algorithm you want? Input 1 for BF or 2 for KMP"<<endl;
    cin>>choice;
    if(choice==1)
        BF(S,T,1);
    else if(choice==2)
        KMP(S,T, next,1);
	return 0;
}

