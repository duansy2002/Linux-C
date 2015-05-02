#include "Linkedlist.h"

node* IfCircle(node * head)//����ֵΪ������㣬û�л��򷵻ؿ�
{
	if(head==NULL||head->next==NULL)
		return NULL;
	node *slow=head->next;
	node *fast=slow;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		{
			fast=head->next;//�μ�˼·2�ķ���
			while(fast!=slow)//��ʱ�Ѿ�ȷ���л�������Ҫ�߽�����
			{
				slow=slow->next;
				fast=fast->next;//��ʱ�������N�����ĳ��ȣ�����fast�ĳ�һ����1��
			}
			return fast;
		}
	}
	return NULL;
}

//˼·1�������ͷ��ʼ���ʣ��ڵ��ַ�浽����ռ��У�ÿ����һ���ڵ㶼���ѯǰ���Ƿ����ظ���
//		 �÷����ռ临�Ӷ�O(N), ʱ�临�Ӷ�O(N*N),����һ���÷�����
//˼·2������ָ�붼��ͷ��㿪ʼ���ʣ�һ���ٶ�Ϊ1��һ���ٶ�Ϊ2������������ý��㡣
//������������leetcode��������ͬһ������д�ķ�����
/*Assuming that:

                   S1 = the distance between headA and the intersection (����)

                     T = the circle's length                  (S1 + T = all nodes)
And:

                   S1 = n*T + delta (int n)
what we know is 'slow''s speed is 1, 'fast''s speed is 2

1-Now we start from headA------

Before slow == fast ,we need to run [S1/T]*T + T = (S1 + T - delta) step.

2-Then we set 'fast' = headA ( and set fast's speed to 1) It means that--now the distance between 'slow' and 'fast' = n*T

3-After another n*T step, slow and fast arrive the intersection!

So, totoaly we move about 2*S1 + T step. Time complexity is O(n)!*/