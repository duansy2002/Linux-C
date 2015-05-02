#ifndef _LIST_
#define _LIST_
#include<iostream>
#include<assert.h>
using namespace std;
typedef struct LinkedlistNode //����ڵ�
{
	int data;
	LinkedlistNode* next;
}node;

struct LinkInfo //������¼����ͷ��㡢���һ���ڵ㡢Ԫ�ظ���
{
	int listlen;
	LinkedlistNode *head,*tail;
};

node* NewNode(void);//����һ������ڵ�
LinkInfo* CreateLinkInfo();//����һ���յ�������Ϣ
void AddNodeToInfo(LinkInfo*,int);//��LinkInfo�ĺ�������һ���ڵ�
LinkInfo* CreateInfoFromArray(int [],int);//����һ����������ֵ��array��ȡ

node* CreateSonNode(node *father,int num);//����father���ӽڵ�
void FreeNode(node *start);//free�ڵ�start��ָ�Ľڵ�
LinkInfo* InitListInfo(LinkInfo *listHead);//����һ���յĵ�����,����������Ϣ
bool DestroyList(node *L);//����������
bool ClearList(node *LHead);//��L��Ϊ�ձ��ͷ�ԭ�ڵ�ռ�
bool InsertHead(node *head,node *add);//ͷ�巨
bool DeleteFirst(node *head);//ɾ��ͷ�����һ���ڵ�
bool Append(LinkInfo *LInfo,node *s);//��s��ָ��һ���ڵ�ӵ�L���棬������L��βָ��
bool InsertBefore(LinkInfo *L,node *p,node *S);//������L��p�ڵ�ǰ����ڵ�S
bool InsertAfter(LinkInfo *L,node *p,node *S);//������L��p�ڵ�����ڵ�S
node* PrirorPos(node *head,node *p);//����p��ǰ���ڵ��λ
node* Search(node *head,int value);//�����ڵ�


//1-������ת �м������ʽ
void ReverseList(LinkInfo *head);
//2-������K��
node* lastK(LinkInfo L,int k);
//3-�м�ڵ�
node* FinMid(LinkInfo L);
//4-ɾ����ͷ���
void DelNoHead(node *p);
//5-������������ϲ�
LinkInfo* MergeList(LinkInfo *M,LinkInfo *N);
//6-�����Ƿ��л�
node* IfCircle(node *);
//7+8-��������Ľ��㣿�󽻵�
node* Intersection1(node*,node*);
node* Intersection2(node*,node*);
//9-����������,Qsort
void LinkSortQ(LinkInfo*,bool);
//10-ɾ���ظ�Ԫ��
void DelRepeated(LinkInfo*);
//11-�����֣�����һ��ż��һ��
void SplitList(LinkInfo*,LinkInfo*,LinkInfo*);
//12-�������ӷ�
LinkInfo* BigNumAdd(int a,int b);
char* BigNum(char*,char*);
#endif // !_LIST_