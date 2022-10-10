#include <stdio.h>
# define maxsize 5

int queue[maxsize];
int front=-1;
int rear=-1;

void enqueue(int x)
{
	if(front==-1 && rear==-1)
	{
		front++;rear++;
		queue[rear]=x;
	}
	else if(rear==maxsize-1)
	{
		printf("\nqueue overflow");
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("\nqueue underfow");
	}
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front++;
	}
}

void print()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("\nqueue empty");
	}
	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(4);
	enqueue(5);
	enqueue(7);
	printf("\nafter enqueue: ");
	print();
	dequeue();
	printf("\nafter dequeue: ");
	print();
}
