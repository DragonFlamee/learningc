#include<stdio.h>
#define N 8
int a[N] = { 5, 2, 4, 7, 1, 3, 2, 6 };


int partition(int start,int end)
{
    int p = a[start];
    while(start<end)
    {
        while(a[end]>=p && start<end) end--;
        a[start]=a[end];
        while(a[start]<=p&&start<end) start++;
        a[end]=a[start];
    }
    a[start]=p;
    return start;
}

void selectkth(int start, int end, int k)
{
    int mid = partition(start,end);
    int i = mid - start +1;
    if(k==i) printf("%d",a[mid]);
    else if(k<i)
    {
        selectkth(start,mid-1,k);
    }
    else
    {
        selectkth(mid+1,end,k-i);
    }
}

int main(void)
{
    selectkth(0,7,4);
    return 0;
}