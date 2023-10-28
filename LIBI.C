#include<stdio.h>
#include<conio.h>
void linear();
void binary();
int f=-1,n,a[10],i;
void main()
{
	int c;
	clrscr();
	printf("Enter the limit:");
	scanf("%d",&n);
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
	{
	  scanf("%d",&a[i]);
	}
	do
	{
		printf("1.Linear Search\n2.Binary Search\n3.Exit\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: linear();
				break;
			case 2: binary();
				break;
			case 3: exit(0);
			default:printf("Invalid choice\n");
		}
	}while(c!=0);
}

void linear()
{
	int item;
	printf("Enter the number to be searched:");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(item==a[i])
		{
			f=i;
			break;
		}
	}
	if(f==-1)
		printf("Search unsuccessful\n");
	else
		printf("Linear search successful %d is founded at %d\n",item,f+1);
}

void binary()
{
	int item,low,high,mid;
	printf("Enter the number to be searched:");
	scanf("%d",&item);
	low=0;
	high=n-1;
	for(i=0;i<n;i++)
	{
		mid=(low+high)/2;
		if(a[mid]==item)
		{
			printf("Binary search successful %d is founded at %d\n",item,mid+1);
			f=mid;
			break;
		}
		else if(item<a[mid])
		{
			high=mid-1;
		}
		else if(item>a[mid])
		{
			low=mid+1;
		}
	}
	if(f==-1)
	{
		printf("Binary search Unsuccessful\n");
	}
}