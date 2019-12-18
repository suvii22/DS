#include<stdio.h>
#include<string.h>
void binary_insertion_sort(int arr[],int len)
{
	int low,high,m,i,j;
	int tmp;
	for(i=1;i<len;i++)
	{
        tmp=arr[i];
        low=0; high=i-1;
        while(low<=high)
        {
        	m=(low+high)/2;
        	if(arr[m]>tmp) high=m-1;
        	else low=m+1;

        }
        for(j=i-1;j>=high+1;j--)
        	arr[j+1]=arr[j];
        arr[high+1]=tmp;
	}
}
int main()
{
	int i;
	int arr[5]={5,36,10,6,12};
	int len=5;
	binary_insertion_sort(arr,len);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);

	return 0;
}