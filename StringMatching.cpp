/********************************************************************
	created:	2012/01/02
	created:	2:1:2012   1:53
	filename: 	J:\论文初稿\Datastructure.cpp
	file path:	J:\论文初稿
	file base:	Datastructure
	file ext:	cpp
	author:		wangxingjun
	
	purpose:	数据结构课程设计模式匹配源代码
*********************************************************************/
#include<iostream.h>
#define MAX 255  //允许最大长度自定义为255
typedef unsigned char SString[MAX+1];  //0号存储单元用于存储字符串长度

void StrAssign(SString &T, char *strs)
{
        int i;
        T[0] = 0;   //0号单元存储字串长度
        for(i = 0; strs[i]; i++)   //用数组strs给串T赋值
                T[i+1] = strs[i];
        T[0] = i;
}


int Index(SString S,SString T,int pos=1 )
{//返回模式串P在目标串S中第pos个字符后的位置，不存在则pos为0
//T为非空串，1<=pos<=S[0]
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
{//求出模式中的next值并存入next数组中，这是改进后的next函数
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
{//改进前的next函数
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
{//利用next值来减少模式回溯求出模式在主串中第pos位后出现的位置
//T为非空串，1<=pos<=S[0]
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
{//调用BF算法进行模式匹配
cout<<"使用BF算法进行模式匹配的结果是:"<<endl;
if(Index( S, T,pos )>0)
cout<<"从主字符串的第"<< Index( S, T,pos )<<"个字符开始匹配"<<endl;
else cout<<"匹配失败!"<<endl;
}


void KMP(SString S,SString T,int next[],int pos=1)
{//调用KMP算法进行模式匹配
	cout<<"使用KMP算法进行模式匹配的结果是:"<<endl;
	if(Index_KMP( S, T,next,pos)>0)
		cout<<"从主字符串的第"<< Index_KMP( S, T,next,pos)<<"个字符开始匹配"<<endl;
	else cout<<"匹配失败!"<<endl;
}



void main()
{
	SString S,T;
	int order;
	int next[MAX];
	//int position;此程序不区分position默认从开始比较
	char s1[MAX];
	char s2[MAX];
	cout<<"欢迎进入模式匹配测试系统!"<<endl;
	cout<<"请输入主字符串:"<<endl;
	cin>>s1;
	StrAssign(S, s1);
	cout<<"请输入模式字符串:"<<endl;
	cin>>s2;
	StrAssign(T, s2);
	get_next(T, next);
	// cout<<next[2];
	cout<<"您想采用哪种算法?请选择,BF算法请输入1,KMP算法请输入2:"<<endl;
	cin>>order;
	if(order==1)
        BF(S,T,1) ;
    else if(order==2) 
		KMP(S,T,next,1);
}
