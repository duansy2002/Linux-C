/*��38�� ���д����fun�����Ĺ����ǣ�
���ss��ָ�ַ�����ָ���ַ��ĸ����������ش�ֵ��*/
#include<iostream>
int fun(char s[],char a)
{
	char *p=s;
	int num=0;
	while(*p)
	{
		if(*p==a)
			num++;
		p++;
	}
	return num;
}

int main()
{
	char s[]="helloworld!";
	std::cout<<"input a char u want to count:";
	char a=getchar();
	std::cout<<fun(s,a);
	getchar();getchar();
}