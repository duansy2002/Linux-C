/*��36�� �ٶ�������ַ�����ֻ������ĸ��*�š�
���д����fun�����Ĺ����ǣ�
���ַ����е�ǰ��*��ȫ���Ƶ��ַ�����β����*/
#include<iostream>
using namespace std;
char* fun(char s[])
{
	char *p=s,*q=s;
	while(*q)
		q++;
	while(*p=='*')
	{
		*q++=*p++;
		s++;
	}
	*q='\0';
	return s;
}

int main()
{
	char s[]="*b**asdsa";
	cout<<fun(s);
	getchar();
}