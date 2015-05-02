#include "HashSave.h"
int main()
{//�Ѿ�ȫ��ת����Сд��'s�ᱻͳ�Ƴ�s, ���ַ�-û����
	FILE *f_open;
	f_open=fopen("lower.txt","rb");
	FILE *write[26];
	FILE *INDEX;
	INDEX=fopen("index.txt","wb");
	char name[26][6];
	Info *hash[26];
	for(int i=0;i<26;i++)
	{
		name[i][0]=i+'A';
		strncpy(name[i]+1,".txt\0",5);
		write[i]=fopen(name[i],"wb");
		hash[i]=CreateInfo();
	}
	char c;
	char word[20];
	char *p;
	int words=0;
	while((c=fgetc(f_open))!=EOF)
	{
		while(!isalpha(c))
			if((c=fgetc(f_open))==EOF)
				goto toend;
		words++;
		p=word;
		while(isalpha(c))
		{
			*p++=c;
			if((c=fgetc(f_open))==EOF)
			{
				*p='\0';
				break;
			}
		}
		*p='\0';
		assert(isalpha(word[0]));
		IfExsist(hash[word[0]-'a'],word);
	}
toend:;
	PrintHash(hash,INDEX);
	for(int i=0;i<26;i++)
	{
		WordQsort(hash[i]);
		PrintResult(hash[i],write[i],i);
	}
	fclose(f_open);
	for(int i=0;i<26;i++)
		fclose(write[i]);
	fclose(INDEX);
	return 0;
}