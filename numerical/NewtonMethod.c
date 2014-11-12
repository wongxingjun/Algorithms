/*牛顿迭代法求一元二次方程的数值解，
  使用error控制精度
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float func(float a,float b,float c,float x)
{
    return a*x*x+b*x+c;
}
float newton(float a,float b,float c,float x0,float error)
{
    float x,temp;
    x=x0;
    temp=x0;
    x=-func(a,b,c,x)/(2*a*x+b)+x;
    while(fabs(temp-x)>error)
    {
        temp=x;
        x=-func(a,b,c,x)/(2*a*x+b)+x;
    }
    return x;
}
int main()
{
    float a,b,c,x0;
    scanf("%f%f%f",&a,&b,&c);
    float delta=b*b-4*a*c;
    if(delta>1e-7)
    {
        scanf("%f",&x0);
        printf("One of the solution is: %f\n",newton(a,b,c,x0,0.001));
    }
    else
        printf("There is no real sulution\n");
    return 0;
}
