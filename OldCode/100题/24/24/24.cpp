/*��24�� ���дһ������fun�����Ĺ����ǣ�
��һ���ַ���ת��Ϊһ������
(���õ���c�����ṩ�Ľ��ַ���ת��Ϊ�����ĺ���)��*/
#include<iostream>
using namespace std;
int fun(char *s)
{
	char *p=s;
	int num=0,count=1;

	if(*p=='+')//������==�ˡ�����
	{
		count=1;
		p++;
	}
	else if(*p=='-')
	{
		count=-1;
		p++;
	}

	while(*p)
	{
		if(*p<48||*p>57)
		{
			cout<<"ERROR!NOT A NUMBER!";
			getchar();
			exit(0);
		}
		num=num*10+(*p-48);
		p++;
	}
	num=num*count;
	return num;
}

int main()
{
	char s[]="-1241512363";
	int num=fun(s);
	cout<<num<<"===";
	getchar();
}