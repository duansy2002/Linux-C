/*һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж���������*/
#include<stdio.h>
#define N 50
int count=0;

void jumponly(int rest)
{
	if(rest==0)
	{
		count++;
		return;
	}
	else if(rest==1)
	{
		count++;
		return;
	}
	jumponly(rest-1);
	jumponly(rest-2);
}
int shitfog(int rest)
{
	if(rest==0)
		return 1;
	else if(rest==1)
		return 1;
	int method;
	method=shitfog(rest-1)+shitfog(rest-2);
	return method;
}


int main()
{
	/*int fog[N+1],i;
	fog[0]=1;
	fog[1]=1;
	for(int i=2;i<=N;i++)
		fog[i]=fog[i-1]+fog[i-2];//����*/
	//int num=shitfog(5);
	jumponly(15);
	return 0;
}
//û�뵽����ΪN��ȡֵ̫���˵������㲻��
//�����ҵĳ��򡢵ݹ������û�����
