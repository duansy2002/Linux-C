/*

#include<iostream>
#include<string.h>
using namespace std;
const int N=500;
char s[N];
void tst(char a)
{
	cout<<a<<';';
}
void printpalin()
{
	//Ԥ�������˵����ַ���
	char* pre[N];
	int pre_i=0;

	for(int j=0;j<sizeof(s)-1;j++)
	{
		if(isalpha(s[j]))
		{
			pre[pre_i++]=&s[j];//���ԭ���ĵ�ַ
		}
	}
	//Ԥ������ϡ�ͨ��ָ�����s�����֡�
	int left,right,i=1;//�߽�����ˣ������������εĵ��ԣ�ԭ��Ȼ��sizeof��pre��=2000��������û���뵽�ġ���Ϊ������󣬵����˺ó��ó�ʱ�䣡
	while(i<pre_i)
	{	
		int move=0;
		left=i-1;right=i+1;
		while(left>=0&&right<pre_i&&(*pre[left]==*pre[right]||(*pre[left]==*pre[right]+'a'-'A')||(*pre[left]==*pre[right]+'A'-'a')))
		{
			left--;
			right++;
			move++;
		}
		if(move)
		{
			right--;
			for(char* j=pre[++left];j<=pre[right];j++)//ĩ�˴����ã����ǻ���������һ����ĸ��ķ��š�
				//ԭ������Ϊ��'--'д����forѭ�������˱�ִ�ж�Σ��������Ҫע�⣡������������BUG����������ġ�
				//��ʵҲ�ܼ򵥣��߽��������ǻ��ǲ���ȫ����sizeof���ǲ�������
				cout<<*j;
			cout<<'\n';
		}
		//��һ��������Գ��ַ�����
		move=0;
		left=i-1;right=i;
		while(left>=0&&right<pre_i&&(*pre[left]==*pre[right]||(*pre[left]==*pre[right]+'a'-'A')||(*pre[left]==*pre[right]+'A'-'a')))
		{
			left--;
			right++;
			move++;
		}
		if(move)
		{
			right--;
			for(char* j=pre[++left];j<=pre[right];j++)
				cout<<*j;
			cout<<'\n';
		}
		i++;
	}
}

int main()
{
	FILE *fin;
	fin=fopen("input.txt","rb");
	s[N]=fscanf(fin,"%s",s);
	printpalin();
	getchar();
}

*/