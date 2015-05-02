#include <iostream>
#include "function.h"

using namespace std;

/*�ؽ�������*/
int main()
{
    int szPrevOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};   //���������������
    int szInOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};     //���������������
    int nodeNum = sizeof(szPrevOrder)/sizeof(int);
    tree *root = BulidBinaryTree(szPrevOrder, szInOrder, nodeNum);
    cout<<"PrevOrder: ";
    PrevOrder(root);
    cout<<endl<<"InOrder:   ";
    InOrder(root);
    cout<<endl<<"PostOrder: ";
    PostOrder(root);
    cout<<endl;
	getchar();
    return 0;
}
