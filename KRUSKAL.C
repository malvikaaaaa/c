#include<stdio.h>
#include<conio.h>
int parent[20];
int n,i,j,cost[20][20],edgecount,count=1,mincost,c,rno,cno,v1,v2;
int find(int i)
{
	return parent[i];
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

void main()
{
	clrscr();
	printf("\nEnter the no:of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		parent[i]=i;
	printf("Enter adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter edge(%d,%d)",i,j);
			scanf("%d",&cost[i][j]);
			cost[j][i]=cost[i][j];
			if(cost[i][j]==0)
			{
				cost[i][j]=999;
				cost[j][i]=999;
			}
		}
	}
	printf("Adjacency Matrix\n");
	for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d ",cost[i][j]);
			}
			printf("\n");
		}

	edgecount=n-1;
	while(count<=edgecount)
	{
		c=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<c)
				{
					c=cost[i][j];
					v1=rno=i;
					v2=cno=j;
				}
			}
		}
		rno=find(rno);
		cno=find(cno);
		if(uni(rno,cno))
		{
			printf("\nEdge %d is (%d->%d) with cost: %d ",count++,v1,v2,c);
			mincost=mincost+c;
		}
		cost[v1][v2]=cost[v2][v1]=999;
	}
	printf("\nMinimum cost=%d",mincost);
getch();
}
