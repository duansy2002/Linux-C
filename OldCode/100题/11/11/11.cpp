/*11: ���г�������n��n�Ķ�ά���飬�������������Զ���ֵ��
���д���� fun(int a[n][n]),
�ú����Ĺ����ǣ�ʹ�������°�����Ԫ���е�ֵȫ���ó�0��*/
const int N=3;
#include<iostream>

void fun(int a[][N])
{
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			a[i][j]=0;
}

int main()
{
	int a[][N]={{1,2,3},{4,5,6},{7,8,9}};
	fun(a);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<'\n';
	}
	getchar();
}