/*ɾ���ַ�����ָ�����ַ������� ��abcdaefaghiagkl�� ɾ����a��,�Ժ� ��bcdefghigkl�� */
#include<stdio.h>
#include<string.h>
void deletech(char str[],char ch)
{
	int done=0;
	for(int i=0;i<strlen(str);i++)
	{
		while(str[i]==ch)
			i++;
		str[done++]=str[i];
	}
	str[done]='\0';
}
int main()
{
	char str[]="hello world again";
	printf("%s\n",str);
	deletech(str,'o');
	printf("%s\n",str);
	return 0;
}
