#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
/*.�׻�˵�������������ɹ������ĳ�˴� 1990 �� 1 �� 1 ����ʼ�������������ɹ������
���� ��������Ժ��ĳ�����ڡ����㡱���ǡ�ɹ����*/
int monthday[12]={0,31,28,31,30,31,30,31,31,30,31,30};
int betweendata(int,int,int);
int uptoday(int,int,int);
int uptoday(int year,int month,int day)
{
	int count=0;
	bool addyear=false;
	if(year%400==0||(year%4==0&&year%100!=0))
		addyear=true;
	int whole=365+addyear;
	for(int i=1;i<month;i++)
		count=count+monthday[i];
	if(month>=3)
		count+=addyear;
	count+=day;
	return whole-count;
}
bool catchfish(int num)
{
	if(num%5<=3&&num%5!=0)
		return 1;
	else 
		return 0;
}

int main()
{
	int year[2],month[2],day[2];
	year[0]=1990;month[0]=1;day[0]=0;
	printf("�������ڣ����� 2222 2 22:\n");
	while(scanf("%d%d%d",&year[1],&month[1],&day[1])==3)
	{
		int num=0;
		int flag=0;if(year[0]>year[1]) flag=1;
		for(int i=year[flag];i<=year[1-flag];i++)
		{
			num+=uptoday(i,month[flag],day[flag]);
			month[flag]=1;day[flag]=0;
		}//���㻹�м����Ԫ��
		num-=uptoday(year[1-flag],month[1-flag],day[1-flag]);
		printf(catchfish(num)?"����\n":"ɹ��\n");
	}
}