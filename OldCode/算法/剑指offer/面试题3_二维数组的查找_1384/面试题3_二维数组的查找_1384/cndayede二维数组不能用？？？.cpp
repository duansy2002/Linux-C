#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int m,n;
    int search;
    int a[10][100];
    while((scanf("%d",&m)!=EOF)&&(scanf("%d",&n)!=EOF)&&(scanf("%d",&search)!=EOF))
    {
        //a=(int **) malloc(m*sizeof(int));
        int i,j;
        for(i=0;i<m;i++)//��ɵ�ƵĴ���forѭ��д����
        {
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        i=m-1;j=n-1;
        if(a[i][j]<search)
        {
            printf("No\n");
continue;       }//̫�����Ҳ���,���ǿ������������
        while(i>=0&&j>=0&&a[i][j]>=search)//ע�⣡i>=0��j>=0Ҫд��ǰ�ߡ���Ȼ����ַ���a[-1][-1�������
        {
            i--;j--;
        }
        i++;j++;
 
        if(a[i][j]==search)
        {
            printf("Yes\n");
continue;       }//����������ڵ�ֱ���ҵ�
        for(int q=0;q<i;q++)
        {
            if(a[q][j]==search)
            {
                printf("Yes\n");
continue;           }
        }//��������
        for(int q=0;q<j;q++)
        {
            if(a[i][q]==search)
            {
                printf("Yes\n");
continue;           }
        }//��������
        printf("No\n");
    }
    return 0;
}