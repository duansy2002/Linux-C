#ifndef _IOSTREAM_
#define _IOSTREAM_
#include<iostream>
#endif
using namespace std;
const int N=16;
struct tree
{
	int data;
	tree *left;
	tree *right;
}node[N];//ע������node[N]������ģ�ֻ��Ϊ�˷��㽨����һ����Ҳ������new�ġ�
void CreateTree(tree &root,int value)
{
	root.data=value;
	root.left=root.right=NULL;
}//createtree(root,value,left&right)
void AddTree(tree &root,tree &leaf,bool choose,int value)//bool 0������������1����������
{
	if(value==0)
	{
		(choose?root.right:root.left)=NULL;
		return;
	}
	(choose?root.right:root.left)=&leaf;
	leaf.data=value;
	leaf.left=leaf.right=NULL;
}
void AddTreeFromArray(int a[])
{
	int used=0,i=0;
	bool choose=0;
	//tree * queue[N];//���ö�����ʵ�֣�����������ȫ�������������й��ɵ���һ���Ȳ�д
	CreateTree(node[0],a[used++]);
	while(used<N-1)//��ԭ��������16�޸��˱߽������������ڴ���δ����һ����ֵ�����ǿ���-1��
	{
		AddTree(node[i],node[i*2+1],0,a[used++]);
		AddTree(node[i],node[i*2+2],1,a[used++]);
		i++;
	}

}
void VisitTree_1(tree &T)//���Ե���ǰ�����������������������
//�㷨���Ӷ�ΪO(n),�ݹ鹤��ջ����ǡ��Ϊ���ĸ߶ȡ�
{
	if(&T!=NULL)//�Ҳ���else����ΪNULL��Ȼ�����������жϣ�
	{
		cout<<T.data<<'/';
		VisitTree_1(*T.left);
		VisitTree_1(*T.right);
	}
}
void VisitTree_2(tree &T)
{
	if(&T!=NULL)
	{
		VisitTree_2(*T.left);
		cout<<T.data<<'/';
		VisitTree_2(*T.right);
	}
}
void VisitTree_3(tree *T)
{
	if(T!=NULL)
	{
		VisitTree_3(T->left);
		VisitTree_3(T->right);
		cout<<T->data<<'/';
	}
}