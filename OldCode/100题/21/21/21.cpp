/*��21�� ���д����fun,�Գ���Ϊ7���ַ����ַ�����
����β�ַ��⣬������5���ַ���ascii�뽵�����С�*/

#include<iostream>
using namespace std;

void fun(char s[])
{
	int i=1;
	for(int j=strlen(s)-2;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if(s[i]<s[j])
			{
				char temp;
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
}

int main()
{
	char s[]="hacdbfqiuwyrioquyo";
	fun(s);
	cout<<s;
	getchar();
}