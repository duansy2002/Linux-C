/*���дһ������void fun(int m,int k,int xx[])
�ú����Ĺ����ǣ�����������m�ҽ���m��k����������xx��ָ��������*/
#include<iostream>
using namespace std;

int ifprime(int n)
{
	int t=0;
	for(int i=2;i<n;i++)
		if(n%i==0)
			t++;
	return (!t);
}//���������������1

void fun(int m,int k,int xx[])
{
	int t=0;
	m++;
	while(t<k)//����m*mΪ�硣�Ǵ���ģ�
	{
		if(ifprime(m))//���������
		{
			//cout<<m<<"~~~";
			xx[t++]=m;
			//t++;
		}
		m++;
	}
}

int main()
{
	int m=12,k=8,xx[100]={0};
	fun(m,k,xx);

	for(int i=0;i<k;i++)
		cout<<xx[i]<<'~';
	getchar();
}