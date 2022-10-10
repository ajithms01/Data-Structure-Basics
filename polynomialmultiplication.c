#include <stdio.h>

int main()
{
	int p1[50],p2[50],mult[50];
	int d1,d2;
	int i;
	
	printf("\nEnter the order of poly 1 &poly 2:  ");
	scanf("%d%d",&d1,&d2);
	printf("\n______________________________________________poly1____________________________________________________");
	printf("\nENter poly 1:");
	for(int i=d1;i>=0;i--)
	{
		printf("\nenter the coeffient of x^%d: ",i);
		scanf("%d",&p1[i]);
	}
	printf("\np1: ");
	for(int i=d1;i>=0;i--)
	{
		printf("%dx^%d+",p1[i],i);
	}
	
	printf("\n______________________________________________poly2____________________________________________________");
	printf("\nENter poly 2:");
	for(int i=d2;i>=0;i--)
	{
		printf("\nenter the coeffient of x^%d: ",i);
		scanf("%d",&p2[i]);
	}
	printf("\np2: ");
	for(int i=d2;i>=0;i--)
	{
		printf("%dx^%d+",p2[i],i);
	} 
	
	for(i=0;i<(d1+d2);i++)
	{
		mult[i]=0;
	}
	
	for(i=0;i<d1;i++)
	{
		for(int j=0;j<d2;j++)
		{
			mult[i+j]+=p1[i]*p2[j];
		}
	}
	
	printf("\nproduct: ");
	for(int i=d1+d2;i>=0;i--)
	{
		printf("%dx^%d+",mult[i],i);
	} 
}
