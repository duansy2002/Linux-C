/*��22�� n��ѧ���ĳɼ������������з���һ����ͷ�ڵ������ṹ�У�
hָ�������ͷ�ڵ㡣���д����fun��
���Ĺ����ǣ��ҳ�ѧ������߷֣��ɺ���ֵ����*/
#include<iostream>
struct student{
	int score;
	student *next;
};

int fun(student *head)
{
	int high;
	student *p=head;
	high=p->score;
	while(p!=NULL)
	{
		if(p->score>high)
			high=p->score;
		p=p->next;
	}
	return high;
}

int main()
{
	student stu1,stu2,stu3,stu4;
	stu1.score=12;
	stu2.score=8979;
	stu3.score=99;
	stu4.score=77;

	stu1.next=&stu2;
	stu2.next=&stu3;
	stu3.next=&stu4;
	stu4.next=NULL;//��ָ�룡�����ˣ�������

	int high=fun(&stu1);
	std::cout<<high;
	getchar();
}