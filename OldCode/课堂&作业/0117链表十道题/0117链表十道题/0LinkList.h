struct Linklist
{
	int data;
	Linklist* next;
};//��ʼ��

Linklist* Create()
{
	Linklist* p= new Linklist;
	p->next=nullptr;
	return p;
}//�����ڵ�

void AddLink(Linklist *father,int value)
{
	Linklist* p=Create();
	father->next=p;
}//���ӽڵ�

Linklist* Search(Linklist *lhead,int value)
{
	while(lhead->next!=nullptr&&lhead->next->data!=value)
		lhead=lhead->next;
	return lhead->next;
}//���ҽڵ�

Linklist* SearchFather(Linklist *lhead,int value)
{
	while(lhead->next!=nullptr&&lhead->next->data!=value)
		lhead=lhead->next;
	return lhead;
}//����ֵ�ĸ��ڵ�


void DelNode(Linklist *head,int value)
{
	Linklist *p=SearchFather(head,value);
	Linklist *record=p->next;
	p->next=p->next->next;
	delete(record);
}//ɾ���ڵ�