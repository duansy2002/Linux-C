/*ͳ�ƿո񡢻��з����Ʊ���ĸ���*/
#include<stdio.h>
#include<stdlib.h>
void more1()
{
	char c;
	int space,tab,enter;
	int alpha[26]={0};
	space=tab=enter=0;
	while((c=getchar())!=EOF)
	{
		if(' '==c)
			space++;
		else if('\t'==c)
			tab++;
		else if('\n'==c)
			enter++;
		else if(c>='A'&&c<='Z')
			alpha[c-'A']++;
		else if(c>='a'&&c<='z')
			alpha[c-'a']++;
	}
	printf("space %d tab %d enter %d\n",space,tab,enter);
	for(int i=0;i<26;i++)
		printf("the number of '%c' is %d\n",i+'a',alpha[i]);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	char c;
	int space,tab,enter;
	space=tab=enter=0;
	int asc[126]={0};
	while((c=getchar())!=EOF)
	{
		if(c<=126)
			asc[c]++;
	}
	//printf("space %d tab %d enter %d\n",space,tab,enter);
	for(int i=0;i<126;i++)
		printf("the number of '%c' is %d\n",char(i),asc[i]);
}
/* ��չ��ͳ��������ĸ��*/
//��չ2���������е�ASCII�ַ���33-126Ϊ�ɴ�ӡASCII�롣�ܼ򵥵�
