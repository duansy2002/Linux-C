#include<iostream>
using namespace std;
const int N=16;

struct tree
{
	int data;
	tree *left;
	tree *right;
}node[N];//ע������node[N]������ģ�ֻ��Ϊ�˷��㽨����һ����
tree leaves[N];
tree *p=leaves;
/*����������������������������������Ӳ��֡���������������������������������*/
void CreateTree(tree &root,int value)
{
	root.data=value;
	root.left=root.right=NULL;
}
void AddTree(tree &root,tree &leaf,bool choose,int value)//bool 0������������1����������
{
	if(value==0)
	{
		(choose?root.right:root.left)=NULL;
		return;
	}
	(choose?root.right:root.left)=&leaf;
	leaf.data=value;
	leaf.left=leaf.right=NULL;
}

/*���������������������������������ؽ����֡���������������������������������*/
//int a[9]={1,2,4,8,9,5,3,6,7};
//int b[9]={8,4,9,2,5,1,6,3,7};
int a[3]={1,2,3};
int b[3]={2,1,3};

tree * Find_Root(tree root,int top,int end)
	//��ȷ�����Ĺ�����ʲô���ҵ�������������е������Ǹ����ڵ㲢�������ĵ�ַ��
	//����Ĺؼ�����������ָ��Ľṹ�������������ӵ�һ��
	//�����˺ܶ��βΣ�ϣ���ܴ����㹻����Ϣ��
{
	if(top>end)
	{
		cout<<"return!";
		return;
	}
	int former_root;//�зֵ�,��¼�Ǳ��õģ��ҵ�����ĸ��ڵ�ֵ�ĽǱ꣬�ж������������
	for(int i=0;i<N;i++)
	{//find root.data in b[];
		if(root.data==b[i])
		{
			former_root=i;
			break;
		}
		else;
		//	return;//�Ҳ������˳�����
	}
cout<<"(1) former_root:"<<former_root;
	bool choose;//then if right or left?;
	if(former_root<top)//�Ⱥ��أ�
		choose=1;//����1����������������0����������
	else if(former_root==top||former_root==end)
	{
		cout<<"it happens ![equal]";//I don't know what happens.
	}
	else if(former_root>end)
		choose=0;
cout<<"(2) choose:"<<choose;
	//make sure the side;
	int next_root_value;//��һ�����ڵ��ֵ��ͨ��a++���Ƶķ�ʽ�ҵ�
	for(int i=0;i<N;i++)
	{
		if(a[i]==root.data)
		{
			next_root_value=a[i+1];
			break;
		}
	}//find next root in a[ ];
cout<<"(3) next_root_value"<<next_root_value;
	//-int next_root_value=a[next_root_mark];
	int cut;//��top to end �зֿ��ĵ�
	for(int i=top;i<=end;i++)
	{
		if(b[i]==next_root_value)
			{
				cut=i;
				cout<<"(4) cut:"<<cut;
		}
		else
			cout<<"cut error!\n";
	}//find the position of next_root in b[ ]
	//tree leaf;
	tree *temp=new tree;
	root.right or left = temp;
	//���´������ӷ��˵�ʱ��д��ע�ⲻҪ����
	temp->data=b[cut];
	if(choose)
		temp->right=Find_Root(
	//AddTree(root,*++temp,choose,next_root_value);//root point to leaf(next_leaf);
	
	//Find_Root(*temp,top,cut-1);//root ->next_root, do top1 ~ end1;
	//Find_Root(*temp,cut+1,end);//root -> next root, do top2 ~ end2;
	return temp;
}




























/*�������������������������������齨������������������������������������������*/
void AddTreeFromArray(int a[])
{
	int used=0,i=0;
	bool choose=0;
	//tree * queue[N];//���ö�����ʵ�֣�����������ȫ�������������й��ɵ���һ���Ȳ�д
	CreateTree(node[0],a[used++]);
	while(used<N-1)//��ԭ��������16�޸��˱߽������������ڴ���δ����һ����ֵ�����ǿ���-1��
	{
		AddTree(node[i],node[i*2+1],0,a[used++]);
		AddTree(node[i],node[i*2+2],1,a[used++]);
		i++;
	}

}
/*���������������������������������֡�����������������������������������*/
void VisitTree_1(tree &T)//���Ե���ǰ�����������������������
//�㷨���Ӷ�ΪO(n),�ݹ鹤��ջ����ǡ��Ϊ���ĸ߶ȡ�
{
	if(&T!=NULL)//�Ҳ���else����ΪNULL��Ȼ�����������жϣ�
	{
		cout<<T.data<<'/';
		VisitTree_1(*T.left);
		VisitTree_1(*T.right);
	}
}
void VisitTree_2(tree &T)
{
	if(&T!=NULL)
	{
		VisitTree_2(*T.left);
		cout<<T.data<<'/';
		VisitTree_2(*T.right);
	}
}
void VisitTree_3(tree *T)
{
	if(T!=NULL)
	{
		VisitTree_3(T->left);
		VisitTree_3(T->right);
		cout<<T->data<<'/';
	}
}