#include <stdio.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

 void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
void heapify(int a[],int size,int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<size &&  a[left]>a[largest])
		largest=left;
	if(right<size && a[right]>a[largest])
		largest=right;
	if(largest!=i)
	{
		swap(&a[largest],&a[i]);
		heapify(a,size,largest);
	}
}
  
void heapsort(int arr[],int size)
{
	for(int i=(size/2)-1;i>=0;i--)
	{
		heapify(arr,size,i);
	}
	for(int i=size-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}
  
int main()
{
	int a[]={5,3,7,1,9,6};
	int size=sizeof(a)/sizeof(a[0]);
	printf("array before sort: ");
	printArray(a,size);
	heapsort(a,size);
	printf("after sort: ");
	printArray(a,size);
}
