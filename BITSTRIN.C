#include <stdio.h>
#include <conio.h>

void main()
{
	int setU[10],setA[10],setB[10],unionAB[10],intersection[10],diffAB[10],diffBA[10],i,j,flag,m,n,p,u[10],a[10],b[10];
       /*	int u[10]={1,2,3,4,5,6,7};
	int a[10]={2,3,4};
	int b[10]={3,4,5,6}; */
	clrscr();
	printf("\nEnter the no:of elements in universal set:");
	scanf("%d",&n);
	printf("\nEnter the no:of elements in set a:");
	scanf("%d",&m);
	printf("\nEnter the no:of elements in set b:");
	scanf("%d",&p);

	printf("\nEnter universal set:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&u[i]);
	}
	printf("\nEnter set a elements");
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter set b elements");
	for(i=0;i<p;i++)
	{
		scanf("%d",&b[i]);
	}

	for(i=0;i<n;i++)
	{
		setU[i]=1;
	}
	printf("Universal bit set\n    	");
	for(i=0;i<n;i++)
	{
		printf("%d ",setU[i]);
	}

	//set A
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{

			if(u[i]==a[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			setA[i]=1;
		}
		else
		{
			setA[i]=0;
		}
	}
	printf("\nBit set A\n	   ");
	for(i=0;i<n;i++)
	{
		printf("%d ",setA[i]);
	}

	//set B
	for(i=0;i<n;++i)
	{
		flag=0;
		for(j=0;j<n;j++)
		{

			if(u[i]==b[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			setB[i]=1;
		}
		else
		{
			setB[i]=0;
		}
	}

	printf("\nBit set B\n	   ");
	for(i=0;i<n;i++)
	{
		printf("%d ",setB[i]);
	}

	//Union of A and B

	printf("\nUnion of A and B\n	   ");
	for(i=0;i<n;i++)
	{
		unionAB[i]=setA[i]|setB[i];
		printf("%d ",unionAB[i]);
	}

	//Intersection of A and B
	printf("\nIntersection of A and B\n	   ");
	for(i=0;i<n;i++)
	{
		intersection[i]=setA[i]&setB[i];
		printf("%d ",intersection[i]);
	}

	//Difference of A and B
	printf("\nDifference  A - B\n	   ");
	for(i=0;i<n;i++)
	{
		if(setA[i]==1 && setB[i]==0)
		{
			diffAB[i]=1;
		}
		else
		{
			diffAB[i]=0;
		}
		printf("%d ",diffAB[i]);
	}


	//Difference of B and A
	printf("\nDifference  B - A\n	   ");
	for(i=0;i<n;i++)
	{
		if(setB[i]==1 && setA[i]==0)
		{
			diffBA[i]=1;
		}
		else
		{
			diffBA[i]=0;
		}
		printf("%d ",diffBA[i]);
	}

getch();

}
