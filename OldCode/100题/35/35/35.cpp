/* ��35�� ���дһ������������ɾ���ַ����е����пո�*/

#include<iostream>
void dele(char *s)
{
	char *p=s,*write=s;
	while(*p)
	{
		if(*p!=' ')
			*write++=*p;
		p++;
	}
	*write='\0';
}

int main()
{
	char s[]="hell osad s dsdas as";
	dele(s);
	std::cout<<s;
	getchar();
}