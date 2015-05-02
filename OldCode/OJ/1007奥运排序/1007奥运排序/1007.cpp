#include<assert.h>
#include<iostream>
#include<cstdio>
using namespace std;
typedef struct nation
{
	double award[4];
	int rank[4];
}nation;
/*--------һ������,д��rank��������---------*/
void cacurank(nation* p,int nationinrank[],int size,int which)//bubble
{
	for(int i=0;i<size;i++)
	{
		//assert(nationinrank[i]<M);
		p[nationinrank[i]].rank[which]=1;
		for(int j=0;j<size;j++)
		{
			if(p[nationinrank[i]].award[which]<p[nationinrank[j]].award[which])
				p[nationinrank[i]].rank[which]++;
		}
	}

}//��ôͬʱ��¼rank����������ϣ�///��������ķ���

int min(nation p)
{//rank���ȼ����õȺ�������
	if(p.rank[0]<=p.rank[1]&&p.rank[0]<=p.rank[2]&&p.rank[0]<=p.rank[3])
		return 0;
	else if(p.rank[1]<p.rank[0]&&p.rank[1]<=p.rank[2]&&p.rank[1]<=p.rank[3])
		return 1;
	else if(p.rank[2]<p.rank[1]&&p.rank[2]<p.rank[0]&&p.rank[2]<=p.rank[3])
		return 2;
	else if(p.rank[3]<p.rank[1]&&p.rank[3]<p.rank[2]&&p.rank[3]<p.rank[0])
		return 3;
}

int main()
{
	freopen("input.txt","r",stdin);
	int M,N;
	while(scanf("%d%d",&N,&M)==2)//N��������ʾM��
	{
		//assert(M<=N);
		nation *p= new nation [N];
		for(int i=0;i<N;i++)
		{
			cin>>p[i].award[0]>>p[i].award[1]>>p[i].award[2];
			p[i].award[3]=p[i].award[1]/p[i].award[2];
			p[i].award[2]=p[i].award[0]/p[i].award[2];
		}
		//����������ϣ������������.///�Բ�ֻ����m������
		int index;
		int *nationinrank=new int [M];
		for(int i=0;i<M;i++)
		{
			scanf("%d",&nationinrank[i]);
		}
		for(int i=0;i<4;i++)
			cacurank(p,nationinrank,M,i);
		//----------�������-------
		//assert(index<N);
		for(int i=0;i<M;i++)
		{
			int record=min(p[nationinrank[i]]);
			printf("%d:%d\n",p[nationinrank[i]].rank[record],record+1);//����:������ʽ
		}
		printf("\n");
		delete(p);p=NULL;
		delete(nationinrank);nationinrank=NULL;
	}
	return 0;
}
