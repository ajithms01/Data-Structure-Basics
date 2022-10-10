#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};
typedef struct node node;


void enqueue(node** front,node** rear,int x)
{
	node* new;
	if(*front==NULL && *rear==NULL)
	{
		new=(node* )malloc(sizeof(node));
		new->data=x;
		new->link=NULL;
		*front=new;
		*rear=new;
	}
	else
	{
		new=(node*)malloc(sizeof(node));
		new->data=x;
		new->link=NULL;
		
		(*rear)->link=new;
		*rear=new;
	}
}

void freeNode(node *ptr)
{
  free(ptr);
}

void dequeue(node** front,node**rear)
{
	node* temp;
	if(*front==NULL && *rear==NULL)
	{
		printf("empty");
	}
	else if(*front==*rear)
	{
		temp=*front;
		*front=*rear=NULL;
		freeNode(temp);
	}
	else
	{
		temp=*front;
		*front=(*front)->link;
		freeNode(temp);
	}
}

void printList(node* front,node* rear)
{
  node *p;
  if(front == NULL && rear==NULL)
    {
      printf("The list is empty");
    }
  else
    {
		printf("\nqueue elements: ");
      for (p = front; p!=NULL; p = p->link)
	{
	  printf("%d ", p->data);
	}
    }
}

int main()
{
	node* front;
	node* rear;
	front=NULL;rear=NULL;
	enqueue(&front,&rear,1);
	enqueue(&front,&rear,110);
	enqueue(&front,&rear,12);
	enqueue(&front,&rear,13);
	printList(front,rear);
	dequeue(&front,&rear);
	printList(front,rear);
		dequeue(&front,&rear);
		printList(front,rear);
			dequeue(&front,&rear);
			printList(front,rear);
				dequeue(&front,&rear);
				printList(front,rear);
					dequeue(&front,&rear);
	printList(front,rear);
}
		
