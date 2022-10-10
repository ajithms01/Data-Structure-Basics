#include <stdio.h> 
#include <stdlib.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int l,int r)
{
	int pivot=a[l];
	int start=l;
	int end=r;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(&a[start],&a[end]);
		}
	}
	swap(&a[l],&a[end]);
	return end;
}

void quicksort(int a[],int l,int r)
{
	if(l<r)
	{
		int pivotpos=partition(a,l,r);
		quicksort(a,l,pivotpos-1);
		quicksort(a,pivotpos+1,r);
	}
	
}

void print(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[]={5,3,6,7,1,33,2,12};
	int size=sizeof(a)/sizeof(a[0]);
	printf("before sort: ");
	print(a,size);
	printf("afyer sort: ");
	quicksort(a,0,size-1);
	print(a,size);
}
