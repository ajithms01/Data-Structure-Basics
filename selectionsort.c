#include <stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void selectionsort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		swap(&a[i],&a[min]);
	}
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

int main()
{
	int arr[]={3,1,5,6,22,4,9,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("before sort: \n");
	print(arr,size);
	printf("after sort: \n");
	selectionsort(arr,size);
	print(arr,size);
	}
