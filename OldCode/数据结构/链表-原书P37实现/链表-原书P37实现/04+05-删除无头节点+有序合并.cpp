#include "Linkedlist.h"

void DelNoHead(node *p)
{
	if(p==NULL||p->next==NULL)
	{
		p=NULL;
		return;
	}
	node *record=p->next;
	p->data=p->next->data;
	p->next=p->next->next;
	delete(record);
}//ֱ�Ӱ���һ���ڵ��ֵ����������ת���ɾ����һ���ڵ�

LinkInfo* MergeList(LinkInfo *M,LinkInfo *N)//�ϲ�������������ֵΪ�ϲ���ͷ���
{
	node *p=M->head->next,*q=N->head->next;
	M->listlen+=N->listlen;
	if(p==NULL||q==NULL)
	{
		if(p==NULL)
		{
			M->head->next=q;
			M->tail=N->tail;
		}
		goto merge_end;
	}//pΪ������ָ��q���ɡ���qΪ����������ν
	bool increase=M->head->next->data<=M->tail->data&&N->head->next->data<=N->tail->data;//1�����������У�0����ݼ�����
	//ȷ��β�ڵ�
	M->tail=(M->tail->data>=N->tail->data?increase:!increase)?M->tail:N->tail;
	//�鲢����
	node *headrecord=M->head;
	while(p!=NULL&&q!=NULL)
	{
		if(p->data>=q->data)
		{
			headrecord->next=(increase?q:p);
			increase?q=q->next:p=p->next;
		}
		else
		{
			headrecord->next=(increase?p:q);
			increase?p=p->next:q=q->next;
		}
		headrecord=headrecord->next;
	}
	headrecord->next=(p==NULL?q:p);

merge_end:
	delete(N->head);
	delete(N);
	return M;
}
