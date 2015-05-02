#include<iostream>
using namespace std;
void QuickSort(int a[],int head,int tail)
{
	if(head>=tail)
		return;
	int flag=a[head];
	int i=head,j=tail;//two pointer,i and j,
	//use a[head] as a temp container, swich it and number
	while(i<j)
	{
		while(i<j)//j-- until a[j] < flag swap
		{
			if(a[j]<flag)
			{
				a[i]=a[j];//
				/*a[j]=a[j]^a[i];
				a[i]=a[j]^a[i];
				a[j]=a[j]^a[i];*/
				break;
			}
			j--;
		}
		while(i<j)
		{
			if(a[i]>flag)
			{
				a[j]=a[i];//
				/*a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];*/
				break;
			}
			i++;

		}	//i++ until a[i]>flag; swap
	}//remember to judge : if i>j	//when j in front of i, stop
	//repeat and recurse
	a[i]=flag;//
	QuickSort(a,head,j-1);
	QuickSort(a,j+1,tail);
}
void QuickSort_Pro(int a[],int head,int tail)
{
	if(head>=tail)
		return;
	int flag=a[head];
	int i=head,j=tail;//two pointer,i and j,
	//use a[head] as a temp container, swich it and number
	while(i<j)
	{
		while(i<j&&a[j]>=flag)//j-- until a[j] < flag swap
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=flag)
			i++;
		a[j]=a[i];//i++ until a[i]>flag; swap
	}//remember to judge : if i>j	//when j in front of i, stop
	//repeat and recurse
	a[i]=flag;
	QuickSort_Pro(a,head,j-1);
	QuickSort_Pro(a,j+1,tail);
}//����ĸĶ����ǰ�if��Ƕ�ˣ�������Ӽ��
int main()
{
	int a[8]={4,9,5,2,7,3,6,8};
	QuickSort_Pro(a,0,7);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	getchar();
}
//�ܽ�һ�£�����ĵط��Ǳ߽�����������j+1д����j++���������⡣
//�Ա�֮������һ��û��Ҫ�Ĳ����������������ĵط���ͬʱwhile��Ƕ��if������if��while��Ч�ʸߡ����Ըо��ڲ�����whileûɶ�á�