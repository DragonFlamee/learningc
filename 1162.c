#include<stdio.h>
#include<math.h>
double mysqrt(double y)
{
    double n1=0, n2=y;
    double x = (n1 + n2)/2;
    double delta = pow(x,2)-y;
    while(fabs(delta)>=0.001)
    {
        if(delta < 0) n1 = x;
        if(delta > 0) n2 = x;
        x = (n1 + n2)/2;
        delta = pow(x,2)-y;
    }
    return x;
}

int main(void)
{
    double y;
    scanf("%lf", &y);
    printf("%lf \n",mysqrt(y));
    return 0;
}