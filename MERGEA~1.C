#include <stdio.h>
#include <conio.h>
int a[10],b[10];
void sort(int a[10],int);
void main()
{
	int n1,n2,i,j,k,c[10];
	clrscr();
	printf("Enter size of array 1\n");
	scanf("%d",&n1);
	printf("Enter Array 1\n");
	for(i=0;i<n1;++i)
		scanf("%d",&a[i]);
	printf("Enter size of array 2\n");
	scanf("%d",&n2);
	printf("Enter Array 2\n");
	for(i=0;i<n2;++i)
		scanf("%d",&b[i]);
	sort(a,n1);
	sort(b,n2);
	printf("\nArray 1\n");
	for(i=0;i<n1;++i)
		printf("%d ",a[i]);
	printf("\nArray 2\n");
	for(i=0;i<n2;++i)
		printf("%d ",b[i]);

	i=0;j=0;
	for(k=0;k<n1+n2;++k)
	{
	     if(i<n1 && j<n2)
	     {
		if(b[j]<a[i])
		{
			c[k]=b[j];
			j++;
		}
		else
		{
			c[k]=a[i];
			i++;
		}
	     }
	     else if(i<n1)
	     {
			c[k]=a[i];
			i++;
	     }
	     else if(j<n2)
	     {
			c[k]=b[j];
			j++;
	     }
	}
	printf("\nMerged Array \n");
	for(i=0;i<n1+n2;++i)
		printf("%d ",c[i]);
	getch();
}

void sort(int a[10],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}