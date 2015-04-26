#include<stdio.h>
const int length=10;
int N;
void swap(int *m,int *n)
{
	int temp;
	temp=*m;*m=*n,*n=temp;
}

void maxheapify(int A[],int i)
{
	int l,r,largest;
	l=i*2;r=i*2+1;

	if (A[l]>=A[i]&&l<=N)
		largest=l;
	else largest=i;

	if (A[r]>A[largest]&&r<=N)
		largest=r;

	if (largest!=i)
	{
		swap(&A[largest],&A[i]);
		maxheapify(A,largest);
	}
}

void buildheap(int A[])
{
	for(int i=int(N/2);i>0;i--)//C �������0��ʼ�ı�ǱȽ�����,������������ͷ����һ��0Ԫ��
	maxheapify(A,i);
}
void print(int B[],int n)
{
	for(int i=1;i<=n;i++)
		printf("%d ",B[i]);
	printf("\n");
}

void heapsort(int A[])//ͨ�������õĶѣ�ȡ��A[1]����β��������
{
	buildheap(A);
	for(int i=N;i>1;i--)
	{
		swap(&A[1],&A[i]);
		N--;
		maxheapify(A,1);		
	}
}

void main()
{
	int A[length+1]={0,4,1,3,2,16,9,10,14,8,7};//0 here is used as a 'sodier'
	N=length;
	heapsort(A);
	print(A,length);
	getchar();
}