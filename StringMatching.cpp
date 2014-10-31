/********************************************************************
	created:	2012/01/02
	created:	2:1:2012   1:53
	filename: 	J:\���ĳ���\Datastructure.cpp
	file path:	J:\���ĳ���
	file base:	Datastructure
	file ext:	cpp
	author:		wangxingjun
	
	purpose:	���ݽṹ�γ����ģʽƥ��Դ����
*********************************************************************/
#include<iostream.h>
#define MAX 255  //������󳤶��Զ���Ϊ255
typedef unsigned char SString[MAX+1];  //0�Ŵ洢��Ԫ���ڴ洢�ַ�������

void StrAssign(SString &T, char *strs)
{
        int i;
        T[0] = 0;   //0�ŵ�Ԫ�洢�ִ�����
        for(i = 0; strs[i]; i++)   //������strs����T��ֵ
                T[i+1] = strs[i];
        T[0] = i;
}


int Index(SString S,SString T,int pos=1 )
{//����ģʽ��P��Ŀ�괮S�е�pos���ַ����λ�ã���������posΪ0
//TΪ�ǿմ���1<=pos<=S[0]
int i=pos;
int j=1;
while(i<=S[0]&&j<=T[0])
   {
      if(S[i]==T[j]){
         ++i;  ++j;}
      else
{i=i-j+2;  j=1;}
}
     if(j>T[0])
        return i-T[0];
     else return 0;
}//Index

void get_next(SString T,int next[])
{//���ģʽ�е�nextֵ������next�����У����ǸĽ����next����
   int  i=1;  next[1]=0;  int j=0;
   while(i<T[0])
      if(j==0 ||T[i]==T[j])
      {++i; ++j;
      if(T[i]!=T[j]) 
        next[i]=j;
      else next[i]=next[j];
	  }
      else j=next[j];
}//get_next

 
/*void get_next(SString T,int next[])
{//�Ľ�ǰ��next����
	int i=1;  next[1]=0;  int j=0;
	while(i<T[0])
		if (j==0||T[i]==T[j])
		{
			++i;  ++j;
			next[i]=j;
		}
		else j=next[j];
}*/


int Index_KMP(SString S,SString T,int next[],int pos=1 )
{//����nextֵ������ģʽ�������ģʽ�������е�posλ����ֵ�λ��
//TΪ�ǿմ���1<=pos<=S[0]
int i=pos;
int j=1;
while(i<=S[0]&&j<=T[0])
      if(j==0||S[i]==T[j]){
         ++i;  ++j;}
      else  j=next[j];
if(j>T[0])
      return i-T[0];
     else return 0;
}//Index_KMP

void BF(SString S,SString T,int pos=1) 
{//����BF�㷨����ģʽƥ��
cout<<"ʹ��BF�㷨����ģʽƥ��Ľ����:"<<endl;
if(Index( S, T,pos )>0)
cout<<"�����ַ����ĵ�"<< Index( S, T,pos )<<"���ַ���ʼƥ��"<<endl;
else cout<<"ƥ��ʧ��!"<<endl;
}


void KMP(SString S,SString T,int next[],int pos=1)
{//����KMP�㷨����ģʽƥ��
	cout<<"ʹ��KMP�㷨����ģʽƥ��Ľ����:"<<endl;
	if(Index_KMP( S, T,next,pos)>0)
		cout<<"�����ַ����ĵ�"<< Index_KMP( S, T,next,pos)<<"���ַ���ʼƥ��"<<endl;
	else cout<<"ƥ��ʧ��!"<<endl;
}



void main()
{
	SString S,T;
	int order;
	int next[MAX];
	//int position;�˳�������positionĬ�ϴӿ�ʼ�Ƚ�
	char s1[MAX];
	char s2[MAX];
	cout<<"��ӭ����ģʽƥ�����ϵͳ!"<<endl;
	cout<<"���������ַ���:"<<endl;
	cin>>s1;
	StrAssign(S, s1);
	cout<<"������ģʽ�ַ���:"<<endl;
	cin>>s2;
	StrAssign(T, s2);
	get_next(T, next);
	// cout<<next[2];
	cout<<"������������㷨?��ѡ��,BF�㷨������1,KMP�㷨������2:"<<endl;
	cin>>order;
	if(order==1)
        BF(S,T,1) ;
    else if(order==2) 
		KMP(S,T,next,1);
}
