/*��4�� ���дһ������void fun(char *tt,int pp[])
ͳ����tt�ַ���"a"��"z"26����ĸ���Գ��ֵĴ���
�����η���pp��ָ�������С�*/

#include<iostream>
using namespace std;
void function(char *tt,int pp[])
{
	for(int i=0;i<26;i++)
	//	{*pp=0;
	//pp++;}
		pp[i]=0;
	while (*tt)
	{
		pp[*tt++-97]++;

		//pp[int(*tt-97)]++;����������������������ʽת��ȡ��switch�ṹ��

		/*switch (*tt)
		{
		case 'a': pp[0]++;break;
		case 'b': pp[1]++;break;
		case 'c': pp[2]++;break;
		case 'd': pp[3]++;break;
		case 'e': pp[4]++;break;
		case 'f': pp[5]++;break;
		case 'g': pp[6]++;break;
		case 'h': pp[7]++;break;
		case 'i': pp[8]++;break;
		case 'j': pp[9]++;break;
		case 'k': pp[10]++;break;
		case 'l': pp[11]++;break;
		case 'm': pp[12]++;break;
		case 'n': pp[12]++;break;
		case 'o': pp[14]++;break;
		case 'p': pp[15]++;break;
		case 'q': pp[16]++;break;
		case 'r': pp[17]++;break;
		case 's': pp[18]++;break;
		case 't': pp[19]++;break;
		case 'u': pp[20]++;break;
		case 'v': pp[21]++;break;
		case 'w': pp[22]++;break;
		case 'x': pp[23]++;break;
		case 'y': pp[24]++;break;
		case 'z': pp[25]++;break;
		}*/
		//tt++;
	}
}

void main()
{
	int pp[26];
	char *tt="ghjgkvbvncnbvacbntyeyrewewqwerqyuituyioyuiyjdasd";
	//cin>>tt;
	//char *s1; s1ֻ��һ���ַ���ָ�룬ֻ�ܴ洢һ���ַ���ָ�����,Ҫ����cin�����ַ��������������ַ�����!!

	function(tt,pp);
	for(int i=0;i<26;i++)
		cout<<pp[i];
	getchar();
}