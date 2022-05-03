#include <stdio.h>
#define maxsize 5//size of the stack

//INITIALISING ARRAY (STACK)
int stack[maxsize];
int top=-1;

//FUNCTION TO PUSH AN ITEM INT0 THE STACK
void push(int item)
{
	if(top==maxsize-1)	//checking if stack is full
	{
		printf("\n\tStack Overflow\n");
	}
	else
	{
		stack[++top]=item;
		printf("\n\t%d pushed successfully\n",item);
	}
}

//FUNCTION TO REMOVE AN ITEM FROM STACK
void pop()
{
	if(top==-1)
	{
		printf("\n\tStack Underflow\n");
	}
	else
	{
		printf("\n\t%d popped from stack\n",stack[top]);
		top--;
	}
}

int main()
{
	printf("\n\t-------------------------STACK IMPLEMENTATION-----------------------------\t");
	int choice=0;
	int item;
	while(choice!=3)
	{
		printf("\n\t1.Push\t2.pop\t3.Exit");
		printf("\n\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter the element to be pushed :");
				scanf("%d",&item);
				push(item);
			}
			break;
			case 2:
			{
				pop();
			}
			break;
			case 3: break;
			
		}
	}
}
		
