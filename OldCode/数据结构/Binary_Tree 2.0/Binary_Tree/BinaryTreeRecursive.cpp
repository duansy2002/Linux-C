#include<iostream>

#ifndef _TREE_H_
#define _TREE_H_
#include "tree.h"
#endif // !_TREE_H_

#ifndef _REBUILD_H_
#define _REBUILD_H_
#include "rebuild.h"
#endif // !_REBUILD_H_
using namespace std;
int main()
{
	tree* head=createnode();
	head->data=-1;
	DivideAndFind_Tree(head,0,M-1);

	cout<<"ǰ�������";
	VisitTree_1(*head->right);
	cout<<"\n���������";
	VisitTree_2(*head->right);
	cout<<"\n���������";
	VisitTree_3(head->right);

	getchar();
	return 0;
}