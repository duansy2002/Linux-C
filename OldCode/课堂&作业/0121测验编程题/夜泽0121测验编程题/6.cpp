//����һ���������� L1 ��ֳ��������� L2��L3��
//һ�������ϵ�ֵȫ���� ��������һ�������ϵ�ֵȫ����ż����

#include<stdio.h>
#include<stack>
using namespace std;

typedef struct LinkList
{
	int num;
	LinkList *next;
}node,*pnode;

void Solution(node *L1,node *L2,node *L3)
{
	stack<node*> odd,even;
	odd.push(NULL);
	even.push(NULL);
	node *visit=L1->next;
	while(visit)
	{
		if(visit->num%2==0)
			even.push(visit);
		else
			odd.push(visit);
		visit=visit->next;
	}
	node *oddconnect=L2;
	node *evenconnect=L3;
	while(!odd.empty())
	{
		oddconnect->next=odd.top();
		odd.pop();
		oddconnect=oddconnect->next;
	}
	while(!even.empty())
	{
		evenconnect->next=even.top();
		even.pop();
		evenconnect=evenconnect->next;
	}
}
