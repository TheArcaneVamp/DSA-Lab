#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
char Q[100];
char P[100];

int topP=-1;
int top=0;

void push(char e)
{
	top++;
	stack[top] = e;	
}


void PushingP(char e)
{
	topP ++;
	P[topP]= e;
}


void pop()
{
	PushingP(stack[top]);
	top--;	
}


int isoperator(char e)
{
	if( e == '+' || e == '-' )
	{
		return 1;
	}
	else if( e == '*' || e == '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}


void main()
{
	int i = 0;
	int x;
	stack[0] = '(';
	
	printf("Enter the infix expression:");
	
	while(1)
	{
		Q[i] = getchar();
		if (Q[i] == '\n')
		{
			break;
		}
		i++;
	}
	
	Q[i] = ')'; //replacing '\n' by ')'
	Q[i+1] = '\0';
	for(i = 0; i< strlen(Q); i++ )
	{
		if (isdigit(Q[i]))
		{
			PushingP(Q[i]);
		}
		else if (Q[i]== '(')
		{
			push(Q[i]);
		}
		else if(isoperator(Q[i]))
		{
			x = isoperator(Q[i]);
			while(x<=isoperator(stack[top]))
			{
				pop();	
			}
			
			push(Q[i]);	
		}
	
		else if( Q[i] == ')')
		{
			while(stack[top] != '(')
			{
				pop();
			}
			top--; //poping the stack
		}
	}
	
	P[topP+4] = '\0'; 
	
	printf("The Postfix expression is: %s\n", P);
		
}