/*��̬��̨��*/
/*һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������n<=50*/

#include<stdio.h>
#include<math.h>
int main()
{
	long long int fogshit[51];
	fogshit[0]=1;
	fogshit[1]=1;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		/*long long int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum=sum+fogshit[i-1];
			fogshit[i]=sum;
		}*/
		printf("%lld\n",pow((long long int)2,(long long int)n));
	}
	return 0;
}
				