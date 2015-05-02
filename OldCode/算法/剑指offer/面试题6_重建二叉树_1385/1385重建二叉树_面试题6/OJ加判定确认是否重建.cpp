#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//const int N=16;
typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}tree;
void VisitTree_3(tree *T)
{
	if(T!=NULL)
	{
		VisitTree_3(T->left);
		VisitTree_3(T->right);
		cout<<T->data<<' ';
		free(T);
	}
}
int M;
int* a=NULL;
int* queue=NULL;;
int* b=NULL;
tree* createnode_dynamic()
{
	tree *p=(tree*) malloc(sizeof(tree));
	p->left=p->right=NULL;
	return p;
}
int FindValueInA(int array[],int find)
{
	for(int i=0;i<M;i++)
		if(array[i]==find)
			return i;
	return -1;
}
bool ifright=1;
void DivideAndFind_Tree(tree *root,int top,int end,int fatherroot)
{
	if(top>end)
		return;
	int root_in_a=FindValueInA(a,root->data);
	int root_in_b;
	if(root->data!=-1)
		root_in_b=FindValueInA(b,root->data);
	else
		root_in_b=-2;
	if(root_in_a+1>=M)
		return;
	int next_root_value=*queue;
	if(root_in_b==-1)
	{
		ifright=false;
		return;
	}
	int next_root_in_b=FindValueInA(b,next_root_value);
	/*if((fatherroot<root_in_b&&fatherroot>next_root_in_b)||(fatherroot>root_in_b&&fatherroot<next_root_in_b))
	{
		ifright=false;
		return;
	}*/
	tree* p=createnode_dynamic();
	if(next_root_in_b<root_in_b)
	{
		root->left=p;
		root->left->data=next_root_value;
		queue++;
	}
	else if(next_root_in_b>root_in_b)
	{
		root->right=p;
		root->right->data=next_root_value;
		queue++;
	}
	else
		return;
	DivideAndFind_Tree(p,top,next_root_in_b-1,root_in_b);
	DivideAndFind_Tree(p,next_root_in_b+1,end,root_in_b);
	return;
}
int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&M)!=EOF)
	{
		a=(int*) malloc(sizeof(int)*M);
		b=(int*) malloc(sizeof(int)*M);
		queue=a;
		for(int i=0;i<M;i++)
			//scanf(p,"%d",&a[i]);
			cin>>a[i];
		for(int i=0;i<M;i++)
			//scanf(p,"%d",&b[i]);
			cin>>b[i];

		tree* head=createnode_dynamic();
		head->data=-1;

		DivideAndFind_Tree(head,0,M-1,-2);//��ͷ����λ�����⻯Ϊ-2
		if(ifright)
		{
			VisitTree_3(head->right);
			printf("\n");
		}
		else
			printf("No\n");
		free(a);a=NULL;
		queue=NULL;//queue����û������ռ䣬����Ҫfree�أ�������
		free(b);b=NULL;
		free(head);head=NULL;
		ifright=1;//bool����û��1����������!
		//fflush(stdin);
	}
	return 0;
}
/*
һ���Ͽ���Сʱ��Ŭ��������AC�ˣ�
�ܽ�һ�£����Ȱ�.h�е��ļ�ճ���˹�����Ȼ���޸��˱߽�������
���ڱ߽�����������46�кʹ����head�ڵ��ֵΪ-2

�����Ĺ����ǽ����̬���������룬Ȼ������������Ϊeruntime error
�������û���ͷ�ָ����ٴθ�malloc�ռ��ˣ�
ע����new�ķ�����delete��malloc������delete��
Ȼ�����������ˣ����е�free��ʱ�򴥷��˶ϵ㣬������֤��queueָ������⣬û��mallocȴfree��Ȼ����

Ȼ����Ҫ�Ĺ����Ǻ���������������������ǣ��ļ�������ֶ�����Ľ����һ�£������޸���bool������ѭ��β��ʼ����������Խ����
���������룬��ô������ֶ�������ȷ�����󣿣����԰��ⲻ�Ծ�������������������bool��ʼ��������AC�ˡ�

�м�����������ǣ�fflush����ͨ�����룡
�����Ҫ���ջ�����free�ĸ��������ã������Ƿ���ʹ��ͬһ����������ʱ��

�ܽ�һ�£������������һ���������ġ�
����ǰд���ؽ���������û�뵽��OJ���������ˣ����ǰ�ԭ���ĺ��������á�
���˺�ŷ��ֺܶ�ȱ�㣬һ�ǲ���ʶ�����Ķ�������������������Ԫ�ظ�����һ�������ͨ��return -1 �޸�head����-2������root in b�ĸ�ֵ�м�if�������
�����޷�����������ڽ������������Ҳ�õ���Ī������Ľ�������������롣
�������ˣ������ؽ������������һ������fatherroot�����ǰһ���ڵ������һ���ڵ�͵�ǰ�ڵ�֮�䣬��ô���Ǵ�ģ������Ҹ���ע�͵���Ҳ���������С��������ٹ۲�һ��
�����Է��֣�root-��data��һ����ֵ��fatherroot��1,top=0��end=7
˵�����ǵڶ������ҵ�1�ˣ������ظ��ˣ���һ������1,������Ǵ���������Ļ���δ�ػ��ڸ��ڵ�������壬����Ҫ�ü����м�õ�ɣ������ܲ���AC
ͬ����AC���������Ͻ�һЩ��
*/