/*18. �۲��������У��ҹ��ɣ��ҳ���һ�������Ƕ��٣�
(�ó���ʵ��)�� 1, 11, 21 , 1211, 111221, 312211, */

/*1 
11--- ��ʾǰһ������1���� 1 �� 1�� 
21--- ��ʾǰһ������11���� �� 2 �� 1 ��ɣ� 
1211--- ��ʾǰһ������21���� �� 1 �� 2��1 �� 1 ��ɣ� 
111221--- �� 11 12 21 ����ʾǰһ������1211���������� 1 �� 1��1 �� 2�� 
2 �� 1��ɣ� 
312211---�� 31 22 11����ʾǰһ������111221���������� 3 �� 1��2 �� 2�� 
1 �� 1 ��ɣ�*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* countit(char *str)
{
	char ch[2]="";
	char number[20]="";
	char* newchar=(char *)calloc(100,sizeof(char));
	for(int i=0;i<strlen(str);)
	{
		ch[0]=str[i];
		int count=0;
		while(str[i]==ch[0])
		{
			count++;i++;
		}
		strncat(newchar,itoa(count,number,10),1);//ճ���ɼ������
		strncat(newchar,ch,1);//ճ����ɵ�����
		if(str[i]=='\0')
			break;
	}	
	printf("\nnext result is:\n%s",newchar);
	//free(str);
	return newchar;
}


int main()
{
	char str[1000]="1";
	char c;
	char* reload=str;
	for(int i=0;i<10;i++)
		reload=countit(reload);
	return 0;
}
