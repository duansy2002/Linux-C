#include "Linkedlist.h"
void ReverseList(LinkInfo *L)//�м����ʵ��
{
	node *son,*grandson;
	node *headrecord=L->head;
	son=headrecord->next;
	L->head=NULL;
	L->tail=son;
	while(son!=NULL)
	{
		grandson=son->next;
		son->next=L->head;
		L->head=son;
		son=grandson;
	}
	headrecord->next=L->head;
	L->head=headrecord;
}

//�ݹ�ʵ�֣������䣩