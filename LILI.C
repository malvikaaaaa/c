#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void createlist(int n);
void display();
void insert_first();
void insert_last();
void insert_pos();
void delete_first();
void delete_last();
void delete_pos();
void search();

int n=0;
struct node
{
	int data;
	struct node *next;
} *head;

void main()
{
	int ch;
	clrscr();
	printf("Enter the size of list\n");
	scanf("%d",&n);
	createlist(n);
	do
	{
		printf("SELECT\n1.Insert node at first\n2.Insert node at last\n3.Insert node at position\n4.Delete node at first\n5.Delete node at last\n6.Delete node at position\n7.Search an element\n8.Display\n9.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:	insert_first();
			printf("%d",n);
			continue;
		case 2:	insert_last();
			continue;
		case 3:	insert_pos();
			continue;
		case 4: delete_first();
			continue;
		case 5: delete_last();
			continue;
		case 6: delete_pos();
			continue;
		case 7: search();
			continue;
		case 8: display();
			continue;
		default:
			exit(0);
		}
	} while(ch!=0);
}

void createlist(int n)
{
	struct node *curr,*newnode;
	int data,i;

	if(n==0)
	  return;

	head=malloc(sizeof(struct node)); //allocating memory for head
	if(head==NULL)
	{
		printf("unable to allocate memory\n");
		return;
	}
	printf("enter the head value\n");
	scanf("%d",&data);
	head->data=data; //assigning data to head
	head->next=NULL; //assigning next to null

	curr=head;

	for(i=1;i<n;++i)
	{
		printf("enter the node %d\n",i+1);
		scanf("%d",&data);

		//creating new node

		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		newnode->next=NULL;

		//creating link with current node

		curr->next=newnode;
		curr=newnode;
	}
}

void display()
{
	struct node *curr;
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		curr=head;
		printf("\nThe List is ");
		while(curr!=NULL)
		{
			printf("%d",curr->data);
			curr=curr->next;
		}
	}

	printf("\n\n");
}

void insert_first()
{
	struct node *newnode;
	int data;
	n++;
	printf("enter node value\n");
	scanf("%d",&data);

	//if list is empty
	if(head->data==NULL)
	{
		head=malloc(sizeof(struct node));
		head->data=data;
		head->next=NULL;
		printf("Node inserted\n");
	}
	//if list contain atleast one element

	else
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		newnode->next=head;
		head=newnode;
		printf("Node inserted\n")
	}
}

void insert_last()
{
	struct node *newnode,*lastnode;
	int data;

	if(head==NULL)
	{
		insert_first();
	}
	else
	{
		n++;
		printf("enter the node value\n");
		scanf("%d",&data);
		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		lastnode=head;
		while(lastnode->next!=NULL)
		{
			lastnode=lastnode->next;
		}
		lastnode->next=newnode;
		newnode->next=NULL;
		printf("node inserted\n");
	}
}

void insert_pos()
{
	struct node *newnode,*prev,*curr;
	int pos,data,i;
	printf("enter the pos to be insertd\n");
	scanf("%d",&pos);
	if(pos<0||pos>n+1)
		printf("invalid position\n");
	else if(pos==1)
	{
		insert_first();
	}
	else if(pos==n)
	{
		insert_last();
	}
	else
	{
		n++;
		printf("enter the node value\n");
		scanf("%d",&data);
		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		curr=head;
		for(i=1;i<pos-1;++i)
		{
			curr=curr->next;
		}
		newnode->next=curr->next;
		curr->next=newnode;

		printf("node inserted\n")
	}
}

void delete_first()
{
	if(head==NULL)
		printf("\nNo element to delete\n\n");
	else if(head->next==NULL)
	{
		n--;
		printf("\nThe node deleted is %d\n\n",head->data);
		head=NULL;
	}
	else
	{
		n--;
		printf("\nThe node deleted is %d\n\n",head->data);
		head=head->next;
	}
}

void delete_last()
{
	struct node *lastnod,*prev;
	if(head==NULL)
		printf("\nNo element to delete\n\n");

	else if(head->next==NULL)
	{
		n--;






























































