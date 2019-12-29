#include<iostream>
#include<string.h> 
using namespace std;
 
#define MAX 10			//������������ֵ
 
struct ArcNode
{
	int to;
	struct ArcNode *next;
};
 
int n, m;				//�������������
ArcNode *List[MAX];		//ÿ������ı������ͷָ��
int count[MAX];			//����������
char output[100];		//�������
 
void TopSort()
{
	int i, top = -1;
	ArcNode *temp;
	bool bcycle = false;	//�Ƿ�������򻷵ı�־
	int pos = 0;			//д��output�����λ��
	for(i = 0; i < n; i++)	//���Ϊ0�Ķ�����ջ
	{
		if(count[i] == 0) 
		{
			count[i] = top; 
			top = i;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(top == -1)		//ջΪ�գ����������·
		{
			bcycle = true;
			break;
		}
		else
		{
			int j = top; top = count[top];		//ջ������j��ջ
			pos += sprintf(output+pos, "%d ", j+1);
			temp = List[j];
			//��������j�ı�����ÿ�����ߵ��յ����ȼ�1
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
		output[pos-1] = '\n';	//ȥ�����Ŀո�
		printf(output);
	}
}
int main()
{
	int i, u, v;		//ѭ���������ߵ������յ�
	while(1)
	{
		scanf("%d%d", &n, &m);	//���붥�����������
		if(n == 0 && m == 0) break;
		memset(List, 0, sizeof(List));
		memset(count, 0, sizeof(count));
		memset(output, 0, sizeof(output));
		ArcNode *temp;
		for(i = 0; i < m; i++)		//������
		{
			scanf("%d%d", &u, &v);
			u--; v--;
			count[v]++;
			temp = new ArcNode;
			temp->to = v; temp->next = NULL;	//�����ڽӱ�
			if(List[u] == NULL) List[u] = temp;
			else
			{
				temp->next = List[u];
				List[u] = temp;
			}
		}
 
		TopSort();
 
		for(i = 0; i < n; i++)					//�ͷű������ϸ��߽����ռ�õĴ洢�ռ�
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

