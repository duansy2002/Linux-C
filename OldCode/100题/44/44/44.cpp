/*��44�� ��дһ���������ú�������
ͳ��һ������Ϊ2���ַ�������һ���ַ����г��ֵĴ�����*/
#include<iostream>
int fun(char s[],char a[2])
{
	char *p=s;
	int count=0;
	while(*p)
	{
		if(*p==a[0]&&*(p+1)==a[1])
			count++;
		p++;
	}
	return count;
}

int main()
{
	char s[]="hjhgdgffhfbdxghfdthyrds";
	char a[]="hg";
	std::cout<<fun(s,a);
	getchar();
}