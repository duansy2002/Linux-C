/*/ʵ��һ���ַ��滻���� rep(char* s, char* s1, char* s2),
ʵ�ֽ���֪�ַ��� s ������������ ���� s1 �е��ַ������ַ��� s2 �еĶ�Ӧ�ַ�����*/

#include<stdio.h>
#include<string.h>
#include<assert.h>
void rep(char* s,char* origin,char* replace)
{
	assert(strlen(origin)<=strlen(origin));
	for(int i=0;i<strlen(s);i++)
	{
		for(int j=0;j<strlen(origin);j++)
		{
			if(s[i]==origin[j])
				s[i]=replace[j];
		}
	}
}

int main()
{
	char s[1000],s1[1000],s2[1000];
	printf("string for s:\n");
	gets(s);
	printf("string for s1:\n");
	gets(s1);
	printf("string for s2\n");
	gets(s2);
	rep(s,s1,s2);
	printf("new string after replace:\n%s",s);

	return 0;
}
