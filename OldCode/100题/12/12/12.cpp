/*12: ���г�������n��n�Ķ�ά���飬�����������и�ֵ��
���д����fun,�����Ĺ��ܣ�
ʹ��������ܱ�Ԫ�ص�ƽ��ֵ����Ϊ����ֵ���ظ��������е�s�� */
const int N=3;
#include<iostream>

double fun(int a[][N])
{
	double s=0;
	int k=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(i==0||j==0||i==(N-1)||j==(N-1))
			{
				s=s+a[i][j];
				k++;
			}
		}
		return (s/k);
}

int main()
{
	int a[][N]={{1,2,3},{4,5,6},{7,8,9}};
	double aver;
	aver=fun(a);
	std::cout<<aver;
	getchar();
}