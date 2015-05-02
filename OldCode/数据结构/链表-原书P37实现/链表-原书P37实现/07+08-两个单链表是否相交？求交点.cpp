#include "Linkedlist.h"

//˼·1����Ҫ������������������㵽�������ܾ��벻ͬ�������Ȱ����Ǳ����ͬ��
//		 ���Ǵ���������ͷ��ʼ���ʣ�ֱ��β������¼����Ȼ��ѳ����Ǹ��ƶ���Ӧ�ĳ��Ȳ�
//       ������ѭ����ÿ���ƶ�һ���ڵ�ֱ�������ڵ���ͬһ����Intersection1()
node* Intersection1(node * headA, node *headB)
{
	int count=0;
	node *p=headA;
	node *q=headB;
	while(headA!=nullptr)
	{
		count++;
		headA=headA->next;
	}
	while(headB!=nullptr)
	{
		count--;
		headB=headB->next;
	}
	headA=p;headB=q;
	if(count>0)//A is longer
		while(count--)
			headA=headA->next;
	else//B is longer
		while(count++)
			headB=headB->next;
	while(headA!=nullptr&&headB!=nullptr&&headA!=headB)
	{
		headA=headA->next;
		headB=headB->next;
	}
	return (headA==nullptr?headA:headB);
}

//˼·2�����Ż��Ľⷨ��˼·1Ҫ�߽ӽ�2N����
//		 ������֮ǰ����6�������ĺ��������˼·1Ҫ������ಽ������ΪN�������Ϊ2N����
node* Intersection2(node *headA,node *headB)
{
	node *p=headA,*q=headB;
	while(p->next!=NULL)
		p=p->next;
	node *record=p;
	p->next=q;//���컷
	node *intersection=IfCircle(headA);
	p->next=NULL;
	return intersection;
}
