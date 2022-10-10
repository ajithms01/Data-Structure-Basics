#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* next;
};

typedef struct node node;

node* search(node*,int);
void insertatfront(node** header,int x)
{
	node* newnode;
	if(*header==NULL)
	{
		*header=(node*)malloc (sizeof(node));
		(*header)->next=NULL;
		(*header)->key=x;
	}
	else
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->next=*header;
		newnode->key=x;
		*header=newnode;
	}
}

void insertafterx(node*header,int x,int k)
{
	node* newnode;
	if(header==NULL)
	{
		printf("insertion not possiblr cos header is empty\n");
	}
	else
	{
		node* xnode;
	
		xnode=search(header,x);
		if(xnode==NULL)
		{
			printf("element not present\n");
		}
		else
		{
			newnode=(node*)malloc(sizeof(node));
			newnode->key=k;
			newnode->next=xnode->next;
			xnode->next=newnode;
		}
	}
}

node* search(node* header,int x)
{
	node*ptr;
	for(ptr=header;ptr!=NULL;ptr=ptr->next)
	{
		if(ptr->key==x)
		{
			break;
		}
	}
	if(ptr==NULL)
	{
		return NULL;
	}
	else
		return ptr;
}

void freeone(node* ptr)
{
	free(ptr);
}

void deletex(node**header,int x)
{
	node* prev=NULL;
	node* ptr;
	if(*header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		for( ptr=*header;ptr!=NULL;ptr=ptr->next)
		{
			if(ptr->key==x)
			{
				break;
			}
			prev=ptr;
		}
	}
	if(ptr==NULL)
	{
		printf("element not present\n");
	}
	else
	{
		prev->next=ptr->next;
		freeone(ptr);
	}
}

				

void print(node*header)
{
	node* ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		for(ptr=header;ptr!=NULL;ptr=ptr->next)
		{
			if(ptr->next==NULL)
				printf("%d",ptr->key);
			else
				printf("%d->",ptr->key);
		}
	}
	printf("\n");
}

int main()
{
	node* header=NULL;
	for(int i=1;i<6;i++)
	{
		insertatfront(&header,i);
	}
	insertafterx(header,3,43);
	printf("the list is: ");
	print(header);
	deletex(&header,2);
	printf("after deletion:");
	print(header);
}
