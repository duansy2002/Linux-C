/*���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����*/
#include<stdio.h>
int count=0;

int cover_resursive(int size)
{
	if(size==0)
		return ++count;
	if(size==1)
		return ++count;
	cover_resursive(size-2);
	cover_resursive(size-1);
	return count;
}

int cover_iteration(int size)
{
	return 0;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		long long int a=1,b=1;
		while(n-1)
		{
			a=a+b;
			b=a-b;
			n--;
		}
		printf("%lld\n",a);
	}
	return 0;
}
