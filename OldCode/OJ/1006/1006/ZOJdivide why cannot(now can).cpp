/*�Ը������ַ���(ֻ����'z','o','j'�����ַ�),�ж����Ƿ���AC��*/
#include<string.h>
#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	char str[10000];
	while(gets(str)!=NULL)
	{
		int mark[3]={0};
		int *p=mark;
		bool right=0;
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='o')
				(*p)++;
			if(str[i]=='z')
			{
				if(p-mark==0)
					p++;
				else goto ed;
			}
			if(str[i]=='j')
			{
				if(p-mark==1)
					p++;
				else goto ed;
			}
		}
		if(p-mark!=2)//no j in str
			goto ed;
		if(mark[1]==0)//zoooooj   ozoooooooooojo WA
				right=0;
		else if(mark[0]==0||mark[2]==0)
		{
			if(mark[0]==0&&mark[2]==0)
				right=1;
		}
		else if(mark[2]/mark[0]==mark[1]&&mark[2]%mark[0]==0)//XzojX   ozoooooooooojo WA
			right=1;
		//right=(mark[1]!=0&&mark[2]==mark[1]*mark[0]);
ed:		printf(right?"Accepted\n":"Wrong Answer\n");
	}
	return 0;
}//forgtet to chaeck is there is z & j

/**/