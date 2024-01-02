#include <stdio.h>
#include <conio.h>
int top=1,curr,found,i,j,n,x=1;
int cost[10][10],v,stack[10],visited[10],popped[10];
void dfs();
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
	stack[top]=v;
	visited[v]=1;
	dfs();
	getch();
}

void dfs()
{
	int p=0;
	while(top>=0)
	{
		found=0;
		curr=stack[top];
		for(i=1;i<=n;i++)
		{
			if(cost[curr][i]!=0 && visited[i]==0)
			{
				visited[i]=1;
				top++;
				stack[top]=i;
				found=1;
				break;
			}
		}
		if(found==0)
		{
			p++;
			popped[p]=stack[top];
			top--;
		}
	}
	printf("popped vertex:\n")
	for(i=1;i<=n;i++)
	{
		printf("%d ",popped[i]);
	}
}
