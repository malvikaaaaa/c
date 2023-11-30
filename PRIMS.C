#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int  cost[20][20],n,t[20][20],mincost=0,nr[10],min;
void main()
{
	int i,j,b,k=0,l=0,c,p,q;
	clrscr();
	//count of vertices
	printf("enter the number of vertices:");
	scanf("%d",&n);

	//vertices in the graph

	//cost of all edges in the graph
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(i!=j)
			{
				printf("enter the cost[%d][%d]||cost[%d][%d]:",i,j,j,i);
				scanf("%d",&cost[i][j]);
				cost[j][i]=cost[i][j];
				if(cost[i][j]==0)
					{
					   cost[i][j]=999;
					   cost[j][i]=999;
					}
			}
		}
	}
	k=1;
	l=2;
	mincost=cost[1][2];               //setting mincost
	t[1][1]=k;                                              //minimum cost edge
	t[1][2]=l;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				if(cost[i][j]!=0)
				{
					if(cost[i][j]<mincost)
					{
						k=i;
						l=j;
						mincost=cost[i][j];               //setting mincost
						t[1][1]=k;                                              //minimum cost edge
						t[1][2]=l;
					}
				}
		}
	}

	//display cost of all edges in the graph
	printf("cost matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[i][j]!=999)
				printf("%d     ",cost[i][j]);
			else
				printf("0     ");
		}
		printf("\n\n");
	}
	//setting near
	for(i=1;i<=n;i++)
	{
		if(cost[i][l]<cost[i][k])
			nr[i]=l;
		else
			nr[i]=k;
	}
		printf("initial near :");
	for(i=1;i<=n;i++)
	{
		printf("%d       ",nr[i]);
	}
	printf("\n");
	nr[k]=nr[l]=0;
	for(i=2;i<=n-1;i++)
	{
	c=1;
		//finding j such that near[j]!=0 and cost is minimum
		for(j=1;j<=n;j++)
		{
			if(nr[j]!=0 && c==1)
			{
			     min=cost[j][nr[j]];
			     p=j;
			     c++;
			}
			else if(nr[j]!=0 &&c>1)
			{
				if(cost[j][nr[j]]<min)
				{
					min=cost[j][nr[j]];
					p=j;
				}
			}

		}
		t[i][1]=p;
		t[i][2]=nr[p];
		mincost+=cost[p][nr[p]];
		nr[p]=0;
		for(k=1;k<=n;k++)
		{
			if(nr[k]!=0 && cost[k][nr[k]]>cost[k][p])
				nr[k]=p;
		}
	}
	//spanning tree and mincost
	printf("result:\n");
	for(i=1;i<=n-1;i++)
	{
			for(j=1;j<=2;j++)
			{
				printf("%d      ",t[i][j]);
			}
			printf("\n\n");
	}
	printf("mincost=%d      \n",mincost);
	getch();
}
