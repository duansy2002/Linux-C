/*�ո����+���������Ƶ������*/
#include<stdio.h>
#include<ctype.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("copy.txt","w",stdout);
	char c;
	int countblank=0;int count=0;
	while((c=getchar())!=EOF)
	{
		/*if(c=='\r'||c=='\t'||c=='\n'||c==10||c==32||c==13)
			putchar('a');
		if(c==' '&&countblank==0)
		{
			putchar(c);
			countblank++;
		}
		else if(c<='z'&&c>='a')
		{
			putchar('c');
			countblank=0;
		}
		putchar(c);
		printf("%d ",c);*/
		if(c==' '&&countblank==0)
		{
			countblank++;
			putchar(' ');
			count++;
		}//ȥ�ո���
		else if(c==' '&&countblank)
			countblank=0;
		else if(isspace(c))
			;
		else
		{
			putchar(c);
			count++;
		}
		if(count>80&&isspace(c))
		{
			putchar('\n');
			count=0;//���ʽ����ڻ���
		}//�Զ����й���
	}
}
/*
		if(c==' '&&countblank==0)
		{
			putchar(c);
			countblank++;
		}
		else if(c!=' ')
		{
			putchar(c);
			countblank=0;
		}

	*/