/*��1�� m���˵ĳɼ������score�����У����д����fun
���Ĺ����ǣ�������ƽ���ֵ�������Ϊ����ֵ���أ�
������ƽ���ֵķ�������below��ָ���ĺ����С�*/
#include<iostream>
int fun(int score[],int m,int below[])
{
	float aver=0;
	for(int i=0;i<m;i++)
		aver=aver+score[i];
	aver=aver/m;//����ǡ����һ��������������float���ο���ʽת��
	std::cout<<"aver="<<aver<<'\n';
	int j=0;
	for(int i=0;i<m;i++)
	{
		if(score[i]<aver)
			below[j++]=score[i];
	}
	return(j);
}

int main()
{
	int score[10]={1,2,3,4,5,6,7,8,9,10},m=9;
	int below[10]={0};
	int N=fun(score,m,below);
	std::cout<<"N="<<N<<'\n';
	int i=0;
	while(below[i])
	{
		std::cout<<below[i++]<<'-';
	}
	getchar();
	return 0;
}