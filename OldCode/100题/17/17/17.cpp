/*��17�� ���дһ������fun(char *s)��
�ú����Ĺ���ʹ���ַ����е��������á�*/
#include<iostream>
using namespace std;
void fun(char *s)
{
	char *p,*q;
	p=q=s;
	while(*q)
		q++;
	q--;
	char temp;
	//cout<<*p<<" and "<<*q;
	while(p<=q)
	{
		temp=*p;
		*p=*q;//���ʳ�ͻ��
		*q=temp;
		p++;q--;
	}
}

int main()
{
	char s[]="helloworld!";
	fun(s);
	cout<<s;
	getchar();
}