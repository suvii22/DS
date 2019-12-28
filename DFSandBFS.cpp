#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 9
int a[N][N]={{0,1,1,0,1,0,0,0,0}
			,{0,0,0,1,1,0,0,0,0}
			,{0,0,0,0,1,1,0,0,0}
			,{0,0,0,0,1,0,0,1,0}
			,{0,0,0,0,0,1,0,0,0}
			,{0,0,0,0,0,0,1,0,1}
			,{0,0,0,1,1,0,0,1,0}
			,{0,0,0,0,0,0,0,0,0}
			,{0,0,0,0,0,0,1,1,0}};

int visited[N]={0,0,0,0,0,0,0,0,0};
int Q[N];

void BFS(int G[][N],int s)
{
	visited[s]=1;
	Q[0]=s;
	int f=-1,l=0;
	int v;
	while(f!=l)
	{
		v=Q[++f];
		for(int i=0;i<N;i++)
		{
			if(G[v][i]&&(!visited[i])) 
			{
				Q[++l]=i;
				visited[i]=1;
			}
		}
	}
	
}
static int l=-1;
void DFS(int G[][N],int s)
{
	visited[s]=1;
	Q[++l]=s;
	for(int i=0;i<N;i++)
	{
		if(G[s][i]&&(!visited[i])) DFS(G,i);
	}
	
}

int main()
{
 	DFS(a,0);
 	printf("DFS:  ");
 	for (int i=0;i<N;i++)
 		printf("%d ",Q[i]);
 	printf("\n");
 	
 	memset(Q,0,sizeof(Q));
 	memset(visited,0,sizeof(visited));
 	
	BFS(a,0);
	printf("BFS:  ");
	for (int i=0;i<N;i++)
		printf("%d ",Q[i]);
	printf("\n");
	return 0;
}







