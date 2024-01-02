#include <stdio.h>
#include <conio.h>
int i,j,n,x=0,cost[10][10],flag[10],span[10],k,count=1,indeg[10];
void bfs(int);
void main()
{
	clrscr();
	printf("enter the no:of vertices:");
	scanf("%d",&n);
	printf("enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter edge(%d,%d)",i,j);
			scanf("%d",&cost[i][j]);
		}
	}
	printf("adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",cost[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		indeg[i]=0;
		flag[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			indeg[i]=indeg[i]+cost[j][i];
		}
	}
	while(count<=n)
	{
		for(i=1;i<=n;i++)
		{
			if(indeg[i]==0 && flag[i]==0)
			{
				x++;
				span[x]=i;
				printf("%d ",i);
				flag[i]=1;
				for(k=1;k<=n;k++)
				{
					if(cost[i][k]==1)
					{	indeg[k]--;

				       }
			       }
		       }


		}
	count++;
	}
if(x!=n)
	printf("forms a cycle");
getch();
}
