/*10:��д����fun,���Ĺ����ǣ�
�������µļ򵥵��������󷽳�cos(x)-x=0��һ��ʵ����
�����������£�(1)ȡx1��ֵΪ0.0�� (2)x0=x1,��x1��ֵ����x0;
(3)x1=cos(x0),���һ���µ�x1;
(4)��x0-x1�ľ���ֵС��0.000001����ִ�в���(5),����ִ�в���(2);
(5)����x1���Ƿ���cos(x)-x=0��һ��ʵ������Ϊ����ֵ���ء�
�������root=0.739085��*/
#include<math.h>
#include<iostream>
double fun()
{
	double x0=0,x1;
	x1=cos(x0);
	while(abs(x0-x1)>=0.000001)
	{
		x0=x1;
		x1=cos(x0);
	}
	return x1;
}

int main()
{
	double root;
	root=fun();
	std::cout<<root;
	getchar();
}