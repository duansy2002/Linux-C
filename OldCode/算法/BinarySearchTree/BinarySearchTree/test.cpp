#include<iostream>
using std::cout;
class A {
private:
	int x;
	int y;
	int z;
public:
	A(): x(0),y(0),z(0){};
	A(int val): x(val){};
	virtual void printA() {cout<<"x = "<<x<<",y = "<<y<<",z = "<<z<<std::endl;}
};
using std::cout;
class book {
public:
	int a;
	int b;

	book(): a(9),b(-1){}
	virtual void print33(){cout<<(a*10)<<std::endl;}
	void print1(){cout<<"asd"<<std::endl;}
	void print12(){cout<<a+1<<std::endl;}

};

class novel : public book {
public:
	int num;
	int a;
	void print(){cout<<"heheda\n"<<std::endl;}
	virtual void print123(){cout<<"heheda\n"<<std::endl;}
	novel(): num(11){}
};

int main()
{
	book history;
	novel GoneWith;
	(dynamic_cast<book*> (&GoneWith))->print12();
	/*GoneWith��Ϊcast���������Լ��ķ�Χ�����GoneWith��print��Ա������*/
	//int cd = (dynamic_cast<novel*> (&history))->num;
	/*�Բ���cd��ô���ã�ֻ������ָ��ķ�Χ���������Ƭ����û���ݰ�*/
	/*����û�е������캯����ֻ�Ƕ�ȡ��һƬδ�����ڴ�*/
	/*��������ǲ���ȫ�ģ���ʱ�ᱨ��*/
	//(dynamic_cast<novel*> (&history))->print12();/*history��չΪһ��novel*/
	//historyת��Ϊnovel����ô������ȥѰ��novel�µĺ���.˵����Щ�����ǵ����ų����ġ�
	/*print33û�����⣬��̬�󶨵ġ���print��history ��û�к��ʵĿռ������print������˵�����print���Ժ��������ʽ���ڣ����Ǿ�̬*/
	/*���ﱨ���ˣ����ʳ�ͻ��������ڱ���a�ķ���������*/
	/*ֻ�Ǳ�������Ϊ���ı߽���չ���ȷ��ʵ�ʱ��ͻ����һ����ԭ����a���ǵġ��ڴ��в����ڵ�a*/
	/*�ɼ���ǿ��ת�������Ĳ���ȫ�ԡ������Ǹ����С�ռ��ָ��ת���ɸ���ϴ�ռ��ָ��ʱ*/
	
	/*�����������cast�Ľ����ͬ*/
	(dynamic_cast<novel*> (&history))->print12();/*history��չΪһ��novel������*/
	(reinterpret_cast<novel*> (&history))->print12();/*history��չΪһ��novel�����������10*/
	(static_cast<novel*> (&history))->print12();/*history��չΪһ��novel�����10 ---��˵�����ʵ���book::a������novel::a */

	return 0;
}

/* 
conslusion:
class won't call it's constructor twice.
*/