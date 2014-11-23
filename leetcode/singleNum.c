#include <stdio.h>
int main()
{
	int a[11]={1,2,1,3,3,4,4,2,5,6,6};
	int res=a[0];
	int i=1;
	for(;i<11;i++)
		res=res^a[i];
	printf("The single number is: %d\n",res);
	return 0;
}
