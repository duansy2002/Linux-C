#ifndef _TREE_H_
#define _TREE_H_
#include<iostream>
#include "tree.h"
#endif
#include<stdio.h>
const int M=5;
int a[M]={1,2,4,5,3};
int b[M]={4,2,5,1,3};
int *queue=a;
//���ƶ���һ���ı�����������¼�ĸ�ֵ��δ��ѯ������Ϊ�ݹ�����ⲻ����a[]�в��Ҹ��ڵ�ֵȻ��Ǳ�+1����Ϊ��һ�����ڵ�ֵ

tree* createnode_dynamic()
{
	tree *p=new tree;
	p->left=p->right=NULL;
	return p;
}//������½������ڴ������ָ��ֵ�������ӭ�ж����ˣ�

int FindValueInA(int array[],int find)
{
	for(int i=0;i<M;i++)
		if(array[i]==find)
			return i;
	return -1;
}

void DivideAndFind_Tree(tree *root,int top,int end)
{
	if(top>end)
		return;
	int root_in_a=FindValueInA(a,root->data);
	//�������a[]�з���ֵΪ-1����������ͷ��㣬����������Ϊ�ؽ���Ľ����
	int root_in_b=FindValueInA(b,root->data);
	if(root_in_a+1>=5)//���鳬�ˣ�����û����һ����Ҳ���ǲ������
	{
		//printf("return because next root do not exsist:\n");
		return;
	}
	int next_root_value=*queue;//int cut = find next root in top-end;
	int next_root_in_b=FindValueInA(b,next_root_value);
	tree* p=createnode_dynamic();//create a new memory
	if(next_root_in_b<root_in_b)//��仰ʹ�����еķ�ͷ��㶼���Ҳ���.�������FindValueInA�ķ���ֵΪM���Ա��������
	{
		root->left=p;
		root->left->data=next_root_value;
		queue++;
	}//if root.value in right, root->left=p;
	else if(next_root_in_b>root_in_b)
	{
		root->right=p;
		root->right->data=next_root_value;
		queue++;
	}//if root.value in left, root.right=p;
	else //if equal....I don't know
		return;
	DivideAndFind_Tree(p,top,next_root_in_b-1);
	DivideAndFind_Tree(p,next_root_in_b+1,end);
}
//��ʼ�ڵ㻮���� ���������м��������ݹ�.�ӵݹ鲻�С������������л���һ�ΰ�.���뷽���Ǽ�ͷ���..��Ȼȥ���Ǿ�Ͷ��ˡ�����������
//ԭֵҪ�ö��У���Ȼ�ݹ��ȥ���Ҵ���
//�������ˣ��Ҳ���next value��������ѭ��