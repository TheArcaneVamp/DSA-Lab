#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int data;
	struct Node* next;	
} Node;

Node *head;

Node* CreateNode(int item)
{
	Node *new = (Node*)malloc(sizeof(Node)) ;
	new->next = NULL;
	new->data = item;
	return new;
}

void Display()
{
	Node *ptr = head;
	while(ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void InsertLast(int item)
{
	Node *new = CreateNode(item);
	Node *ptr = head;
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next=new;
}

void InsertFirst(int item)
{
	Node *new = CreateNode(item);
	new->next = head;
	head = new;

}

void InsertAfter(int item, int after)
{
	Node *new = CreateNode(item);
	Node *ptr = head;
	while(ptr->data != after)
	{
		ptr = ptr->next;
	}
	if(ptr->next == NULL)
	{
		printf("After Element Not Found\n");
	}
	new->next = ptr->next;
	ptr->next = new;
}

void InsertBefore(int item, int before)
{
	Node *ptr = head;
	Node *new = CreateNode(item);
	if(head->data == before)
	{
		new->next = NULL;
		head = new;
	}
	else
	{
		while((ptr->next)->data != before)
		{
			ptr = ptr->next;
		}
		new->next = ptr->next;
		ptr->next = new;
	}
}
		
void DeleteFirst()
{
	Node *ptr = head;
	head = ptr->next;
	free(ptr->next);
}

void DeleteLast()
{
	Node *ptr = head;
	while((ptr->next)->next != NULL)
	{
		ptr = ptr->next;
	}
	free((ptr->next)->next);
	ptr->next= NULL;
}

/*void DeleteBefore(int before)
{
	Node *ptr = head;
        if(head->data == before)
        {
                printf("There is no data before the before element\n");
        }
        else
        {
                while(((ptr->next)->next)->data != before)
                {
                        ptr = ptr->next;
                }
                new->next = ptr->next;
                ptr->next = new
        }
	
}*/


void main()
{
	int ch, item, after, before;
	while(1)
	{
		printf("1.Insert at First\n");
		printf("2.Insert at Last\n");
		printf("3.Display\n");
		printf("4.Insert Before Element\n");
		printf("5.Insert After Element\n");
		printf("6.Delete at First\n");
		printf("7.Delete at Last\n");
		printf("Enter -1 to exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: 
				printf("Enter an item:");
				scanf("%d", &item);
				InsertFirst(item);
				break;
			case 2: 
				printf("Enter an item:");
                                scanf("%d", &item);
                                InsertLast(item);
				break;
			case 3:
				Display();
				break;
			case 4:
				printf("Enter the before element:");
				scanf("%d", &before);
				printf("Enter an item:");
                                scanf("%d", &item);
				InsertBefore(item, before);
				break;
			case 5:
				printf("Enter the after element:");
                                scanf("%d", &after);
                                printf("Enter an item:");
                                scanf("%d", &item);
                                InsertAfter(item, after);
				break;
			case 6: 
				DeleteFirst();
				break;
			case 7: 			
				DeleteLast();
				break;
			default:
				if(ch == -1)
				{
					exit(0);
				}
				printf("Wrong Input\n");
		}	
	}
	

}
