#include<stdio.h>
int main()
{
	int a,b;
	printf("Input two numbers a and b\n");
	scanf("%d%d",&a,&b);
	printf("a=%d,b=%d\n",a,b);
	a=a+b;//有可能溢出
	b=a-b;
	a=a-b;
	printf("a=%d,b=%d\n",a,b);
	return 0;
}
