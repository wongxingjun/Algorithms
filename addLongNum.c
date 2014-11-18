/*两个超大整数相加,HDOJ 1002 解题报告
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
inline float func(float a,float b,float c,float x)
{
    return a*pow(x,2)+b*x+c;
}
float newton(float a,float b,float c,float x0)
{
    float x,temp;
    x=x0;
    temp=x0;
    x=(-func(a,b,c,x)/(2*a*x+b))+x;
    while(!(abs(temp-x)<1e-7))
    {
        temp=x;
        x=(-func(a,b,c,x)/(2*a*x+b))+x;
    }
    return x;
}
int main()
{
    float a,b,c,x0;
    scanf("%f%f%f%f",&a,&b,&c,&x0);
    float delta=b*b-4*a*c;
    //printf("%f\n",delta);
    if(abs(delta)<1e-5)
        return -1;
    else
        printf("%f\n",newton(a,b,c,x0));
    return 0;
}
