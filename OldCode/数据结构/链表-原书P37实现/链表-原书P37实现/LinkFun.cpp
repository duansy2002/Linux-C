//��ε��<���ݽṹ> P37 ����ʵ��
#include "Linkedlist.h"
node* NewNode()
{
	node* p=new node;
	p->next=nullptr;//NULL
	return p;
}

LinkInfo* CreateLinkInfo()
{
	LinkInfo *p=new LinkInfo;
	p->head=NewNode();
	p->tail=p->head;
	p->listlen=0;
	return p;
}

void AddNodeToInfo(LinkInfo *L,int data)
{
	node *p=NewNode();
	p->data=data;
	L->tail->next=p;
	L->tail=p;
	L->listlen++;
}

node* CreateSonNode(node *father,int num)//����father���ӽڵ�,����ֵΪ�ӽڵ�
{
	if(father==NULL)
		return false;
	father->next=NewNode();
	father->next->data=num;
	return father->next;
}

void FreeNode(node *start)//free�ڵ�start��ָ�Ľڵ�
{
	if(start==NULL)
		return;
	delete(start->next);
	start->next=NULL;
}


LinkInfo* InitListInfo(LinkInfo *L)//��ʼ��info
{
	L->head=NewNode();
	L->tail=L->head;
	L->listlen=0;
	return L;
}

bool DestroyList(node *L)//����������
{
	while(L!=NULL)
	{
		node *record=L->next;
		delete(L);
		L=record;
	}
	return true;
}

bool ClearList(node *LHead)//��L��Ϊ�ձ��ͷ�ԭ�ڵ�ռ�
{
	if(LHead==NULL)//ͷ���Ϊ�գ���������
		return false;
	LHead=LHead->next;
	while(LHead!=NULL)
	{
		node *record=LHead->next;
		delete LHead;
		LHead=record;
	}
	return true;
}

bool InsertHead(node *head,node *add)//ͷ�巨
{
	if(head==NULL||add==NULL)
		return false;
	add->next=head->next;
	head->next=add;
	return true;
}

bool DeleteFirst(node *head)//ɾ��ͷ�����һ���ڵ�
{
	if(head==NULL||head->next==NULL)
		return false;
	node *record=head->next->next;
	delete(head->next);
	head->next=record;
	return true;
}

bool Append(LinkInfo *LInfo,node *s)//��s��ָ��һ���ڵ�ӵ�L���棬������L��βָ��
{
	if(s==NULL||LInfo->head==NULL)
		return false;
	LInfo->tail->next=s;
	int add=1;
	while(s->next)
	{
		add++;
		s=s->next;
	}
	LInfo->tail=s;
	LInfo->listlen+=add;
	return true;
}

bool InsertBefore(LinkInfo *L,node *p,node *S)//������L��p�ڵ�ǰ����ڵ�S
{
	node *start=L->head;
	if(start==NULL||p==NULL||S==NULL)
		return false;
	while(start->next!=p)
	{
		start=start->next;
		if(start==NULL)
			return false;//û��p�ڵ㣬����false
	}
	start->next=S;
	S->next=p;
	L->listlen++;
	return true;
}

bool InsertAfter(LinkInfo *L,node *p,node *S)//������L��p�ڵ�����ڵ�S
{
	if(p==NULL||S==NULL||L->head==NULL)
		return false;
	node *rec=p->next;
	p->next=S;
	S->next=rec;
	L->listlen++;
	return true;
}

node* PrirorPos(node *head,node *p)//����p��ǰ���ڵ��λ��
{
	if(head==NULL||p==NULL)
		return NULL;
	while(head->next!=p)
	{
		head=head->next;
		if(head->next==NULL)
			return NULL;
	}
	return head;
}

node* Search(node *head,int value)//�����ڵ�
{
	if(head==NULL)
		return NULL;
	head=head->next;
	while(head!=NULL)
	{
		if(head->data==value)
			return head;
		head=head->next;
	}
	return NULL;
}
