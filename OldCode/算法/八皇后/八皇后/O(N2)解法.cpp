#include<cmath>
#include<iostream>
#include<stdio.h>
using namespace std;
#define N 5
int used_colunmn[N]={0};//��¼�Ѿ�ռ�õ���
int a[N+1]={0};
int watch[N+1][N+1]={0};
int loop[N]={0};

void printqueen(int a[],int count)
{
	printf("\n%d:\n\n",count);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<a[i];j++)
			printf("| ");
		printf("|O");
		for(int j=a[i]+1;j<=N;j++)
			printf("| ");
		printf("|");
		printf("\n");
	}
}

int main()
{
	freopen("queen.txt","w",stdout);
	//for(int i=1;i<=N;i++)\�Ȳ������м����Ȱ���5��
	int count=0;
layer1:	for(loop[1]=1;loop[1]<=N;loop[1]++)//qwert���Ǹ�ֵ��ֵ,q�ǵ�һ��
	{
		memset(a,0,6*sizeof(int));
		a[1]=loop[1];
layer2:	for(loop[2]=1;loop[2]<=N;loop[2]++)
		{
			if(abs(loop[2]-loop[1])<=1)
				continue;//�����˴�
			a[2]=loop[2];
layer3:		for(loop[3]=1;loop[3]<=N;loop[3]++)
			{
				if(loop[3]==loop[1]||(abs(loop[2]-loop[3])<=1))
					continue;
				a[3]=loop[3];
layer4:			for(int r=1;r<=N;r++)
				{
					if(r==loop[1]||r==loop[2]||abs(loop[3]-r)<=1)
						continue;
					a[4]=r;
layer5:				for(int t=1;t<=N;t++)
					{
						if(t==loop[1]||t==loop[2]||t==loop[3]||abs(r-t)<=1)
							continue;
						a[5]=t;
						printqueen(a,++count);
						break;
					}
				}
			}
		}
	}
	printf("total: %d",count);
}//����ֲ�ԣ������Ƿŵ�һ�������
//д��������Ǻܿ�ģ���ʼ�����������һ��Īչ�����������벻��������İ취��5��ѭ��Ƕ�װ�
//��������Ӧ�ôӼ򵥵�ģ������Ȼ������Ӹ��ӵĹ��ܡ�
//���ַ�����һ���������Ч�ʣ�continue��������ʹ�������кܶ�������ı�����Ŀǰ�ܼ򻯵������ڲ�ѭ�������Ǹо����岻��
void caculate_queen()
{

}
/*int main()
{
	freopen("queen.txt","w",stdout);
	//for(int i=1;i<=N;i++)\�Ȳ������м����Ȱ���5��
	for(int q=1;q<=N;q++)//qwert���Ǹ�ֵ��ֵ
	{
		memset(a,0,6*sizeof(int));
		a[1]=q;
		for(loop[1]=1;loop[1]<=N;loop[1]++)
		{
			if(abs(loop[1]-q)<=1)
				continue;
			a[2]=loop[1];
			for(loop[2]=1;loop[2]<=N;loop[2]++)
			{
				if(loop[2]==q||loop[2]==loop[1]||(abs(loop[1]-loop[2])<=1))
					continue;
				a[3]=loop[2];
				for(int r=1;r<=N;r++)
				{
					if(r==q||r==loop[1]||r==loop[2]||abs(loop[2]-r)<=1)
						continue;
					a[4]=r;
					for(int t=1;t<=N;t++)
					{
						if(t==q||t==loop[1]||t==loop[2]||t==r||abs(r-t)<=1)
							continue;
						a[5]=t;
						printqueen(a,++loop[0]);
					}
				}
			}
		}
	}
	printf("total: %d",loop[0]);
}//����ֲ�ԣ������Ƿŵ�һ�������V1.1*/