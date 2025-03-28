#include <stdio.h>
#define N 8
int a[N] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int selectsecond(int start,int end)
{
    int sm1=a[start];
    int sm2=a[start];    
    for (int i=start;i<=end;i++)
    {
        if(a[i]<sm1)
        {
            sm2 = sm1;
            sm1 = a[i];
        }
        else if(a[i]<sm2&&a[i]!=sm1)
        {
            sm2 = a[i];
        }
    }
    return sm2;
}

int main()
{
    int c;
    c = selectsecond(0,7);
    printf("%d\n",c);
    return 0;
}