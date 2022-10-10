#include <stdio.h>
#include <stdlib.h> 

void insertionsort(int a[],int n)
{
	int i,hole,value;
	for(i=1;i<n;i++)
	{
		value=a[i];
		hole=i;
		while(hole>0 && a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=value;
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
	int arr[]={3,1,5,6,22,4,9,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("before sort: \n");
	print(arr,size);
	printf("after sort: \n");
	insertionsort(arr,size);
	print(arr,size);
}
	
