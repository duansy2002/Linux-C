/*��41�� ���д����fun���ú����Ĺ����ǣ�
��m��n�еĶ�ά�����е��ַ�����
�����е�˳�����ηŵ�һ���ַ����С�*/
#include<iostream>
using namespace std;
const int m=3,n=4;

void fun(char s[],char a[m][n])
{
	char *p = s;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			*p++=a[i][j];
	*p='\0';
}

int main()
{
	char s[m*n];
	char a[m][n]={{'a','b','c','d'},{'q','w','e','r'},{'z','x','c','v'}};
	fun(s,a);
	cout<<s;
	getchar();
}