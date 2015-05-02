#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void rotate(char str[])
{
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char temp;
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
}
char* takeoffsign(char a[])
{
	char *newc=(char *)malloc(sizeof(char)*strlen(a));
	if(a[0]=='-')
	{
		rotate(a);
		a[strlen(a)-1]='\0';
		rotate(a);
	}
	else if(a[0]=='+')
	{
		rotate(a);
		a[strlen(a)-1]='\0';
		rotate(a);
	}
	strcpy(newc,a);
	return newc;
}
int* dividenum(char a[],int digit)//�Ѵ����г�int9λ��Χ�ڵ�char��Ȼ��洢��int
{
	int *num=(int *)calloc(digit,sizeof(int));
	rotate(a);
	int count=1;
	for(int i=0;i<strlen(a);i++)
	{
		if(count==1000000000)
			count=1;
		num[i/9]=num[i/9]+count*(a[i]-'0');//�����
		//num[i/9]=num[i/9]*10+(a[i]-'0');//�����

		count*=10;
	}
	return num;
}

char* bignum(char a[],char b[])
{
	bool change_sign=0;//��¼�Ƿ�Ҫ����

	int flag_a=1,flag_b=1;//����λ
	if(a[0]=='-')
		flag_a=-1;
	if(b[0]=='-')
		flag_b=-1;//��Ϊ�����add������ƣ��������������ĸ��������Զ�ת���ɴ�������С����������+��
	a=takeoffsign(a);b=takeoffsign(b);
	int len_a=strlen(a);
	int len_b=strlen(b);
	if(flag_a==-1&&flag_b==-1)
	{
		change_sign=true;
		flag_a=flag_b=1;
	}
	else if(flag_a==-1&&strlen(a)>strlen(b)||(flag_b==-1&&strlen(b)>strlen(a)))//��һ��һ������������ֵ��
	{
		change_sign=true;
		flag_a=-flag_a;
		flag_b=-flag_b;
	}
	else if((flag_a==-1&&strlen(a)==strlen(b)&&strcmp(a,b)==1)||(flag_b==-1&&strlen(a)==strlen(b)&&strcmp(b,a)==1))//һ��һ����λ������ȣ��жϸ��ľ���ֵ��
	{
		change_sign=true;
		flag_a=-flag_a;
		flag_b=-flag_b;
	}
	/*_________________________________*/
	int digit=(len_a>len_b?(len_a/9+1):(len_b/9+1));//���ֳ�ÿ9λһ���ļӷ�,�����������ӷ�
	int *num1=dividenum(a,digit);
	int *num2=dividenum(b,digit);
	int *add=(int *)calloc(digit,sizeof(int));//����ᴥ���ϵ�???��λ���ܳ�digit>=4��ʱ��//ԭ������takeoffsign������ʹ����malloc������ȥ���ͺ���
	
	//����λ
	//int *flag=(int *)calloc(digit,sizeof(int));
	for(int i=0;i<digit;i++)
	{
		num1[i]=num1[i]*flag_a+num2[i]*flag_b+(i==0?0:add[i-1]);
		add[i]=num1[i]/1000000000;
		num1[i]=num1[i]%1000000000;//����ȡ����
		if(num1[i]<0)
		{
			num1[i]=1000000000+num1[i]%1000000000;//��λ
			add[i]++;//��Ϊ��λ��Ҫ�ٽ�1��
		}
	}
	char *result=(char *)calloc(10000,sizeof(char));
	char temp[11];
	for(int i=digit-1;i>=0;i--)
	{
		int value=num1[i]+1000000000;//numÿС�������������巴��,��������000��ͷ������+1000000000

		itoa(value,temp,10);//�����00000999��ʽ����������⣬����ÿ��temp����һ��ͷ1
		rotate(temp);temp[9]='\0';//���999000000��ʽ����תһ�ξ���
		rotate(temp);
		strcat(result,temp);

	}
	
	//ȥ��ͷ0����ӷ���λ
	rotate(result);
	int i=strlen(result)-1;
	while(result[i]=='0'&&i>0)
		i--;
	if(change_sign)
		result[++i]='-';
	result[++i]='\0';
	rotate(result);
	return result;
}
int main()
{
	char a[]="-99999990798068769895123152432412419812123127951024709862187461298749999";
	char b[]="998464513313213123132165798796412315152321996465465465469999999999999";
	printf("%s\n +\n%s \n= \n",a,b);
	char* result=bignum(a,b);
	printf("%s\n",result);
	return 0;
}//bug
//1.�ϵ�BUG��takeoffsign��mallocȥ���ͽ���ˣ�ԭ���ǲ����ף�//ԭ��Ȼ��д����sizeof��strlen��������ʹ��

/*�����ε�ԭ����malloc��ָ��p������һ����ַ��Ȼ���������mallocһ��q��ô�ͻ������Ƭ�ڴ���䡣
������ʹp��q����1λ��������p,q֮��Ԥ��һ��ռ䡣����д���ڴ���ַ����϶̵�ʱ�򲻻���ִ��󡣶�������Ĳ����㹻��ʱ����������ˡ�
������malloc��ָ��pû��Ԥ�����㹻�Ŀռ�ȴ����һ�������ռ��ֵ������malloc��4��,ȴд��ܴ���ַ�����
��ô��malloc��һ��ָ��q�󣬾ͻᵼ��q��ָ��p�б����ǵĵ���Ƭ�ڴ棬����*p�����ݴ���*/

//2.ȫ��0��ʱ��itoa��null����if�ж��ֶ����00000000----�Ѿ����ϵ�����5���ˡ�
//3.�����λ��numҪȡ��������
//4.flag_a��b������������elseֻ���������+С��������add��
//5.line 106�����������һ��000009999���������֣�itoa��ֱ�ӱ��9999������000009999�����԰���+100000000��ȥ����λ