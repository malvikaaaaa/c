#include <stdio.h>
void push();
void pop();
void show();
int s[10],top=-1,n;
void main()
{
    int c;
    printf("Enter the size of stack<=100:");
    scanf("%d",&n);
    while(1)
    {
        printf("Menu\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your Choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: show();
                    break;
            case 4: exit(0);
            default: printf("Invalid Choice");
        }
    }
getch();
}

void push()
{
    int item;
    if(top==n-1)
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        top++;
        s[top]=item;
        printf("Item inserted\n");
    }
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack is Underflow\n");
    }
    else
    {   
        item=s[top];
        top--;
        printf("%d deleted\n",item);
    }
}

void show()
{
    int i;
    if(top<0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements are:\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",s[i]);
        }
    }
}
