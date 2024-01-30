#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void search();

struct node{
int data;
struct node *next;
}*top;

void main()
{

	int ch;
	clrscr();

    do
    {

	printf("SELECT\n1.PUSH\n2.POP\n3.Display\n4.Search\n5.Exit\nEnter your choice:");
	scanf("%d", &ch);

	switch (ch)
	{
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4: search();
			break;
		default:exit(0);
	}

    } while (ch != 0);
}


void push()
{

    struct node *newnode;
    int data;

    printf("Enter node value\n");
    scanf("%d", &data);

    // if list is empty
    if (top->data == NULL)
    {
	top = malloc(sizeof(struct node));
	top->data = data;
	top->next = NULL;
	printf("Node Inserted\n");
    }
    // if list contain atleast one element
    else
    {
	newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = top;
	top = newnode;
	printf("Node Inserted\n");
    }
}

void pop()
{
    struct node *temp;

    if (top == NULL)

	printf("\nNo Element to Delete\n\n");

    else if (top->next == NULL)
    {
	printf("\nThe node deleted is %d\n\n", top->data);
	top = NULL;
    }
    else
    {
	printf("\nThe node deleted is %d\n\n", top->data);
	temp=top;
	top = top->next;
	free(temp);
    }
}


void display()
{
    struct node *curr;

    if (top == NULL)
	printf("Stack is Empty\n");

    else
    {

	curr = top;
	printf("\nThe Stack is \n");
	while (curr != NULL)
	{
	    printf("%d\n", curr->data);
	    curr = curr->next;
	}
    }

    printf("\n\n");
}

void search()
{
	struct node *curr;
	int flag,value,pos;
	printf("\nEnter the value to be searched:");
	scanf("%d",&value);
	if(top==NULL)
		printf("\nStack empty");
	else if(top->next==NULL)
	{
		if(top->data==value)
			printf("\nNode found at position 1");
		else
			printf("\nNode not found");
	}
	else
	{
		flag=0;
		pos=0;
		curr=top;
		while(curr!=NULL)
		{
			pos++;
			if(curr->data==value)
			{
				printf("Element found at position %d\n",pos);
				flag=1;
				break;
			}
			else
			{
				curr=curr->next;
			}
		}
	if(flag==0)
		printf("Element not found\n");
	}
}