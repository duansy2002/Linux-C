/*��15�� ���дһ������unsigned fun(unsigned w)
w��һ������10���޷���������
��w��n(n��2)λ���������������w��n��1λ������Ϊ����ֵ���ء�*/
#include<iostream>
#include<stdio.h>
using namespace std;

unsigned fun(unsigned w)
{
	if(w<10)
	{
		cout<<"ERROR!";
		return -1;
	}
	char a[64],b[64];
	itoa(w,a,10);//���ַ�ʽ�����ԣ�10��ʾ����ʮ����
	//sprintf(a,"%d",w);//sprintf������~��
	//itoa��ֻ������ת�����ַ���, sprintf�ǰ���ָ����ʽ���һ��Ŀ���ַ���������sprintf���ܸ���..
	int i=0;
	while(a[i])1
	{
		b[i]=a[i+1];
		i++;
	}
	w=atoi(b);//atoi��������~����
	return(w);
}

int main()
{
	unsigned w=815123;
	w=fun(w);
	cout<<w;
	getchar();
}