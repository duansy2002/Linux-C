#include<iostream>
#include<string.h>
using namespace std;
const int N=500;
char s[N];
void tst(char a)
{
	cout<<a<<';';
}
void ifpalin()//�Ҿ�����Ӧ����Ԥ����������������������������Ȼ����д��,���ݽṹ����Ҫ�ԣ�
{
	int left,right,i=1;
	while(s[i])
	{
		//tst('A');
		//Ѱ�ҵ�һ���Ƿ��ŵ㡣
		while(!isalpha(s[i]))
		{
			i++;
			//tst('B');
		}
		left=i-1;right=i+1;
		while(left>=0&&!isalpha(s[left]))
		{
			left--;
			//tst('C');
		}//Ѱ�ұ����ߵ�һ���Ƿ��ŵ㡣
		while(s[right]&&!isalpha(s[right]))
		{
			right++;
			//tst('D');
		}//Ѱ���ұߵ�һ���Ƿ��ŵ㡣

		if(isalpha(s[right])&&isalpha(s[left]))//���������Ҷ��в����жϡ�
		{		
			while(s[left]==s[right]&&left>=0&&s[right])
			{
				//tst('E');
				while(left>=0&&!isalpha(s[left]))//��������Ҳ�����ĸ
					left--;
				while(s[right]&&!isalpha(s[right]))
					right++;//д��while����Զ��һ��
			}
			if(left!=(i-1)&&left!=right)
			{
				for(int j=left;j<=right;j++)
					cout<<s[j];
				cout<<'\n';
			}
		}
		i++;
		//��������������Ρ�������if�򻯣�û���һ��aaaaaaaaaaaʱ��ô����
	}
}

int main()
{
	FILE *fin;
	fin=fopen("input.txt","rb");
	s[N]=fscanf(fin,"%s",s);
	ifpalin();
	getchar();
}