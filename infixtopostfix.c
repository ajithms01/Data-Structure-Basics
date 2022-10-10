#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stk[50],inf[50],post[50],ch;
int top=-1;
int j=0;
int priority(char ch)
{
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/')
		return 2;
	if(ch=='^')
		return 3;
	else
		return 0;
}

void push(char ch)
{
	top++;
	stk[top]=ch;
}
	

int main()
{
	printf("\nEntr the infix expression: ");
	scanf("%s",inf);
	for(int i=0;inf[i]!='\0';i++)
	{
		ch=inf[i];
		switch(ch)
		{
			case '(': push(ch);
			break;
			case ')':{
				while(stk[top]!='(')
				{
					post[j++]=stk[top];
					top--;
				}
				top--;
			}
				break;
			case '+':
			case '-':
			case '/':
			case '^': 
			case '*':{
				if(stk[top]=='(' || top==-1)
					push(ch);
				else
				{
					int x,y;
					x=priority(ch);
					y=priority(stk[top]);
					if(x<=y)
					{
						while(x<=y)
						{
						post[j++]=stk[top];
						top--;
					}
						push(ch);
					
					}
					else
					{
						push(ch);
					}
				}
			}
			break;
			default: if(isalpha(ch))
						post[j++]=ch;
					break;
		}
	}
		while(top>=0)
		{
			post[j++]=stk[top];
			top--;
		}
		post[j++]=stk[top];
		//post[j++]='\0';
		printf("\npostfix exp: ");
		for(int i=0;post[i]!='\0';i++)
		{
			printf("%c",post[i]);
		}
	}

			
