/*��3�� ���д����void fun(int x,int pp[],int *n)���Ĺ����ǣ�
���������x�Ҳ���ż���ĸ�������������С�����˳�����pp��ָ��������
��Щ�����ĸ���ͨ���β�n���ء�*/
#include<iostream>
using namespace std;

void fun(int x,int pp[],int *n)
{
	for(int i=1;i<=x;i++)
	{
		if(x%i==0&&i%2==1)
		{
			*pp++=i;
			(*n)++;//��д���������///////////////////////////////////
		}
	}
}

void main()
{
	int x=50,pp[50]={0},t=0;
	int *n=&t;
	fun(x,pp,n);
	cout<<*n<<"\n\n";
	int i=0;
	while(pp[i])
	{
		cout<<pp[i++]<<'\n';
	}
	getchar();
}