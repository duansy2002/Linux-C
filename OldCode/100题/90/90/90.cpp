/*��90�� ���д����fun���书���ǣ����㲢������ж���ʽֵ:sn=(1-1/2)+(1/3-1/4)+��+(1/(2n-1)-1/2n)*/
#include<iostream>

double fun(int n)
{
	double sum=0;
	double one;
	for(int i=1;i<=n;i++)
	{
		one=1/(2*i-1.0)-1/double(2*i);
		sum=sum+one;
	}
	return sum;
}

int main()
{
	int n=10;
	std::cout<<fun(n);
	getchar();
}