#include<iostream>
using namespace std;
#include "tree.h"
int main()
{
	int num1[N]={1,2,3,0,4,0,5,0,0,6,0};
	int num2[N]={1,2,3,4,5,6,7,8,9};
	CreateTree(num2);
	cout<<"ǰ�������";
	VisitTree_1(node[0]);
	cout<<"\n���������";
	VisitTree_2(node[0]);
	cout<<"\n���������";
	VisitTree_3(&node[0]);
	getchar();
	return 0;
}