//��һ����ά������������ʹ�øö�ά�����ÿһ�е�������ÿһ�еݼ�����
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define M 8
#define N 6
void printarr(int a[M][N])
{
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	putchar('\n');
}

void givevalue(int a[M][N])
{
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			a[i][j]=rand()%999;
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	putchar('\n');
}

int cmpDecrease(const void *left,const void *right)
{
	int *a=(int *)left;
	int *b=(int *)right;
	if(*a<*b)
		return 1;
	else
		return (*a==*b?0:-1);
}

int cmpIncrease(const void *left,const void *right)
{
	int *a=(int *)left;
	int *b=(int *)right;
	if(*a>*b)
		return 1;
	else
		return (*a==*b?0:-1);
}

int main()
{
	srand(time(NULL));
	int arr[M][N]={0};
	printf("ԭ���飺\n");
	givevalue(arr);
	//-------������
	for(int i=0;i<M;i++)
		qsort(arr[i],N,sizeof(int),cmpIncrease);
	
	printf("������\n");
	printarr(arr);

	//=------������
	for(int i=0;i<N;i++)
		qsort((int *)(arr+i),M,sizeof(int),cmpDecrease);
	printf("������\n");
	printarr(arr);

	return 0;
}
