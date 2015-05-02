#include<stdio.h>
typedef struct tag 
{   
	int m_ival; 
	tag* next; 
}node, *pnode; 
typedef struct tagstack 
{    
	node *m_head ;  
	//node *m_tail;
	int m_size ;
}Stack,*pStack;
void pop(Stack *stack);  //��ջ
int top(Stack *stack);//����ջ��Ԫ�� 
void push(Stack *stack, int val); //��ջ 
int empty(Stack *stack) ; //�ж�ջ�Ƿ�Ϊ�� 
int size(Stack *stack)  ; //����ջ�����ݵ�Ԫ�ظ��� 

int empty(Stack *stack)
{
	return stack->m_head->next==NULL;
}

void pop(Stack *s)
{
	if(empty(s))
		return;
	node *visit=s->m_head;
	while(visit->next->next)
		visit=visit->next;
	delete(visit->next);
	visit->next=NULL;
	s->m_size--;
}

int top(Stack *s)
{
	if(empty(s))
		return;
	node *visit=s->m_head;
	while(visit->next)
		visit=visit->next;
	return visit->m_ival;
}

void push(Stack *s, int val)
{
	node *visit=s->m_head;
	while(visit->next)
		visit=visit->next;
	node *p=new node;
	p->next=NULL;
	p->m_ival=val;
	visit->next=p;
	s->m_size++;
}

int size(Stack *stack)
{
	return stack->m_size;
}
