#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#define N 12
int AppearOnce(int a[],int size)
{
	int *b=(int *)calloc(size,sizeof(int));
	memcpy(b,a,size*sizeof(int));
	assert(size%2==1);
	while(--size){
		b[size-1]=b[size]^b[size-1];
	}
	int record=b[0];
	free(b);
	return record;
}//���ֵ����⡣��ı�a��ֵ��������ʱ���顣

int* AppearOnceTwo(int a[],int size)
{
	int count=size;
	assert(size%2==0);
	int xor=a[0];
	while(--size)
		xor=xor^a[size];//xor=a^b
	int move=0;
	while((xor>>move)%2==0)
		move++;//ֱ��xor������λ��Ϊ1
	int flag=1<<move;
	int *num2=(int *)calloc(2,sizeof(int));
	for(int i=0;i<count;i++){
		if((a[i]&flag)==0)
			num2[0]=num2[0]^a[i];//��һ����
		else
			num2[1]=num2[1]^a[i];//�ڶ�����
	}
	return num2;
}
//���ֵ����⡣if�ж����ȼ�����λ��������ȼ�

int main()
{
	int a[N]={1,1,2,3,3,4,4,5,5,6,6,7};//101̫���ˣ���define����
	printf("ONE---%d\n",AppearOnce(a,N-1));
	int* num2=AppearOnceTwo(a,N);
	printf("TWO---%d %d",num2[0],num2[1]);//���ܺ�
	free(num2);
	return 0; 
}