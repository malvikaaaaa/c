#include<stdio.h>
#include<conio.h>
int n,a[10];
void arr_insert();
void arr_delete();
void arr_display();
void main()
{
	int i,ch;
	clrscr();
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter Array\n");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Array\n");
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	do
	{
	printf("\nSelect\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: arr_insert();
			break;
		case 2: arr_delete();
			break;
		case 3: arr_display();
			break;
		default: exit();
	}
	}while(ch!=0);
	getch();
}
void  arr_insert()
{
	int pos,num,i;
	printf("Enter the position to be inserted\n");
	scanf("%d",&pos);

	if(pos<1 || pos>n+1)
	{
		printf("Invalid Position\n");
	}
	else
	{
		printf("Enter the value to be inserted\n");
		scanf("%d",&num);
		pos--;
		for(i=n+1;i>pos;--i)
		{
			a[i]=a[i-1];
		}
		a[i]=num;
		n++;
	}

}

void arr_delete()
{
	int num,flag,i,j;
	printf("Enter the value to be deleted\n");
	scanf("%d",&num);
	flag=0;
	for(i=0;i<n;++i)
	{
		if(a[i]==num)
		{
			flag++;
			for(j=i;j<n;++j)
				a[j]=a[j+1];
			n--;
		}
	}
	if(flag==0)
		printf("Element not found\n");
	else if(flag==1)
		printf("Element deleted\n");
	else
		printf("Elements deleted\n");
}

void  arr_display()
{
	int i;
	printf("Array\n");
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
}