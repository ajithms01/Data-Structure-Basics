#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2=r-mid;
	int al[n1];
	int ar[n2];
	int i,j,k;
	for(i=0;i<n1;i++)
	{
		al[i]=arr[l+i];
	}
	for(j=0;j<n2;j++)
	{
		ar[j]=arr[mid+1+j];
	}
	i=0;j=0;k=l;
	while(i<n1&&j<n2)
	{
		if(al[i]<ar[j])
		{
			arr[k]=al[i];
			i++;
		}
		else
		{
			arr[k]=ar[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=al[i];
		k++;i++;
	}
	while(j<n2)
	{
		arr[k]=ar[j];
		k++;j++;
	}
}

void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
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
	int a[] = { 12, 11, 13, 5, 6, 7 };
	int size=sizeof(a)/sizeof(a[0]);
	printf("before sort: ");
	print(a,size);
	mergesort(a,0,size-1);
		printf("afyer sort: ");

	
	print(a,size);
	return 0;
}

