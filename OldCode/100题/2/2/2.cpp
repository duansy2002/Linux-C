/*��2�� ���д����fun�����Ĺ����ǣ�
���1��100֮���ܱ�7����11������������ͬʱ��7��11��������������
�������Ƿ���a��ָ�������У�ͨ��n������Щ���ĸ���(!!!)��*/
#include<iostream>
using namespace std;
void fun(int *a,int *n)
{
	int j=0;
	for(int i=1;i<=100;i++)
	{
		if((i%7==0||i%11==0)&&i%77!=0)//�������Ż���£�&&�����ȼ�Ҫ����||����������
		{
			*a++=i;
			*n=++j;
		}
	}
}

int main()
{
	int a[100]={0},N;
	int *n=&N;
	fun(a,n);
	cout<<*n<<"\n\n";
	int i=0;
	while(a[i])
	{
		cout<<a[i++]<<'\n';
	}
	getchar();
	return 0;
}