/*��26�� ���дһ������fun�����Ĺ����ǣ�
�������¹�ʽ��x��ֵ(Ҫ�����㾫��0.0005����ĳ��С��0.0005ʱֹͣ����)��
x/2=1+1/3+1��2/3��5+1��2��3/3��5��7+1��2��3��4/3��5��7��9+��+1��2��3������n/3��5��7��(2n+1)
�������к�������뾫��0.0005����������Ϊ3.14����*/
#include<iostream>
using namespace std;

double fun(double accu)
{
	int top=1,bottom=1,i=1;
	double one=1,x=0;

	while(one>=accu)
	{
		x=x+one;
		top*=i;
		bottom*=(2*i+1);
		one=(double)top/bottom;
		i++;
	}
	return x;
}

int main()
{
	double accu;
	cin>>accu;
	cout<<2*fun(accu);
	getchar();getchar();
}