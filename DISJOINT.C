#include <stdio.h>
#include <conio.h>

void unionAB(int a[10],int b[10]);
int find(int a[10],int b[10]);
int i,j,k,n,m;

void main()
{
	//int a[10]={1,2,3,4,5};
	//int b[10]={6,7,8,9};
	int parent,a[10],b[10];
	clrscr();
	printf("\nEnter the no:of elements in set a:");
	scanf("%d",&n);
	printf("\nEnter the elements of set a:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("\nEnter the no:of elements in set b:");
	scanf("%d",&m);
	printf("\nEnter the elements of set b:");
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);

	 unionAB(a,b);
	 parent=find(a,b);

	 if(parent==a[0])
		printf("Element found in set A\nRoot node = %d",parent);
	 else if(parent==b[0])
		printf("Element found in set B\nRoot node = %d",parent);
	 else
		printf("Not Found\n");

 getch();
 }
 void unionAB(int a[10],int b[10])
 {
	int unionAB[10];
	i=0;
	for(j=0;j<n;j++)
	{
		unionAB[i]=a[j];
		i++;

	}
	for(k=0;k<m;k++)
	{
		unionAB[i]=b[k];
		i++;
	}

	printf("A -  ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nB -  ");
	for(i=0;i<m;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\nAUB -  ");
	for(i=0;i<n+m;i++)
	{
		printf("%d ",unionAB[i]);
	}
 }

 //find

 int find(int a[10],int b[10])
 {
	int num;
	printf("\nEnter the number to be searched\n");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(a[i]==num)
		{
			return a[0];
		}
	}
	for(i=0;i<m;i++)
	{
		if(b[i]==num)
		{
			return b[0];
		}

	}
	return -1;
 }
