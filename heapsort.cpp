#include<stdio.h>
int heapBuf[]={1,34,6,21,98,31,100,4,36,47,39,45,5,101};
void swap(int *i,int *j)
{
	int tmp=*i;
	    *i=*j;
	    *j=tmp;
}
 
void HeapAdjust(int arr[],int i,int nlen)
{
	int nchild,ntmp;
	for(ntmp=arr[i];2*i+1<nlen;i=nchild)
	{
		nchild=2*i+1;
		if (nchild != nlen - 1 && arr[nchild + 1] > arr[nchild])
            ++nchild;
        if (ntmp < arr[nchild])
        {
            arr[i] = arr[nchild];
        }
        else 
        {
            break;
        }
    }
    arr[i] = ntmp;
	
	
}
void HeapSort(int arr[],int len)
{
	int i;
	for(i=len/2-1;i>=0;i--)
	{
		HeapAdjust(arr,i,len);
	}
	for(i=len-1;i>0;i--)
	{
		swap(&arr[0],&arr[i]);
		HeapAdjust(arr,0,i);
	}
	
} 
int main()
{
	int i;
    int length = sizeof(heapBuf) / sizeof(int);
	printf("%d\n",length);  
    /* sort */  
    HeapSort(heapBuf,length); 
    for(i=0;i<length;i++) printf("%d ",heapBuf[i]);
    return 0;
}
