/*
 * =====================================================================================
 *
 *       Filename:  mst.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 09 April 2015 11:36:15  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

typedef struct edge
{
	int u,v,w;
}edge;

typedef struct node
{
	int data;
	struct node *next;
}node;

int n,m;
edge edges[100000];
int parents[100000];
node *adj[100000];

int cmpfunc(const void *a,const void *b)
{
	const struct edge *elem1 = a;
	const struct edge *elem2 = b;
	return elem1->w - elem2->w;
}

int find(int x)
{
	if(parents[x]==-1)
		return x;
	return parents[x] = find(parents[x]);
}
	
void un(int x,int y)
{
	parents[x] = y;
}

long long int ans=0;

void kruskal()
{
	int i;
	for(i=0;i<n;i++)
		parents[i] = -1;
	int e=0;
	i=0;
	while(e < (n-1))
	{
		int x = find(edges[i].u);
		int y = find(edges[i].v);

		if(x != y)
		{
			ans += (long long int)edges[i].w;
			//printf("%d %d\n",edges[i].u,edges[i].v);
			un(x,y);
			e++;
		}
		i++;
	}
}

int visited[100000];

void dfs(int index)
{
	visited[index]=1;
	node *temp;
	temp = adj[index];
	while(temp!=NULL)
	{
		if(visited[temp->data]!=1)
			dfs(temp->data);
		temp=temp->next;
	}
}

int check_dfs()
{	
	dfs(0,0);
	int i;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			return 0;
	}
	return 1;
}

int main()
{
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<n;i++)
		adj[i]=NULL;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
		node *new1,*new2; 
		new1 = (node *)malloc(sizeof(node));
		new2 = (node *)malloc(sizeof(node));
		new1->data = edges[i].u-1;
		new2->data = edges[i].v-1;
		new1->next = new2->next = NULL;
		new1->next = adj[edges[i].v-1];
		new2->next = adj[edges[i].u-1];
		adj[edges[i].v-1] = new1;
		adj[edges[i].u-1] = new2;
	}
	/*for(i=0;i<n;i++)
	{
		node *temp;
		temp = adj[i];
		printf("i=%d\n",i);
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}*/
	qsort(edges,m,sizeof(edge),cmpfunc);
	if(check_dfs()==1)
	{
		kruskal();
		printf("%lld\n",ans);
	}
	else
		printf("-1\n");
	return 0;
}
