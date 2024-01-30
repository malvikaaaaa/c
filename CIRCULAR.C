#include<stdio.h>
#include<conio.h>
int rear=-1,front=-1,q[10],item,n;
void enqueue();
void dequeue();
void display();
void search();

void main()
{
	int ch;
	clrscr();
	printf("Enter the size of queue:");
	scanf("%d",&n);
	do
	{       printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Search\n5.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: search();
				break;
			case 5: exit(0);
			default:printf("Invalid choice\n");
		}
	} while(ch!=0);
}

void enqueue()
{
	if(front==(rear+1)%n)
	{
		printf("Queue overflow\n");
	}
	else if(front==-1&&rear==-1)
	{
		printf("Enter value:");
		scanf("%d",&item);
		front=0;
		rear=0;
		q[rear]=item;
		printf("Value inserted\n");
	}
	else
	{
		printf("Enter value:");
		scanf("%d",&item);
		rear=(rear+1)%n;
		q[rear]=item;
		printf("Value inserted\n");
	}
}

void dequeue()
{
	if(front==-1&&rear==-1)
		printf("Queue underflow\n");
	else if(front==rear)
	{
		printf("%d Deleted\n",q[front]);
		q[front]=NULL;
		front=-1;
		rear=-1;
	}
	else
	{
		printf("%d Deleted\n",q[front]);
		q[front]=NULL;
		front=(front+1)%n;
	}
}

void display()
{
	int i;
	if(front==-1&&rear==-1)
		printf("Queue is empty\n");
	else
	{
		printf("The circular queue is:\n");
		for(i=front;i<=rear;i++)
		{
			printf(" %d",q[i]);
		}
	printf("\n");
	}
}

void search()
{
	int value,flag,pos,i;
	printf("\nEnter the value to be searched:");
	scanf("%d",&value);
	flag=0;
	pos=0;
	for(i=front;i<=rear;i++)
	{
		pos++;
		if(q[i]==value)
		{
			printf("Element found at position %d\n",pos);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\nElement not found\n");
}