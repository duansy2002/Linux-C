/*13: ��13�� ���дһ������void fun(int tt[m][n],int pp[n])
ttָ��һ��m��n�еĶ�ά�����顣
�����ά������ÿ������СԪ�ء�
�����η���pp��ָ��һά�����С�
��ά�����е��������������и��衣 */

#include<iostream>
using namespace std;
const int M=4,N=3;

void fun(int tt[M][N],int pp[N])
{
	int min;
	for(int i=0;i<N;i++)
	{
		min=tt[0][i];
		for(int j=0;j<M;j++)
		{
			if(tt[j][i]<min)
				min=tt[j][i];//�к��п�ʼд����
		}
		pp[i]=min;
	}
}

int main()
{
	int tt[M][N]={{1,4,5},{3,7,1},{2,10,0},{9,9,9}};
	int pp[N];
	fun(tt,pp);
	for(int i=0;i<N;i++)
		cout<<pp[i]<<" ";
	getchar();
}