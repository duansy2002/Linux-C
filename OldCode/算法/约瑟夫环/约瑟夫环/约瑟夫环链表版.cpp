#include<stdio.h>
#define TOTAL 100
#define COUNT 5
struct node
{
	int num;
	node* next;
}*head;
node* createman()
{
	node* p=new node;
	p->next=NULL;
	return p;
}
node* sitaround()
{
	head=createman();
	node* father=head;
	father->num=1;
	for(int i=2;i<=TOTAL;i++)
	{
		father->next=createman();
		father->next->num=i;
		father=father->next;
	}
	father->next=head;
	return head;
}
void outman(node* father)
{
	node* p=father->next->next;
	delete(father->next);
	father->next=p;
}

int main()
{
	head=sitaround();
	node* surviver=head;
	while(surviver->next!=surviver)//��ʣһ���ˣ��Լ�����һ��ָ���Լ�
	{
		for(int i=1;i<COUNT-1;i++)//surviver��ʼֵ��1,���Դ�1��ʼ����Ϊoutman����ֱ��ɾ����һ���ˣ����Բ�����count-1ִ��
			surviver=surviver->next;
		outman(surviver);//����COUNT���˲�������ֱ������
		surviver=surviver->next;//�������˺�����˿�ʼ����
	}
	printf("surviver is : No.%d",surviver->num);
	return 0;
}