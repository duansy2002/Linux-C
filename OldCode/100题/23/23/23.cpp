/* ��23�� ���д����fun���ú����Ĺ����ǣ�
�ж��ַ����Ƿ�Ϊ����?
������������1�������������yes��
���򷵻�0�������������no��
������ָ˳���͵�������һ�����ַ�����*/

#include<iostream>
using namespace std;

int fun(char *s)
{
	int value=1;
	char *p,*q;
	p=q=s;

	//while(*q) q++;
	//q--;
	while(*q++); q=q-2;

	while(p<=q)
	{
		if(*p!=*q)
		{
			value--;
			break;
		}
		p++;q--;
	}
	return value;
}

int main()
{
	char s[]="abjkhja";
	int value=fun(s);	
	cout<<(value?"YES":"NO")<<"~!!";
	getchar();
	return 0;
}