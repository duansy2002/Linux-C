/*��25�� ���дһ������fun�����Ĺ����ǣ�
�Ƚ������ַ����ĳ��ȣ�(���õ���c�����ṩ�����ַ������ȵĺ���)��
�������ؽϳ����ַ������������ַ���������ͬ���򷵻ص�һ���ַ�����*/

#include<iostream>
using namespace std;

char* fun(char a[],char b[])
{
	char *p=a,*q=b;
	while(*p&&*q)
	{
		p++;
		q++;
	}
	return (*q)?b:a;//�߽���������Ҫ���������������ص�һ���ַ�����������Ҫ����return��˳��
}

int main()
{
	char a[]="123a46";
	char b[]="123456";
	cout<<fun(a,b);
	getchar();
}