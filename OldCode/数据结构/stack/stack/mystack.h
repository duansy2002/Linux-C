#define N 100
struct stack{//����Ϊ100��ջ
	int data[N];
	int top;
}S;

void Initialize(stack &S)//��ʼ����ջ��ָ�벻ָ���κ�Ԫ��
{
	S.top=-1;
}
bool StackEmpty(stack S)//�ж�ջ�Ƿ�Ϊ��
{
	if(S.top==-1)
		return true;
	else
		return false;
}
bool Push(stack &S,int a)//��int a��ջ
//��Ҫ�޸�S������Ҫ�õ�ַ����ʽ����ͬ
{
	if(S.top==N-1)
		return false;
	S.data[++S.top]=a;
	return true;
}
bool Pop(stack &s,int &x)//��ջ��һ��intֵ
{
	if(s.top<0)
		return false;
	x=s.data[s.top--];
	return true;
}
bool GetTop(stack *s,int *x)//��ȡջ��Ԫ��
//�����ָ����ʽдһ�£�ԭ����һ���ġ������Ҿ���bool�����Ż��ǲ�ϰ�ߣ���ϲ����VOID����INT
{
	if(s->top==-1)
		return false;
	*x=s->data[s->top];
	return true;
}