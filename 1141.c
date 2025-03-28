#include<stdio.h>
#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
    int i = start ,j = end, tmp = 0;
    while(i<j)
    {
        while(a[start]<=a[j]&& i<j) j--;
        
        while(a[start]>=a[i]&& i<j)i++;

        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    tmp = a[i];
    a[i] = a[start];
    a[start] = tmp;
    return i;
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

int main(void)
{
    quicksort(0,LEN-1);
    for(int i=0;i<LEN;i++) printf("%d ",a[i]);
    return 0;
}