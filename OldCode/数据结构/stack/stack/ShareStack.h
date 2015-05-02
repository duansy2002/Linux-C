#include "mystack.h"
#define Share 100
struct sharestack
{
	int data[Share];
	int top1;
	int top2;
}S_S;

void S_Initialize(sharestack &S)//��ʼ����ջ��ָ�벻ָ���κ�Ԫ��
{
	S.top1=-1;
	S.top2=Share;
}
bool S_StackEmpty(sharestack S)//�ж�ջ�Ƿ�Ϊ��
{
	if(S.top1==-1&&S.top2==Share)
		return true;
	else
		return false;
}
bool S_Push(sharestack &S,int a,bool choose)//��int a��ջ,bool��Ϊ1�������ջ��Ϊ0�����Ҳ�ջ
//��Ҫ�޸�S������Ҫ�õ�ַ����ʽ����ͬ
{
	if(S.top2-S.top1==1)
		return false;
	if(choose)
		S.data[++S.top1]=a;
	else
		S.data[--S.top2]=a;
	return true;
}
bool S_Pop(sharestack &S,int &x,bool choose)
{
	if(choose)
	{
		if(S.top1==-1)
		return false;
		x=S.data[S.top1--];
		return true;
	}
	else
	{
		if(S.top2==Share)
		return false;
		x=S.data[S.top2++];
		return true;
	}
}