/* �������ַ����ֵ��ַ����ֿ�,ʹ�÷ֿ�����ַ���ǰһ���������ֺ�һ��������ĸ��
�� �硰h1ell2o3�� ->��123hello�� */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
void num_alpha(char str[])
{
	char alpha[MAX];
	char digit[MAX];
	char *alp=alpha;
	char *digi=digit;
	for(int i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i])||isdigit(str[i]))
			isalpha(str[i])?*alp++=str[i]:*digi++=str[i];
	}
	*alp='\0';*digi='\0';
	strcpy(str,digit);
	strcat(str,alpha);
}
int main()
{
	char str[MAX]="h1ell2o3sdaas12341";//b�ѷ���ĸ�����ֹ�����
	printf("%s\n",str);
	num_alpha(str);
	printf("%s\n",str);
	return 0;
}
