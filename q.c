#include <stdio.h>
void ins();
void del();
void show();
int q[10],rear=-1,front=-1,n;
int main()
{
    int c;
    printf("Enter the size of queue<=100:");
    scanf("%d",&n);
    while(1)
    {
        printf("Menu\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your Choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: ins();
                    break;
            case 2: del();
                    break;
            case 3: show();
                    break;
            case 4: return 0;
            default: printf("Invalid Choice");
        }
    }
return 0;
}

void ins()
{
    int item;
    if(rear==n-1)
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        if(rear==-1&&front==-1)
        {
            rear++;
            front++;
            printf("Enter the element:");
            scanf("%d",&item);
            q[rear]=item;
        }
        else
        {
            rear++;
            printf("Enter the element:");
            scanf("%d",&item);
            q[rear]=item;
        }
    }
}

void del()
{
    int item;
    if((rear==-1&&front==-1)||front>rear)
    {
        printf("Queue is Underflow\n");
    }
    else
    {   
        if(rear==front)
        {
            item=q[front];
            front++;
            printf("%d is deleted\n",item);
            rear=front=-1;
        }
        else
        {
            item=q[front];
            front++;
            printf("%d is deleted\n",item);
        }
    }
}

void show()
{
    int i;
    if((rear==-1&&front==-1)||front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements are:\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",q[i]);
        }
    }
}
