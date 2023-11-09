#include<stdio.h>
#include<conio.h>
void creation();
void insertion();
void deletion();
void traversal();
int a[20],n,p,i,item;
void main()
{
	int c;
	clrscr();
	do
	{
		printf("Menu\n");
		printf("1.Creation\n2.Insertion\n3.Deletion\n4.Traversal\n5.Exit\nEnter you choice:");
		scanf("%d",&c);
		if(c==1)
			creation();
		else if(c==2)
			insertion();
		else if(c==3)
			deletion();
		else if(c==4)
			traversal();
		else
			exit(0);
	} while(c!=0);
}

void creation()
{
	printf("Enter the limit\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void insertion()
{
	printf("Enter the position to be inserted\n");
	scanf("%d",&p);
	printf("Enter the item\n");
	scanf("%d",&item);
	n++;
	i=n-1;
	while(i>=p)
	{
		a[i+1]=a[i];
		i--;
	}
	a[p]=item;
	printf("Item is inserted\n");
}

void deletion()
{
	printf("Enter the position to be deleted\n");
	scanf("%d",&p);
	i=p;
	item=a[p];
	while(i<=n)
	{
		a[i]=a[i+1];
		i++;
	}
	n--;
	printf("%d is deleted\n",item);
}

void traversal()
{
	for(i=1;i<=n;i++)
	{
		printf("%d\n",a[i]);
	}
}