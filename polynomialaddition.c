/*Write a program to read two polynomials and store them in an array. Calculate the sum of the
two polynomials and display the first polynomial, second polynomial and the resultant
polynomial.*/
#include <stdio.h>

int main()
{
	int p1[50],p2[50],sum[50];
	int d1,d2;
	int i;
	int maxdeg,mindeg;
	
	printf("\nEnter the order of poly 1 &poly 2:  ");
	scanf("%d%d",&d1,&d2);
	maxdeg=(d1>d2)?d1:d2;
	mindeg=(d1<d2)?d1:d2;
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
	
	for(i=0;i<=mindeg;i++)
	{
		sum[i]=p1[i]+p2[i];
	}
	if(d1>d2)
	{
		for(i=mindeg+1;i<=maxdeg;i++)
		{
			sum[i]=p1[i];
		}
	}
	if(d2>d1)
	{
		for(i=mindeg+1;i<=maxdeg;i++)
		{
			sum[i]=p2[i];
		}
	}
	
	printf("\nsum: ");
	for(int i=maxdeg;i>=0;i--)
	{
		printf("%dx^%d+",sum[i],i);
	}
}
	
