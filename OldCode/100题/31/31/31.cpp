/*��31�� ���д����fun���书���ǣ�
��s��ָ�ַ����г����±�Ϊż����ͬʱasciiֵҲΪż�����ַ��⣬�����ȫ��ɾ������
����ʣ���ַ����γɵ�һ���´�����*t��ָ��һ�������С�*/
#include<iostream>
using namespace std;

char* fun(char oldchar[],char *t)
{
	char *p=oldchar;
	char *q=t;
	int i=0;
	while(*p)
	{
		if(oldchar[i]%2==0&&i%2==0)
		{
			*q=*p;
			q++;
		}
		p++;i++;
	}
	*q='\0';
	return t;
}//��ϲ�����ú��������Ե���strlenȻ����forѭ��

int main()
{
	char oldchar[]="hello!world!!!";
	char *t=new char;
	t=fun(oldchar,t);
	cout<<t;
	getchar();
}