/*��19�� ��д����fun,�ú����Ĺ����ǣ�
���ַ���ɾ��ָ�����ַ���ͬһ��ĸ�Ĵ�Сд����ͬ�ַ�����*/
#include<iostream>
using namespace std;
void fun(char s[],char c)
{
	int i=0;
	char *p=s;//���Թ�ֱ����sָ�룬��ʵ֤�����У���Ϊsָ��仯�Ļ���s[i]�ͻ���λ��
	while(*p)
	{
		if((*p)!=c)
			s[i++]=*p;
		p++;
	}
	s[i]='\0';
}

int main()
{
	char s[]="helloworld!";
	fun(s,'l');
	cout<<s;
	getchar();
}