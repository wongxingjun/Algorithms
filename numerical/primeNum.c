#include<stdio.h>
int isPrime(int n)
{
	int i;
	if(n==1)
		return 0;
	if(n%2==0||n%3==0||n%5==0)
		return (n==2||n==3||n==5);
	for(i=7;i*i<n;i=i+2)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(isPrime(n)>0)
		printf("It is a prime number\n");
	else
		printf("It is not  a prime number\n");
	return 0;
}
