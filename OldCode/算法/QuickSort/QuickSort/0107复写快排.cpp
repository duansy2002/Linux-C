#include<stdio.h>
void quicksort(int a[],int top,int end)
{
	if(top>end)
		return;
	//���ڵ��������û�б�Ҫ�ģ����Ҳ������
	int flag=a[top];
	int head=top,tail=end;	
	while(head<tail)
	{
		while(a[tail]>=flag&&head<tail)
			tail--;
		a[head]=a[tail];
		while(a[head]<=flag&&head<tail)
			head++;
		a[tail]=a[head];
	}
	a[tail]=flag;
	quicksort(a,top,tail-1);
	quicksort(a,tail+1,end);
}
int main()
{
	int a[10]={7,243,54,1,0,323,12,546,879,123};
	quicksort(a,0,9);
	getchar();
}//�������⣺ѭ���ṹ�����ԣ����Ǵ���ļ�����һ��head<=tail�ĵ��ںţ��߽�����û�п��Ǻð���
//���룬head==tail,�ᷢ��ʲô���ԣ�while���һֱ���У�
//ͬ���ģ����ڲ�whileѭ���Ҳ���ܼӵȺţ���Ϊ��Ⱥ󣬻��ٴ���λ���������̻��λ��
