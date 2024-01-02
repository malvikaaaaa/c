#include <stdio.h>
#include <conio.h>
int front=1,rear=1,i,j,n,x=1;
int cost[10][10],newarr[10],v,queue[10],visited[10];
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
			cost[j][i]=cost[i][j];
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
	printf("Enter the starting vertex:\n");
	scanf("%d",&v);
	queue[rear]=v;
	visited[v]=1;
	newarr[x]=v;
	bfs(v);
	if(x!=n)
	{
		printf("no spanning tree");
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",newarr[i]);
		}
	}
getch();
}

void bfs(int v)
{
	for(i=1;i<=n;i++)
	{
		if(cost[v][i]!=0 && visited[i]==0)
		{
			visited[i]=1;
			rear++;
			queue[rear]=i;
			x++;
			newarr[x]=i;
		}
	}
	if(front<rear)
	{
		front++;
		bfs(front);
	}
}