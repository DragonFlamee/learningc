#include<stdio.h>
#define N 8
int a[N]={1,2,2,2,4,6,9,10};

int binarysearch(int num)
{
    int start = 0;
    int end = N-1;
    int mid = (start + end)/2;
    while (start <= end)
    {
        if(a[mid]<num) start = mid + 1;
        if(a[mid]>num) end = mid -1;
        if(a[mid]==num)
        {
            while(a[mid-1]==num) mid--;

            return mid+1;
        }
        mid = (start + end)/2;
    }
    return -1;
}

int main(void)
{
    int n = binarysearch(2);
    printf("%d \n", n);
    return 0;
}