#include<stdio.h>
#include<string.h>
void Swap(int *a,int *b)
{
   int t;
   t=*a;*a=*b;*b=t;
}
void ShellInsert(int arr[],int len)
{
   int i,j,gap;
   for(gap=len/2;gap>0;gap/=2)
   	   for(i=gap;i<len;i++)
   		   for(j=i-gap;j>=0&&arr[j]>arr[j+gap];j-=gap)
   		   {
              Swap(&arr[j],&arr[j+gap]);
   		   }


}
int main()
{
	int i;
	int arr[5]={5,36,10,6,12};
	int len=5;
	ShellInsert(arr,5);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}