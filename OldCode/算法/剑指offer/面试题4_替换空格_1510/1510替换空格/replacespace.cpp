//#include<stdio.h>
//int main()
//{
//	char ch;
//	int count=0;
//
//	while((ch=getchar())!=EOF)
//	{
//		char str[100];
//		if(ch!='\n'){
//			
//			if(ch==' ')
//			{
//				printf("%%20");
//				str[count++]='%';str[count++]='2';str[count++]='0';
//			}
//			else
//			{
//				putchar(ch);
//				str[count++]=ch;
//			}
//		}
//		else if(ch=='\n')
//		{
//			str[count]='\0';
//			count=0;
//			printf("\n%s\n",str);
//		}
//	}
//}
//�����д�Ļ��Ƚ����⣬�ϱߵ���Ϊ��ʵ��������ַ����Ĺ���

//#include<stdio.h>
//int main()
//{
//    //int count=0;//count the number of ' '
//    char ch;
//    while(/*fflush(stdin),*/(ch=getchar())!=EOF)
//    {
//        if(ch==' ')
//        {
//            printf("%%20");
//            /*putchar('%');
//            putchar('2');
//            putchar('0');*/
//        }
//        else
//            putchar(ch);
//    //calculate the end length
//    //from the end, replace them to new
//    //cout
//    }
//}