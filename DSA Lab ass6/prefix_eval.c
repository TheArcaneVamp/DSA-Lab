//postfix evaluation using stack

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <ctype.h>
#define MAXSIZE 500

char eq[500];
int l;
float arr[MAXSIZE];
int top=-1;

void push(float n)
{
	if(top==MAXSIZE)
	{
		printf("STACK OVERFLOW!!\n");
		return;
	}
	arr[++top]=n;
}

float pop()
{
	if(top==-1)
	{
		printf("STACK UNDERFLOW!!\n");
		return -1;	
	}
	top--;
	return arr[top+1];
}

float evaluate()
{
	int i,t=0;
	float a,b;
	char* ch="+-*/%^";
	char temp[10];
	for(i=0;i<l;i++)
	{
		if(eq[i]==')')
		{
			return pop();
		}
		
		if(strchr(ch,eq[i])!= NULL)
		{
			a=pop();
			b=pop();
			if(eq[i]=='+')
			{
				push(b+a);
			}
			if(eq[i]=='-')
			{
				push(b-a);
			}
			if(eq[i]=='*')
			{
				push(b*a);
			}
			if(eq[i]=='/')
			{
				push(b/a);
			}
			if(eq[i]=='%')
			{
				push((float)(((int)b)%((int)a)));
			}
			if(eq[i]=='^')
			{
				push(pow(b,a));
			}
		}
		else if(eq[i]==',')
		{
		    if(t==0)
		    continue;
			temp[t]='\0';
			int term=atoi(temp);
			push(term);
			t=0;
		}
		else
		{
			temp[t]=eq[i];
			t++;
		}
	}
}
int main()
{
	int i = 0;
	printf("Enter postfix expression : ");
	//scanf("%[^\n]",eq);
	while(1)
	{
		eq[i]=getchar();
		if(eq[i] == '\n')
		{
			break;
		}
		i++;
	}
	l=strlen(eq);
	eq[l]=')';
	eq[l+1]='\0';
	l++;
	printf("ANS = %f\n",evaluate());
	return 0;
}
