#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void insert();
void search();
void inorder(struct node *root);
struct node *delet(struct node *root,int value);
struct node *minValueNode(struct node *curr);

struct node
{
	int data;
	struct node *left,*right;
}*root;

void main()
{
	int ch,value;
	clrscr();
	do
	{
		printf("\nSELECT\n1.Insert\n2.Delete\n3.Search\n4.Inorder Display\n5.Exit\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: insert();
				break;

			case 2: printf("Enter the node to be deleted\n");
				scanf("%d",&value);
				delet(root,value);
				printf("node %d deleted",value);
				break;

			case 3: search();
				break;

			case 4: inorder(root);
				break;

			default: exit(0);
		}
	}while(ch!=0);
}

void insert()
{
	struct node *newnode,*curr,*prev;
	int value;
	printf("Enter the value\n");
	scanf("%d",&value);

	if(root==NULL)
	{
		root=malloc(sizeof(struct node));
		root->data=value;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=value;
		newnode->left=NULL;
		newnode->right=NULL;

		curr=root;
		while(curr!=NULL)
		{
			prev=curr;
			if(value<curr->data)
				curr=curr->left;
			else if(value>curr->data)
				curr=curr->right;
		}
		if(value<prev->data)
			prev->left=newnode;
		else
			prev->right=newnode;
	}
	printf("node inserted\n");
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void search()
{
	int data,flag=0;
	struct node *curr;
	printf("emter the node to be searched:");
	scanf("%d",&data);

	curr=root;
	while(curr!=NULL)
	{
		if(curr->data==data)
		{
			printf("node found\n");
			flag=1;
			break;
		}
		else if(data<curr->data)
			curr=curr->left;
		else
			curr=curr->right;
	}
	if(flag==0)
		printf("node not found");
}

struct node *delet(struct node *root,int value)
{
	struct node *curr;
	if(root==NULL)
		return 0;
	else if(value<root->data)
		root->left=delet(root->left,value);
	else if(value>root->data)
		root->right=delet(root->right,value);
	else
	{
		if(root->left==NULL)
		{
			curr=root->right;
			free(root);
			return curr;
		}
		else if(root->right==NULL)
		{
			curr=root->left;
			free(root);
			return curr;
		}
		else
		{
			curr=minValueNode(root->right);
			root->data=curr->data;
			root->right=delet(root->right,curr->data);
		}
	}
	return root;
}

struct node *minValueNode(struct node *curr)
{
	while(curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}