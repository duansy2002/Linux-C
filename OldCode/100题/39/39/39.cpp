/* ��39�� ���д����fun���ú����Ĺ����ǣ�
�ƶ�һά�����е����ݣ�����������n��������
Ҫ����±��0��p(pС�ڵ���n��1)������Ԫ��ƽ�Ƶ���������*/
#include<iostream>
using namespace std;
const int n=10;
void move(int a[],int n,int p)
{
	for(int i=0;i<=p;i++)//��ʼд����while��*p��������������*p=0��ʱ���Զ�����ѭ��������һ��ֵ��ע������� 
		*(a+n+i)=a[i];
	for(int i=0;i<n;i++)
		a[i]=a[i+p+1];//*newhead++;
}

int main()
{
	int a[n]={1,2,3,4,5,6,7,8,9};
	int p=3;
	move(a,n,p);
	for(int i=0;i<n;i++)
		cout<<a[i]<<'~';
	getchar();
}