#include "Linkedlist.h"
void SplitList(LinkInfo *L,LinkInfo *odd,LinkInfo *even)//��ֺ�����ԭ����
{
	node *p=L->head->next;//��һ��Ԫ��
	node *odd_add=odd->head;//����
	node *even_add=even->head;//ż��
	while(p!=NULL)
	{
		//�������ż��
		odd_add->next=p;
		odd->listlen++;
		odd_add=odd_add->next;
		p=p->next;
		//�ж��Ƿ���δ��Ӷ���
		if(p==NULL)
			break;
		//Ȼ���������
		even_add->next=p;
		even->listlen++;
		even_add=even_add->next;
		p=p->next;
	}
	odd->tail=odd_add;//��дβ�ڵ���Ϣ
	odd_add->next=NULL;//���Ұ�β�ڵ����һ������
	even->tail=even_add;
	even_add->next=NULL;

	delete(L->head);
	L->head=NULL;
	delete(L->tail);
	L->tail=NULL;
	delete(L);
	L=NULL;
}