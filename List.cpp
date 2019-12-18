#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LIST_LENGTH 128
typedef struct Student
{
	char name[16];
	char id[16];
	int score;

};
typedef struct SeqStudentListByArray
{
	Student student[MAX_LIST_LENGTH];
	int count;
};
struct SeqStudentListByArray* g_studentListMgr;
bool InitializeList()
{
	g_studentListMgr = (SeqStudentListByArray*)malloc(sizeof(SeqStudentListByArray));
	if (g_studentListMgr == NULL) return false;
	else
	{
		g_studentListMgr->count = 0;
		return true;
	}

}
bool insert(Student value, int index)      //best:O(1) worst:O(n) average:O(n/2)         
{
	int pos;
	if (index > g_studentListMgr->count+1 || g_studentListMgr->count == MAX_LIST_LENGTH) return false;
	else
	{
		for (pos = g_studentListMgr->count - 1; pos >= index - 1; pos--)
		{
			g_studentListMgr->student[pos + 1] = g_studentListMgr->student[pos];
		}
		g_studentListMgr->student[index - 1] = value;
		g_studentListMgr->count++;
		return true;
	}
}     
bool remove(int index)
{
	int pos;
	if (index > g_studentListMgr->count + 1 || g_studentListMgr->count == MAX_LIST_LENGTH) return false;
	else
	{
		for (pos = index - 1; pos <= g_studentListMgr->count - 1; pos++)
		{
			g_studentListMgr->student[pos] = g_studentListMgr->student[pos + 1];
		}
		g_studentListMgr->count--;
		return true;
	}
}
bool get(int index, Student &value)
{
	if (index > g_studentListMgr->count + 1 || g_studentListMgr->count == MAX_LIST_LENGTH) return false;
	else
	{
		value = g_studentListMgr->student[index - 1];
		return true;
	}
}
bool locate(const char* name, Student &value)
{
	int pos;
	for (pos = 0; pos <= g_studentListMgr->count - 1; pos++)
	{
		if (!strcmp(g_studentListMgr->student[pos].name,name))
		{
			value = g_studentListMgr->student[pos];
			return true;
		}
		
	}
	return false;
}
void Union(SeqStudentListByArray *list1, SeqStudentListByArray *list2)
{
	int pos1, pos2, find;
	for (pos2 = 0; pos2 < list2->count; pos2++)
	{
		find = 0;
		for (pos1 = 0; pos1 < list1->count; pos1++)
		{
			if (!strcmp(list1->student[pos1].id,list2->student[pos2].id)&&!strcmp(list1->student[pos1].name, list2->student[pos2].name)&&list1->student[pos1].score== list2->student[pos2].score)
			{
				find = 1;
				break;
			}
			if (!find)
			{
				list1->student[list1->count++] = list2->student[pos2];
			}
		}
	}
}
int main()
{
	int i;
	InitializeList();
	struct Student s1={"a","123",95};
	struct Student s2={"b","124",96};
	struct Student s3={"c","125",97};
	struct Student s4,s5;
    insert(s1,1);
    insert(s2,2);
    insert(s3,3);
     for(i=0;i<g_studentListMgr->count;i++)
    	printf("%d ",g_studentListMgr->student[i].score);
    printf("\n");
    remove(1);
    get(1,s4);
    locate("c",s5);
    for(i=0;i<g_studentListMgr->count;i++)
    	printf("%d ",g_studentListMgr->student[i].score);
    printf("\n");
    printf("%d",s4.score);
    printf("\n");
    printf("%d",s5.score);
    printf("\n");
    return 0;
}