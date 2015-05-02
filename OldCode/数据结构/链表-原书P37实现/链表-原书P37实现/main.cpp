#include "Linkedlist.h"

LinkInfo* CreateInfoFromArray(int a[],int size)
{
	LinkInfo *p=CreateLinkInfo();
	node* father=p->head;
	for(int i=0;i<size;i++)
	{
		p->tail=CreateSonNode(father,a[i]);
		p->listlen++;
		father=father->next;
	}
	return p;
}

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	//��������
	LinkInfo *L=CreateInfoFromArray(a,10);
	//1-������ת
	ReverseList(L);
	ReverseList(L);
	//2-������K������֤
	node* last[11];
	for(int i=0;i<11;i++)
		last[i]=lastK(*L,i+1);
	//3-�м�Ԫ��
	node* mid=FinMid(*L);
	//4-ɾ����ͷ���
	//DelNoHead(L->head->next);
	//5-��������ϲ�
	int a1[5]={5,5,4,3,1};
	int b1[3]={7,4,2};
	LinkInfo *p=CreateInfoFromArray(a1,0);//���԰���: 1-p,q ���� 2-p,q�ݼ� 3-pΪ�� 4-qΪ�� 5-p,q��Ϊ��
	LinkInfo *q=CreateInfoFromArray(b1,3);
	MergeList(p,q);
	//6-�ж������Ƿ��л��������ػ������node*��
	LinkInfo *circle=CreateInfoFromArray(a,6);//���ԣ��л����޻���������
	node *nocross=IfCircle(circle->head);
	circle->tail->next=circle->head->next->next->next;//����һ����
	node *cross=IfCircle(circle->head);
	//7+8-�����������Ƿ��ཻ���󽻵�
	LinkInfo *A=CreateInfoFromArray(a1,5);//���ԣ�1-������ 2- ���� 3- ������
	LinkInfo *B=CreateInfoFromArray(b1,3);
	node *nointersection1=Intersection1(A->head,B->head);
	node *nointersection2=Intersection2(A->head,B->head);//NULL
	B->tail->next=A->head->next->next->next;//���ý������4
	node *intersection1=Intersection1(A->head,B->head);
	node *intersection2=Intersection1(A->head,B->head);// 4
	//9-����������
	int s[10]={54,41,32,1,6,4,54,32,658,2};
	LinkInfo *linksort=CreateInfoFromArray(s,10);
	LinkSortQ(linksort,0);
	//10-ɾ���ظ�Ԫ��
	DelRepeated(linksort);
	//11-�������
	LinkInfo *odd=CreateLinkInfo();
	LinkInfo *even=CreateLinkInfo();
	SplitList(L,odd,even);
	//12-�������ӷ�
	char numa[]="-7987465413213546465461111111111";
	char numb[]="-574968465216352468749611";
	char* result=BigNum(numa,numb);
	return 0;
}
