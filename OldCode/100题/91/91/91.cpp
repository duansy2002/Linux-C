/*��91�� ���д����fun���书���ǣ�
��������λ����������a b�ϲ��γ�һ����������c�С�
�ϲ��ķ�ʽ�ǣ�
��a����ʮλ�͸�λ�����η���c��ʮλ��ǧλ�ϣ�
b����ʮλ�͸�λ�����η���c���ĸ�λ�Ͱ�λ�ϡ�*/
#include<iostream>
int fun(int a,int b,int c)
{
	int a1,a2,b1,b2;
	a1=a-a/10*10;
	a2=a/10;
	b1=b-b/10*10;
	b2=b/10;
	c=a1*1000+a2*10+b1*100+b2;
	return c;
}

int main()
{
	int a,b,c=0;//������c,����ʼ����ô���γɿ�ָ�룡
	a=12,b=34;
	c=fun(a,b,c);
	std::cout<<c;
	getchar();
}
/*ָ��汾������ΪC��Ҫ��ֵ���ܱ��������á�
int* fun(int a,int b,int *c)
{
	int a1,a2,b1,b2;
	a1=a-a/10*10;
	a2=a/10;
	b1=b-b/10*10;
	b2=b/10;
	*c=a1*1000+a2*10+b1*100+b2;
	return c;
}

int main()
{
	int a,b,c;
	a=12,b=34;
	c=*fun(a,b,&c);
	std::cout<<c;
	getchar();
}
*/