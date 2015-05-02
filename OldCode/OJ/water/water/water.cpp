#include<iostream>
#include<cstring>
using namespace std;
const int N=10;
int wall[N]={2,5,1,2,3,4,7,7,6};
//�����Ҫ��סˮ������Ҫһ��ǽ����������ǽ��ֵ��
//�������find_peak��Ѱ�ҷ�ֵ��peak[]�д洢����wall�ĽǱꡣ
void find_peak(int wall[],int peak[])
{
	int count=0;
	if(wall[0]>wall[1])	peak[count++]=0;
	for(int i=1;i<N-1;i++)
	{
		if(wall[i-1]<=wall[i]&&wall[i+1]<=wall[i])
			peak[count++]=i;
	}
	if(wall[N-1]>wall[N-2])	peak[count++]=N-1;

}
//����������ˮ����������������֮��Ż����ˮ��
int calcu_water(int left,int right)
{
	int volumn=0;
	int board=(wall[left]<=wall[right])?wall[left]:wall[right];
	//�����壬ˮλ���Ϊ�ϵ͵ķ�ֵ������Ϊboard
	for(int i=left;i<=right;i++)
	{
		if(wall[i]<=board)
			volumn+=(board-wall[i]);
		//����board��ǽ�����ˮ�������㡣
	}
	return volumn;
}
int water(int *a)
{
	int peak[N],i=0,volumn=0;
	memset(peak,-1,sizeof(peak));

	find_peak(wall,peak);
	while (peak[i+1]>=0)
	{
		volumn+=calcu_water(peak[i],peak[i+1]);
		i++;
	}
	return volumn;
}
int main()
{
	cout<<water(wall);
	getchar();
}