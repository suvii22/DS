#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct StudentNode
{
	char name[16];
	char id[16];
	int score;
	struct StudentNode* nextAddr;
}StudentNode;

typedef struct SeqStudentList
{
	struct StudentNode * head;
	struct StudentNode * tail;
	int count;
};

struct SeqStudentList g_studentListMgr;
bool Initialize()
{
	g_studentListMgr.head = NULL;
	g_studentListMgr.tail = NULL;
	g_studentListMgr.count = 0;
	return true;
}
bool insert(const char* name, const char* id, int score)
{
	StudentNode* tmpNode = (StudentNode*)malloc(sizeof(StudentNode));
	if (tmpNode != NULL) {
		strcpy_s(tmpNode->name, name);
		strcpy_s(tmpNode->id, id);
		tmpNode->score = score;
		tmpNode->nextAddr = NULL;
		if (g_studentListMgr.head == NULL) {
			g_studentListMgr.head = g_studentListMgr.tail = tmpNode;
		}
		else {
			g_studentListMgr.tail->nextAddr = tmpNode;
			g_studentListMgr.tail = tmpNode;
		}
		g_studentListMgr.count++;
		return true;
	}
	else {
		return false;
	}
}
bool get(int index, struct StudentNode& value) //index从1开始
{
	if (index > g_studentListMgr.count - 1 || g_studentListMgr.count == 0) {
		return false;
	}
	else {
	    StudentNode* tmpNode = g_studentListMgr.head;
		while (--index > 0) {
			tmpNode = tmpNode->nextAddr;
		}
		value = *tmpNode;
		return true;
	}
}

bool locate(const char* name, struct StudentNode& value)
{
	struct StudentNode* tmpNode = g_studentListMgr.head;
	while (tmpNode != NULL) {
		if (!strcmp(tmpNode->name, name)) {
			value = *tmpNode;
			return true;
		}
		else {
			tmpNode = tmpNode->nextAddr;
		}
	}
	return false;
}
bool remove(int index) //index从1开始 
{
struct  StudentNode *tmpNode, *tmpPreNode;
if (index > g_studentListMgr.count - 1 || g_studentListMgr.count == 0) {
	return false;
}
else 
  {
	tmpPreNode = tmpNode = g_studentListMgr.head;
	    while (--index > 0) 
	    {
		tmpPreNode = tmpNode;
		tmpNode = tmpNode->nextAddr;
	    }
		if (tmpPreNode == tmpNode) 
		{ //head
			g_studentListMgr.head = tmpNode->nextAddr;
		}
		else 
		{
			tmpPreNode->nextAddr = tmpNode->nextAddr;
		} //head
	    if (g_studentListMgr.tail == tmpNode) 
	    { //tail
		    if (tmpPreNode == tmpNode) 
		    {
			  g_studentListMgr.tail = NULL;
		    }
		    else 
		    {
			  g_studentListMgr.tail = tmpPreNode;
	        }
	    } //tail
	free(tmpNode);
	return true;
  }
}
void Union(SeqStudentList* list1, SeqStudentList* list2)
{
	struct StudentNode *tmpPtr, *tmpNode1, *tmpNode2 = list2->head;
	while (tmpNode2 != NULL) {
		tmpNode1 = list1->head;
		while (tmpNode1 != NULL) {
			if (!strcmp(tmpNode1->id, tmpNode2->id)) {
				tmpPtr = tmpNode2;
				tmpNode2 = tmpNode2->nextAddr;
				free(tmpPtr);
				break;
			}
			else { tmpNode1 = tmpNode1->nextAddr; }
		}
		if (tmpNode1 == NULL) {
			tmpPtr = tmpNode2;
			tmpNode2 = tmpNode2->nextAddr;
			tmpPtr->nextAddr = list1->head;
			list1->head = tmpPtr;
		}
	}
}
int main()
{
	return 0;
}