/*��33�� �ٶ�������ַ�����ֻ������ĸ��*�š�
���д����fun�����Ĺ����ǣ�ʹ�ַ�����β����*�Ų��ö���n����
������n������ɾ�����ڵ�*�ţ������ڻ����n������ʲôҲ������
�ַ����м��ǰ���*�Ų�ɾ����*/
#include<iostream>
#include<string>
using namespace std;

char* fun(char *old)
{
	char *p=old;
	int num=0;

	while(*p)
	{
		if(*p=='*')//=�ź�==��Ҫ����
			num++;
		p++;
	}
	//ͳ��*����
	if(num<=30)
		return old;//���С��30��ֱ�ӷ��ء�
	else
	{
		p=old;
		char *dele=old;
		int count=0;

		while(*p&&count<(num-30))
		{
			*dele++=*p;
			if(*p=='*')
				count++;
			p++;
		}

		while(*p)
		{
			if(*p!='*')
				*dele++=*p;
			p++;
		}
		*dele='\0';
		return old;
	}
}

int main()
{
	char s[]="1234**************************************************5***6**7**8**9*";
	//������string��������
	cout<<fun(s);
	getchar();
}