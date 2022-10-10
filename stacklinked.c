#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};
typedef struct node node;

node* getnode()
{
	node* new;
	new=(node*)malloc(sizeof(node));
	new->link=NULL;
	return new;
}
	
void push(node **top,int x)
{
	node* newnode;
	if(*top==NULL)
	{
		*top=getnode();
		(*top)->data=x;
	}
	else
	{
		newnode=getnode();
		newnode->data=x;
		newnode->link=*top;
		*top=newnode;
	}
}

void freeNode(node *ptr)
{
  free(ptr);
}

void pop(node** top)
{
	if(*top==NULL)
	{
		printf("Empty");
	}
	else
	{
		node* temp;
		temp=*top;
		*top=(*top)->link;
		freeNode(temp);
	}
	printf("\nSuccessfully popped ");
}

void printList(node *top)
{
	printf("\n");
  node *p;
  if(top == NULL)
    {
      printf("\nThe list is empty");
    }
  else
    {
      for (p = top; p!=NULL; p = p->link)
	{
	  printf("%d ", p->data);
	}
    }
}
int main()
{
	int choice=0; 
	int x;
	node* top=NULL;
/*	for(int i=0;i<5;i++)
	{
		push(&top,i);
	}
	printList(top);
	pop(&top);
	printList(top);*/
	printf("\n=============================Stack operations=================================");
	while(choice!=4)
	{
		printf("\n1.Push\t2.Pop\t3.Print4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter the element to be pushed: ");
				scanf("%d",&x);
				push(&top,x);
				printf("\nPushed Successfully");
			}
			break;
			case 2:
			{
				pop(&top);
				printf("\nPopped Successfully");
			}
			break;
			case 3:
			{
				printList(top);
			}
			break;
			case 4:
			break;
		}
	}
}
	
		
	

