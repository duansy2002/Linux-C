#include "Linkedlist.h"

void DelRepeated(LinkInfo *L)
{
	if(L->listlen<=1)//head->next->next==NULL;
		return;
	node *start=L->head->next;
	while(start->next!=NULL)
	{
		node *record=start->next;
		while(start->data==record->data)
		{
			L->listlen--;
			record=record->next;
			delete(start->next);
			start->next=record;//���������������ָ���¼Ҫ�ͷŵĵ�ַ����������ɾ�����������ӱȽϰ�ȫ
			if(record==NULL)
				return;//����ĩβֱ�ӽ���
		}
		start=start->next;
	}
}