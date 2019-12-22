#include<stdio.h>
#include<string.h>
#include<iostream>
void kmp(char a[], int next[])
{
	int len = strlen(a);
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (j < len - 1)
	{
		if (k == -1 || a[j] == a[k])
		{
			j++; k++;
			if (a[k] != a[j])
			{
				next[j] = k;
			}
			else
			{
				next[j] = next[k];
			}
			
		}
		else
		{
			k = next[k];
		}
	}
}
int main()
{
	int i;
	char a[10] = "abcdabcde";
	int next[20];
	memset(next, 0, sizeof(next));
	kmp(a, next);
	for (i = 0; i < 9; i++)
	{
		printf("%d ", next[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
