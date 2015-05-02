#include<cmath>
#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
#define N 8
int used_colunmn[N]={0};//��¼�Ѿ�ռ�õ���
int a[N+1]={0};
int loop[N+1]={0};

void printqueen(int a[],int count)
{
	printf("\n%d:\n\n",count);//count֮ǰ��д��һ��++�����++����̳���ȥ�����Ա��ֵľ�������ı��+1��
	for(int i=1;i<=N;i++)
	{
		printf(" _");
	}
	printf("\n");
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<a[i];j++)
			printf("|_");
		printf("|O");
		for(int j=a[i]+1;j<=N;j++)
			printf("|_");
		printf("|");
		printf("\n");
	}
}
bool ifexsist(int layer)//loop[2]==q||loop[2]==loop[1]||(abs(loop[1]-loop[2])<=1)
{
	bool judge=0;//���꣨x,y��.���㣨loop[layer],layer��,ǰ��ĵ㣺��a[i],i��
	if(layer!=1&&abs(loop[layer]-a[layer-1])<=1)
		return 0;
	for(int i=1;i<layer;i++)
	{
		if(a[i]==loop[layer])//ע���ߵı�����loop
			return 0;
		if(abs(loop[layer]-a[i])==abs(layer-i))//����һ��б����
			return 0;
		//else //���else�ӵġ�����������һ��ʺ
	}
	return 1;
}

void guess_queen(int layer)
{
	if(layer>N) return;
	for(loop[layer]=1;loop[layer]<=N;loop[layer]++)//forѭ������,loopֵ���޸��ˣ���//��Ƶ�û����
	{		
		if(layer==1)
			memset(a,0,(N+1)*sizeof(int));
		else
		{
			if(!ifexsist(layer))
				continue;//leave
		}
		a[layer]=loop[layer];
		if(layer==N)
		{
			printqueen(a,++loop[0]);
			continue;//��ʼû��continue,����Ӱ�첻��
		}
		guess_queen(layer+1);
	}
}
int main()
{
	time_t start_tm = clock();
	freopen("queen.txt","w",stdout);
	printf("%d�ʺ����⡪����������\n",N);
	guess_queen(1);
	printf("\ntime = %d\n",clock()-start_tm);
}
//ifexist ���˴��elseд�Ĳ��ǵط��һ���Ϊ�Ǹ�����û����
//�ʺ����ڵ������ˣ�����һ���Խ�����������ʼ����Ϊд����
//�������ķ�����ȱ�㣬��������ų��ԳƵġ���ת�Ľ⣡
//�����㷨���Ӷ�Ϊn^n,��֪����õĽⷨ�ٶ���Σ�