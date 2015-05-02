#ifndef _TREE_H_
#define _TREE_H_
#include "tree.h"
#endif
#include<stdio.h>
tree rebuild[N];
int rebuild_count=0;
const int M=5;
int a[M]={1,2,3,4,5};
int *queue=a;
int b[M]={3,2,5,4,1};
tree* createnode()
{
	tree *p=&rebuild[rebuild_count];
	rebuild_count++;
	return p;
}
tree* createnode_dynamic()
{
	tree *p=new tree;
	p->left=p->right=NULL;
	return p;
}//������½������ڴ������ָ��ֵ�������ӭ�ж����ˣ�
//��������Ҫ�Ļ��ǿ�ͷ���ж�����

int FindValueInA(int array[],int find)
{
	for(int i=0;i<M;i++)
		if(array[i]==find)
			return i;
	return -1;
}

void DivideAndFind_Tree(tree *root,int top,int end)
{
	cout<<"Divide in "<<top<<" to "<<end<<" root's value is :"<<root->data<<'\n';
	if(top>end)
	{
		printf("return because top>end\n");
		return;
	}
	/*if(root->data<0)
	{
		//root->data=*queue++;
		return;
	}*/
	int root_in_a=FindValueInA(a,root->data);
	//�������a[]�д�������ͷ��㣬��ô������һ���ڵ���Ϊa[0]
	int root_in_b=FindValueInA(b,root->data);
	//���û���ˡ�if(root_in_b==-1);
	if(root_in_a+1>=5)//���鳬�ˣ�����û����һ����Ҳ���ǲ������
	{
		printf("return because next root do not exsist:\n");
		return;
	}
	int next_root_value=*queue;//int cut = find next root in top-end;
	int next_root_in_b=FindValueInA(b,next_root_value);
	tree* p=createnode_dynamic();//create a new memory
	if(next_root_in_b<root_in_b)//��仰ʹ�����еķ�ͷ��㶼���Ҳ��ˣ�
	{
		root->left=p;
		root->left->data=next_root_value;
		queue++;
		cout<<"I create ["<<next_root_value<<"] in left, father is:["<<root->data<<"]\n";
	}//if root.value in right, root->left=p;
	else if(next_root_in_b>root_in_b)
	{
		root->right=p;
		root->right->data=next_root_value;
		queue++;
		cout<<"I create :["<<next_root_value<<"]in right, father is:["<<root->data<<"]\n";
	}//if root.value in left, root.right=p;
	else //if equal....I don't know
	{
		printf("return because next root = now root\n");
		return;
	}
	printf("next root's (%d) place in b is %d\n",next_root_value,next_root_in_b);
	printf("will divide %d -- %d && %d -- %d \n",top,next_root_in_b-1,next_root_in_b+1,end);
	DivideAndFind_Tree(p,top,next_root_in_b-1);
	DivideAndFind_Tree(p,next_root_in_b+1,end);
}
//��ʼ�ڵ㻮���� ���������м��������ݹ�.�ӵݹ鲻�С������������л���һ�ΰ�.���뷽���Ǽ�ͷ���..��Ȼȥ���Ǿ�Ͷ��ˡ�����������
//ԭֵҪ�ö��У���Ȼ�ݹ��ȥ���Ҵ���
//�������ˣ��Ҳ���next value��������ѭ��