#ifndef __FUNCTION_H__  
#define __FUNCTION_H__  
#include <iostream>  
  
using namespace std;  
struct tree  
{  
    int nodeValue;  
    tree *left;  
    tree *right;  
};  
  
tree * Build_Recursive(int a[], int *pPrevOrderEnd, int *pInOrderStart, int *pInOrderEnd)  
{  
    //���������������ȡ����һ��Ԫ�ؼ�Ϊ���ڵ�Ԫ��  
    int value = a[0];  
    //������ڵ�  
    tree *root = new tree;  
    root->nodeValue = value;  
    root->left = root->right = NULL;  
    //�ݹ�������������ֻʣһ��Ҷ�ӽڵ�  
    if(a == pPrevOrderEnd)  
    {  
        if(pInOrderStart == pInOrderEnd && *a == *pInOrderStart)  
            return root;  
        else  
            throw std::exception();  
    }  
    //����������������ҳ����ڵ��λ��  
    int *pInOrderCursor = pInOrderStart;  
    while(pInOrderCursor < pInOrderEnd && *pInOrderCursor != value)  
    {  
        pInOrderCursor++;  
    }  
    if(pInOrderCursor == pInOrderEnd && *pInOrderCursor != value)  
    {  
        throw std::exception();  
    }  
    //ȡ���������ĳ����Լ������������ȡ������������ʼλ��  
    int leftTreeLen = pInOrderCursor - pInOrderStart;  
    int *pPrevOrderLeftTreeEnd = a + leftTreeLen;  
    //������������ڣ���ݹ�������  
    if(leftTreeLen > 0)  
    {  
        root->left = Build_Recursive(a+1, pPrevOrderLeftTreeEnd,  
                                      pInOrderStart, pInOrderCursor-1);  
    }  
    //������������ڣ���ݹ�������  
    if((pPrevOrderEnd-a) > leftTreeLen)  
    {  
        root->right = Build_Recursive(pPrevOrderLeftTreeEnd+1, pPrevOrderEnd,  
                                       pInOrderCursor+1, pInOrderEnd);  
    }  
  
    return root;  
}  
  
tree * BulidBinaryTree(int *szPrevOrder, int *szInOrder, int nodeNum)  
{  
    if(szPrevOrder == NULL || szInOrder == NULL)  
        return NULL;  
    return Build_Recursive(szPrevOrder, szPrevOrder+nodeNum-1,  
                           szInOrder, szInOrder+nodeNum-1);  
}  
  
/*�������*/  
void PrevOrder(tree *root)  
{  
    if(root == NULL)  
        return;  
    //��  
    cout<<root->nodeValue<<' ';  
    //������  
    if(root->left != NULL)  
        PrevOrder(root->left);  
    //������  
    if(root->right != NULL)  
        PrevOrder(root->right);  
}  
  
/*�������*/  
void InOrder(tree *root)  
{  
    if(root == NULL)  
        return;  
    //������  
    if(root->left != NULL)  
        InOrder(root->left);  
    //��  
    cout<<root->nodeValue<<' ';  
    //������  
    if(root->right != NULL)  
        InOrder(root->right);  
}  
  
/*�������*/  
void PostOrder(tree *root)  
{  
    if(root == NULL)  
        return;  
    //������  
    if(root->left != NULL)  
        PostOrder(root->left);  
    //������  
    if(root->right != NULL)  
        PostOrder(root->right);  
    //��  
    cout<<root->nodeValue<<' ';  
}  
  
#endif  