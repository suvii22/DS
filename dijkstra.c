#include<stdio.h>
#include<string.h>
#define INF 65535
int g[101][101];
int num;
void Initialize()
{
	int i,j;
    for(i=1;i<=num;i++)
    	for(j=1;j<=num;j++)
    	{
    		if(i==j) g[i][j]=0;
    		else g[i][j]=INF;
    	}
}
void InsertEdge(int a,int b,int w)
{
	g[a][b]=g[b][a]=w;
}
void dijkstra(int vs)
{
	int i,j,k;
	int path[num+1]; //i的前驱顶点
	int dis[num+1];  //vs->i的权值
	int flag[num+1]; //i的最短路径是否获取
	int min,tmp;
	for(i=1;i<=num;i++)
	{
		path[i]=0;
		dis[i]=g[vs][i];
		flag[i]=0;
	}
    flag[vs]=1;
	dis[vs]=0;
	//遍历num-1次，每次找出一个顶点的最短路径
	for(i=1;i<num;i++)
	{
		min=INF;
		for(j=1;j<=num;j++)
		{
			if((flag[j]==0)&&(dis[j]<min))
			{
				min=dis[j];
				k=j;
			}
		}

        //k已经获得最短路径
        flag[k]=1;
        //更新未获取最短路径的顶点的最短路径和前驱顶点
        for(j=1;j<=num;j++)
        {
        	tmp=(g[k][j]==INF?INF:(min+g[k][j]));
        	if((flag[j]==0)&&(tmp<dis[j]))
        	{
        		dis[j]=tmp;
        		path[j]=k;
        	}
        }

	}

	//print
	printf("dijkstra(%d):\n",vs);
    for(i=1;i<=num;i++)
        printf("  shortest(%d,%d)=%d\n", vs, i, dis[i]);
    
}
int main()
{
    scanf("%d",&num);
    Initialize();
    InsertEdge(1,2,10);
    InsertEdge(1,3,8);
    InsertEdge(1,4,5);
    InsertEdge(2,3,3);
    InsertEdge(2,5,7);
    InsertEdge(3,4,7);
    InsertEdge(3,6,4);
    InsertEdge(3,7,4);
    InsertEdge(4,7,10);
    InsertEdge(5,6,4);
    InsertEdge(5,8,10);
    InsertEdge(6,9,7);
    InsertEdge(7,9,3);
    InsertEdge(7,10,6);
    InsertEdge(9,10,5);
    InsertEdge(8,9,9);
    
    dijkstra(1);

    return 0;


}
