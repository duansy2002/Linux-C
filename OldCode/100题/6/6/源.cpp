/*��6�� ���дһ������void fun(char a[],charb[],int n) �书���ǣ�
ɾ���Ը��ַ�����ָ���±���ַ��� 
���У�aָ��ԭ�ַ�����
ɾ������ַ��������b��ָ�������У�
n�д��ָ�����±ꡣ*/
#include<string.h>
#include<iostream>
void fun(char a[],char b[],int n)
{
	int j;
	for(int i=0;i<strlen(a);i++)
		if(i!=n)
			b[j++]=a[i];
	b[j]='\0';//�ַ�ĩβ�ǿ��ַ���
}