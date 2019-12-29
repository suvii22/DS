#include<iostream>
#include<string.h> 
using namespace std;
 
#define MAX 10			//顶点个数的最大值
 
struct ArcNode
{
	int to;
	struct ArcNode *next;
};
 
int n, m;			//顶点个数、边数
ArcNode *List[MAX];		//每个顶点的边链表表头指针
int count[MAX];			//各顶点的入度
char output[100];		//输出内容
 
void TopSort()
{
	int i, top = -1;
	ArcNode *temp;
	bool bcycle = false;	//是否存在有向环的标志
	int pos = 0;		//写入output数组的位置
	for(i = 0; i < n; i++)	//入度为0的顶点入栈
	{
		if(count[i] == 0) 
		{
			count[i] = top; 
			top = i;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(top == -1)		//栈为空，存在有向回路
		{
			bcycle = true;
			break;
		}
		else
		{
			int j = top; top = count[top];		//栈顶顶点j出栈
			pos += sprintf(output+pos, "%d ", j+1);
			temp = List[j];
			//遍历顶点j的边链表，每条出边的终点的入度减1
			while(temp != NULL)
			{
				int k = temp->to;
				if(--count[k] == 0)
				{
					count[k] = top;
					top = k;
				}
				temp = temp->next;
			}
		}
	}
	if(bcycle) printf("Network has a cycle!\n");
	else
	{
		output[pos-1] = '\n';	//去掉最后的空格
		printf(output);
	}
}
int main()
{
	int i, u, v;		//循环变量、边的起点和终点
	while(1)
	{
		scanf("%d%d", &n, &m);	//读入顶点个数、边数
		if(n == 0 && m == 0) break;
		memset(List, 0, sizeof(List));
		memset(count, 0, sizeof(count));
		memset(output, 0, sizeof(output));
		ArcNode *temp;
		for(i = 0; i < m; i++)		//边链表
		{
			scanf("%d%d", &u, &v);
			u--; v--;
			count[v]++;
			temp = new ArcNode;
			temp->to = v; temp->next = NULL;	//构造邻接表
			if(List[u] == NULL) List[u] = temp;
			else
			{
				temp->next = List[u];
				List[u] = temp;
			}
		}
 
		TopSort();
 
		for(i = 0; i < n; i++)					//释放边链表上各边结点所占用的存储空间
		{
			temp = List[i];
			while(temp != NULL)
			{
				List[i] = temp->next;
				delete temp;
				temp = List[i];
			}
		}
	}
	return 0;
}

