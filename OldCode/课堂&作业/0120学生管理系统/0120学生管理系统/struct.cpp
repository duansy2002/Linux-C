#include "_SIMS.h"

extern StuInfo *L;

STU* CreateSTU()
{
	STU *p=new STU;
	p->next=NULL;
	memset(p->score,0,5*sizeof(double));
	p->total=0;
	p->name[0]='\0';
	return p;
}

StuInfo* CreateInfo()
{
	StuInfo *p=new StuInfo;
	p->head=CreateSTU();
	p->tail=p->head;
	p->num=0;
	return p;
}

StuInfo* FileToInfo()
{
	FILE *open;
	open=fopen("STU_INFO.txt","r");
	StuInfo *L=CreateInfo();
	STU temp;
	STU *read;
	read=L->head;
	double a=1.0*1.0;
	while(fscanf(open,"%d%s%d%lf%lf%lf%lf%lf",&(temp.id),temp.name,&(temp.sex),&(temp.score[0]),\
		&(temp.score[1]),&(temp.score[2]),&(temp.score[3]),&(temp.score[4]))==8)
	{
		STU *p=CreateSTU();
		p->id=temp.id;
		p->sex=temp.sex;
		strcpy(p->name,temp.name);
		double sum=0;
		for(int i=0;i<5;i++)
		{
			sum+=temp.score[i];
			p->score[i]=temp.score[i];
		}
		p->total=sum;
		L->num++;
		read->next=p;
		L->tail=p;
		read=read->next;
	}
	fclose(open);
	return L;
}

void SearchSTU()
{

	int id;
conti:	while(system("cls"),fflush(stdin),cout<<"��ѧ�Ų�ѯѧ����Ϣ!\n",dayindangqianxuesheng(),
			cout<<"\n����ѧ��ID(����-1�˳�):",scanf("%d",&id)==1)
		{
			fflush(stdin);
			if(id==-1)
				return;
			STU *search;
			search=L->head->next;
			//printf("ѧ��   ����    �Ա�      1      2      3      4      5         �ܷ�\n");
			while(search!=NULL)
			{
				if(search->id==id)
				{
					printSTUINFO(search);
					system("pause");
					goto conti;
				}
				search=search->next;
			}
			printf("		û���ҵ����!\n");
			system("pause");
			/*printf("		3");
			_sleep(1000);printf(" 2");
			_sleep(1000);printf(" 1");
			_sleep(1000);*/
		}
}

void DelSTU()
{
st:	system("cls");
	dayindangqianxuesheng();
	printf("	����Ҫɾ����ѧ��ѧ��(����-1�˳�):");
	int id;
	cin>>id;
	if(id==-1)
		return;
	STU *find=L->head;
	while(find->next)
	{
		if(find->next->id==id)
		{
			printSTUINFO(find->next);
			printf("�Ƿ�Ҫɾ����ѧ����Ϣ��y��ȷ��ɾ�������������ء�");
			char del;
			fflush(stdin);
			cin>>del;
			if(del!='y')
				goto st;
			STU *temp=find->next->next;
			delete(find->next);
			find->next=temp;
			RewriteFile();
			printf("�޸ĳɹ���");printf("��������˳���\n\n");
			fflush(stdin);
			getchar();
			printf("3");
			_sleep(1000);printf(" 2");
			_sleep(1000);printf(" 1");
			_sleep(1000);
			return;
		}
		find=find->next;

	}

}


void UpdateSTU()
{
	int id;
again:
	while(fflush(stdin),system("cls"),printf("��Ϣ����-���޸���Ϣ\n"),\
		dayindangqianxuesheng(),\
		printf("����Ҫ�޸ĵ�ѧ��ѧ��(-1�˳�)��"),scanf("%d",&id)==1)
	{
		if(id==-1)
			return;
		STU *find=L->head->next;
		while(find!=NULL)
		{
			if(find->id==id)
			{
				int gd;
				printSTUINFO(find);
				while(fflush(stdin),printf("\n������Ҫ�޸ĵ���Ŀ[1-8]	����-1�˳�: \n",id),scanf("%d",&gd)==1)
				{
					if(gd<=8&&gd>=4)
					{
						printf("ϣ���޸���ĿΪ����	[%d] ��Ŀ %d -- %3.1f\n�����µĳɼ�:",gd,gd-3,find->score[gd-4]);
						double grade;
						cin>>grade;
						printf("ԭ�ɼ�Ϊ %3.1lf, ϣ���޸�Ϊ %3.1lf. ȷ������y,�������˳���\n",find->score[gd-4],grade);
						char makesure;
						cin>>makesure;
						if(makesure!='y')
							continue;
						find->score[gd]=grade;
						printf("�ɼ��Ѹ��£�\n");
						RewriteFile();
						printf("�޸ĳɹ���\n");
						printSTUINFO(find);
						printf("��������˳���\n\n");
						fflush(stdin);
						getchar();
						printf("3");
						_sleep(1000);printf(" 2");
						_sleep(1000);printf(" 1");
						_sleep(1000);
						goto again;
					}
					else if(gd==-1)
						return;
					else if(gd==2)//����
					{
						printf("ϣ���޸���ĿΪ����	[2] ���� -- %s\n�����µ�������",find->name);
						char namenew[20]="";
						fflush(stdin);
						cin>>namenew;
						printf("ԭ���� %s ϣ���޸�Ϊ %s ȷ������y,�������˳���\n",find->name,namenew);
						char makesure;
						cin>>makesure;
						if(makesure!='y')
							continue;
						strcpy(find->name,namenew);
						printf("�����Ѹ��£�\n");
						RewriteFile();
						printf("�޸ĳɹ���\n");
						printSTUINFO(find);
						printf("��������˳���\n\n");
						fflush(stdin);
						getchar();
						printf("3");
						_sleep(1000);printf(" 2");
						_sleep(1000);printf(" 1");
						_sleep(1000);
						goto again;
					}
					else if(gd==3)//�Ա�
					{
						printf("ϣ���޸���ĿΪ����\n		[3] �Ա� -- %s��",find->name);
						printf("\n����ԭ�Ա� - ");printf(find->sex?"��":"Ů");
						printf(" - �޸�Ϊ - ");	printf(!find->sex?"��":"Ů");
						printf("\nȷ������y,�������˳���\n");
						char makesure;
						fflush(stdin);
						cin>>makesure;
						if(makesure!='y')
							continue;
						find->sex=!find->sex;
						printf("�Ա��Ѹ��£�\n");
						RewriteFile();
						printf("�޸ĳɹ���\n");
						printSTUINFO(find);
						printf("��������˳���\n\n");
						fflush(stdin);
						getchar();
						/*printf("3");
						_sleep(1000);printf(" 2");
						_sleep(1000);printf(" 1");
						_sleep(1000);*/
						goto again;
					}

					else
						printf("��������������룡\n");
				}
			}
			find=find->next;
		}
		printf("û���ҵ���ѧ����\n\n");
		system("pause");
	}
}

void RewriteFile()
{
	FILE *re=fopen("STU_INFO.txt","w");
	STU *visit=L->head->next;
	while(visit!=NULL)
	{
		fprintf(re,"%d  %s  %d ",visit->id,visit->name,visit->sex);
		for(int i=0;i<5;i++)
		{
			fprintf(re," %.1lf",visit->score[i]);
		}
		fprintf(re,"\n");
		visit=visit->next;
	}
	fclose(re);
	return;
}

void printSTUINFO(STU *man)
{
	printf("		=======================\n\n");
	printf("		ѧ����ǰ��Ϣ��\n");
	printf("		[1] ѧ�� -- %d\n",man->id);
	printf("		[2] ���� -- %s\n",man->name);
	printf("		[3] �Ա� -- %s\n",man->sex?"��":"Ů");
	for(int i=0;i<5;i++)
		printf("		[%d] ��Ŀ%d -- %3.1lf\n",4+i,i+1,man->score[i]);
	printf("		=======================\n\n");
}

void AddSTU()
{
ag:	system("cls");
	printf("		���ѧ����Ϣ\n");
	dayindangqianxuesheng();
	printf("���������롣ѧ������-1�˳���\n");
	STU *p=CreateSTU();
	printf("		[1] ѧ�� -- ");
	fflush(stdin);
	if(scanf("%d",&p->id)==EOF)
		goto bye;
	if(p->id==-1)
		goto bye;
	STU *find=L->head->next;
	while(find)//ȷ��û�мӹ�
	{
		if(find->id==p->id)
		{
			printf("		ERROR���� ��ѧ�����ڣ������ظ���ӣ�\n");
			system("pause");
			goto ag;
bye:		fflush(stdin);
			delete(p);
			return;
		}
		find=find->next;
	}

	printf("		[2] ���� -- ");
	cin>>p->name;
	printf("		[3] �Ա�(��=1,Ů=0) -- ");
	cin>>p->sex;
	for(int i=0;i<5;i++)
	{
		printf("		[%d] ��Ŀ%d -- ",4+i,i+1);
		cin>>p->score[i];
	}
	printf("\n\n		��ӳɹ�������ӵ�ѧ����Ϣ�ǣ�\n\n");
	printSTUINFO(p);
	printf("������������ N,����������������");
	fflush(stdin);
	char ch;
	cin>>ch;
	if(ch=='N')
		goto bye;
	L->num++;
	L->tail->next=p;
	L->tail=p;
	RewriteFile();
	system("pause");
	return;
}

void dayindangqianxuesheng()
{
	printf("		=======================\n		��ǰѧ���б���\n");
	STU *search;
	search=L->head->next;
	while(search!=NULL)
	{
		printf("		");
		for(int i=0;i<5&&search!=NULL;i++)
		{
			printf("%4d",search->id);
			search=search->next;
		}
		printf("\n");
	}
	printf("		=======================\n\n");
}
