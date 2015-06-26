#include<stdio.h>
#define N 10
int main()
{
	int a[N]={-2,1,5,9,4,3,12,-5,9,7};
	int num;
	scanf("%d",&num);
	int* b=(int*)malloc(sizeof(int)*N);
	int i;
	int j;
	for(i=0;i<N;i++)
		b[i]=num-a[i];
	i=0;
	j=N-1;
	while(i!=j&&i<N&&j<N)
	{
		if(a[i]==b[j])
			printf("%d,%d\n",a[i],a[j]);
		else{
			a++;
			b--;
		}
	}
	return 0;
}	
