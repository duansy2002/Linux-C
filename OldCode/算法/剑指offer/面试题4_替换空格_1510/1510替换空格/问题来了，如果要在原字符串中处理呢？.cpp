#include<stdio.h>
#include<string.h>
#define N 1000
int main()
{
	char str[N];
	char *p=str;
	int count=0;
	char ch;
	while((ch=getchar())!='\n')
	{
		if(ch==' ')
			count++;
		*p++=ch;
	}
	*p='\0';
	int length=strlen(str)+count*2;//���������ԭ����俼���˴�0��ʼ�������������Ǽӡ� ��0���Ŀռ䵼��Խ��
	for(int i=length;i>=0;i--)//i�ķ���Ҳ����
	{
		if(*p!=' ')
		{
			str[i]=*p;
			p--;
		}
		else if(*p==' ')
		{
			str[i]='0';
			str[--i]='2';
			str[--i]='%';
			p--;
		}
	}
	printf("%s",str);
	getchar();
}