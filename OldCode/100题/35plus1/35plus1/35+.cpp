/* ��35�� ���дһ������������ɾ���ַ����е����пո�*/
//��������Ҫȥ����
#include<iostream>
void dele(char *s)
{
	char *p=s,*write=s;
	while(*p)
	{
		char *q=s;
		int count=0;
		//Ѱ����û���ظ��ģ��еĻ�count=1����Ϊ0
		while(q<p)
		{
			if(*p==*q)
			{
				count++;
				break;
			}
			q++;
		}
		
		if(count==0)
			*write++=*p;
		p++;
	}
	*write='\0';
}

int main()
{
	char s[]="hell osad s dsdas as";
	dele(s);
	std::cout<<s;
	getchar();
}