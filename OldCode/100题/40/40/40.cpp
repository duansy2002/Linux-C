/*��40�� ���д����fun���ú����Ĺ�����
�ƶ��ַ��������ݣ��ƶ��Ĺ������£�
�ѵ�1����m���ַ���ƽ�Ƶ��ַ��������
�ѵ�m��1�������ַ��Ƶ��ַ�����ǰ����*/

#include<iostream>
using namespace std;

void move(char a[],int m)
{
	int n=strlen(a);

	for(int i=0;i<m;i++)//��ʼд����while��*p��������������*p=0��ʱ���Զ�����ѭ��������һ��ֵ��ע������� 
		*(a+n+i)=a[i];
	for(int i=0;i<n;i++)
		a[i]=a[i+m];//*newhead++;

	a[n/*strlen(a)//��ʱ��strlen(a)�ı��ˣ����Բ���������������n*/]='\0';

}

int main()
{
	char a[]="123456789/*-";
	int m=5;
	move(a,m);
	for(int i=0;i<strlen(a);i++);
		cout<<a;
	getchar();
}