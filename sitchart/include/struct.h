#include"sitchart.h"
#define M 8
#define N 9
struct node
{
	int row;
	int col;
	char name[20];
	struct node *right;
	struct node *down;
};//������Ϣ�ڵ㡣�������֡��������������ұ��ˡ������

struct nodehead
{
	int num;
	struct node *head;
	struct node *tail;
};//���С����е�ͷ��㣬���ڼ�¼�����������������Լ�β�ڵ�

struct list
{
	nodehead *rowhead[M];
	nodehead *colhead[N];
	//int rownum;
	//int colnum;
	int stunum;
};//list�ṹ��������������ͷ��㣬����һ��ͷ��㡢һ��ͷ���
//�������ݡ�������������������
