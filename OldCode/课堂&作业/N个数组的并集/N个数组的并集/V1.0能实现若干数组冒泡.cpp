#include<iostream>
using namespace std;
class arr_tree
{
public:
	int *arr;
	int length;
	arr_tree* father;
	arr_tree* son;
};//ÿ������浽һ��arr_tree����ݰ��������ַarr������Ԫ�ظ���length,�������һ�����顢�������һ������

struct pointer
{
	int* p;
	arr_tree* belong;
};//��ΪҪ���أ�ָ����pointerװ������p����ʵ�ĵ�ַָ��Ԫ�أ�belong�������pָ�����ĸ�����

pointer& operator++(pointer& pt)
{
	if(pt.p-pt.belong->arr==pt.belong->length-1)
	{
		if(pt.belong->son==NULL)
		{
			pt.p=NULL;
			return pt;
		}
		pt.p=pt.belong->son->arr;
		pt.belong=pt.belong->son;
	}
	else
		pt.p++;
	return pt;
}//����++

pointer& operator--(pointer& pt)
{
	if(pt.p-pt.belong->arr==0)
	{
		if(pt.belong->father==NULL)
		{
			pt.p=NULL;
			return pt;
		}
		pt.p=pt.belong->father->arr+pt.belong->father->length-1;
		pt.belong=pt.belong->father;
	}
	else
		pt.p--;
	return pt;
}//����--

pointer& operator+(pointer& pt,int i)
{
	pointer temp=pt;
	for(int j=0;j<i;j++)
		pt++;
	return pt;
}//����+��ûд�ã���ı䴫��pointer��ֵ����++��ȫû���
/*pointer& operator+(const pointer pt,int i)
{
	pointer temp=pt;
	for(int j=0;j<i;j++)
		temp++;
	return temp;
}*/
arr_tree* create_class(int a[],int length)
{
	arr_tree* node=new arr_tree;
	node->arr=a;
	node->length=length;;
	node->father=node->son=NULL;
	return node;
}//������ŵ�arr_tree�ĳ�ʼ��
void connect(arr_tree* node1,arr_tree* node2)
{
	node1->son=node2;
	node2->father=node1;
}//��������������һ��
void bubble(pointer,pointer);
int main()
{
	int a[10]={10,2,4,999,5,6,457,8,319,10};
	int b[9]={1,222,33,47};
	int c[4]={45,353,741,0};
	arr_tree *node_a=create_class(a,10);
	arr_tree *node_b=create_class(b,4);
	arr_tree *node_c=create_class(c,4);
	connect(node_a,node_b);
	connect(node_b,node_c);
	pointer tail;
	tail.p=c+node_c->length-1;
	tail.belong=node_c;
	pointer head;
	head.p=a;
	head.belong=node_a;
	bubble(head,tail);
	while(head.p!=NULL)
	{
		printf("%d ",*head.p);
		head++;
	}
	return 0;
}
//ð������
void bubble(pointer head,pointer tail)
{//ʹ�ã�head+1����ֱ�Ӹı�head��ֵ���������+�ŷ���һ����ʱֵ?
	pointer top,next;
	top=head;
	for(pointer i=tail;i.p!=top.p;i--)
	{
		for(pointer j=top;j.p!=i.p;j++)
		{
			next=j+1;j--;
			if(next.p==NULL)
				break;
			if(*j.p>*next.p)
			{
				int temp=*j.p;
				*j.p=*next.p;
				*next.p=temp;
			}
		}
	}
}
//void quicksort(int a[],int top,int end)
//{//int top__pointer pt1\int end__pointer pt2
//	if(top>end)
//		return;
//	int flag=a[top];
//	int head=top,tail=end;	
//	while(head<tail)
//	{
//		while(a[tail]>=flag&&head<tail)
//			tail--;
//		a[head]=a[tail];
//		while(a[head]<=flag&&head<tail)
//			head++;
//		a[tail]=a[head];
//	}
//	a[tail]=flag;
//	quicksort(a,top,tail-1);
//	quicksort(a,tail+1,end);
//}