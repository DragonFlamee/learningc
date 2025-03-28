#include<stdio.h>

double mypow1(double x, int y)
{
    if(y==0) return 1;
    if(y%2 == 0)
    {
        return mypow1(x,y/2)*mypow1(x,y/2);
    }
    else
    {
        return mypow1(x,y/2)*mypow1(x,y/2)*x;
    }
}
double mypow2(double x, int y)
{
    double result = 1;
    double cp = x;
    for(int i=y;i>0;i/=2)
    {
        if(i%2==1)
        {
            result *= cp;
        }
            cp *= cp;
    }
    return result;
}

int main(void)
{
    double x;
    int y;
    scanf("%lf %d", &x,&y);
    printf("%lf \n",mypow2(x,y));
    return 0;
}