/*��16�� ���дһ������float fun(double h),
�����Ĺ���ʹ�Ա���h�е�ֵ����2λС����
���Ե���λ������������(�涨h�е�ֵλ����)��*/
#include<iostream>
using namespace std;
float fun(double h)
{
	/*int last;
	last=int(10*(h*100-int(h*100)));
	if(last<5)
		h=int(100*h)/100.0;
	else
		h=(int(100*h)+1)/100.0;*/

	h=int((h*1000+5)/10)/100.0;

	return h;
}

int main()
{
	double h=1.2395;
	h=fun(h);
	cout<<h<<"~~~";
	getchar();
}