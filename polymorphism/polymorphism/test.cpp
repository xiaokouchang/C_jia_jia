//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	//�麯��
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};


//ȫ�ֺ������ܹ����麯��,ֻ�г�Ա����ǰ�����virtual���ܹ����麯��
//virtual void BuyTicket()
//{
//	cout << "��Ʊ-ȫ��" << endl;
//}


//�������
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}


//�������
//��������Բ�дvirtual
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}


//Э��
//���1 --- ��ǰ���ӹ�ϵ
//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	virtual Person* BuyTicket()
//	{ 
//		cout << "��Ʊ-ȫ��" << endl;
//		return 0;
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual Student* BuyTicket() 
//	{ 
//		cout << "��Ʊ-���" << endl; 
//		return 0;
//	}
//	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}


//Э��
//���2 --- ���ǵ�ǰ���ӹ�ϵ
//#include<iostream>
//using namespace std;
//class A
//{};
//
//class B :public A
//{};
//
//class Person 
//{
//public:
//	virtual A* BuyTicket()
//	{ 
//		cout << "��Ʊ-ȫ��" << endl;
//		return 0;
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual B* BuyTicket() 
//	{ 
//		cout << "��Ʊ-���" << endl; 
//		return 0;
//	}
//	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}


//����������virtual,���麯����д,��Ϊ�������������������destructor���ͳһ������
//ΪʲôҪ��������?��ΪҪ�����ǹ�����д
//ΪʲôҪ�����ǹ�����д?
//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	~Person() 
//	{ 
//		cout << "~Person()" << endl; 
//	}
//};
//class Student : public Person 
//{
//public:
//	~Student() 
//	{ 
//		cout << "~Student()" << endl; 
//		delete[] ptr;
//	}
//private:
//	int* ptr = new int[10];
//};
//int main()
//{
//	//Person p;
//	//Student s;
//
//	Person* p = new Person;
//	delete p;
//
//	p = new Student;
//	delete p;//p->destructor() + operator delete(p)
//
//	//��������p->destructor()��һ����̬����,��������ͨ����
// 	return 0;
//}


//final,�����麯��,��ʾ���麯�������ٱ���д
//#include<iostream>
//using namespace std;
//class Car
//{
//public:
//	virtual void Drive() final 
//	{}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() 
//	{ 
//		cout << "Benz-����" << endl;
//	}
//};
//int main()
//{
//	Benz b;
//	b.Drive();
//	return 0;
//}


//override:����������麯���Ƿ���д�˻���ĳ���麯��,���û����д���뱨��
//#include<iostream>
//using namespace std;
//class Car 
//{
//public:
//	virtual void Drive() 
//	{
//		cout << "virtual void Drive() " << endl;
//	}
//};
//class Benz :public Car 
//{
//public:
//	virtual void Drive() override 
//	{ 
//		cout << "Benz-����" << endl; 
//	}
//};
//int main()
//{
//	Benz b;
//	b.Drive();
//	return 0;
//}


//���һ����,���ܱ��̳�
//����1
//#include<iostream>
//using namespace std;
//class A
//{
////public:
//private:
//	A()
//	{}
//};
//class B:public A
//{ };
//int main()
//{
//	B b;
//	return 0;
//}


//����2
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	static A CreatObj()
//	{
//		//���������,������������
//		return A();
//	}
//private:
//	A()
//	{}
//};
//class B:public A
//{ };
//int main()
//{
//	A::CreatObj();
//	return 0;
//}


//����3
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//private:
//	~A()
//	{}
//};
//class B :public A
//{
//};
//int main()
//{
//	A* p = new A;
//	//B b;
//	return 0;
//}


//c++11
//����4
//#include<iostream>
//using namespace std;
//class A final
//{
//public:
//	A() 
//	{}
//private:
//};
//class B :public A 
//{
//};
//int main()
//{
//	A a;
//	return 0;
//}


//�麯�����ڴ������,�麯�����������麯���ĵ�ַ
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func1()" << endl;
//	}     
//	void Func3()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	char _b = 1;
//};
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base b;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Car 
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car 
//{
//public:
//	virtual void Drive() override 
//	{ 
//		cout << "Benz-����" << endl; 
//	}
//};
//int main()
//{
//	Car c;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//	int _a = 1;
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() 
//	{ 
//		cout << "��Ʊ-���" << endl; 
//	}
//	int _b = 1;
//};
//void Func(Person& p)
//{
//	//�����϶�̬,������ʱ��ȷ�ϵ�ַ
//	//���϶�̬,����ʱ��ָ�������麯�������ҵ��ú����ĵ�ַ
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}


//virtual void func(int val = 1) + std::cout << "B->" << val << std::endl; 
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func(int val = 1) 
//	{ 
//		std::cout << "A->" << val << std::endl;
//	}
//	virtual void test() 
//	{ 
//		func();
//	}
//};
//class B : public A
//{
//public:
//	void func(int val = 0) 
//	{ 
//		std::cout << "B->" << val << std::endl; 
//	}
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func(int val = 1) 
//	{ 
//		std::cout << "A->" << val << std::endl;
//	}
//	
//};
//class B : public A
//{
//public:
//	void func(int val = 0) 
//	{ 
//		std::cout << "B->" << val << std::endl; 
//	}
//	virtual void test()
//	{
//		func();//this*ָ�����B*
//	}
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//	virtual void Func1()
//	{
//	}
//	virtual void Func2()
//	{
//	}
//protected:
//	int _a = 0;
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//protected:
//	int _b = 1;
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//
//	//������Ƭ
//	ps = st;
//	Person* ptr = &st;
//	Person& ref = st;
//	//Func(j);
//	return 0;
//}


//��֤���洢�ڴ�����
//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//	virtual void Func1()
//	{
//	}
//	virtual void Func2()
//	{
//	}
//protected:
//	int _a = 0;
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//protected:
//	int _b = 1;
//};
//int main()
//{
//	int a = 0;
//	printf("ջ:%p\n", &a);
//	static int b = 0;
//	printf("��̬��:%p\n", &b);
//	int* c = new int;
//	printf("����:%p\n", &c);
//	const char* d = "hello world";
//	printf("������(�����):%p\n", d);
//	Person ps1;
//	Student st1;
//	printf("���1:%p\n", *((int*)&ps1));
//	printf("���2:%p\n", *((int*)&st1));
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//	virtual void Func1()
//	{
//		cout << "Person:Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Person:Func2()" << endl;
//	}
//protected:
//	int _a = 0;
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "Student:Func3()" << endl;
//	}
//protected:
//	int _b = 1;
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
////��ӡ����ָ������
//typedef void(*FUNC_PIR) ();
////void PrintVFT(FUNC_PIR table[])
//void PrintVFT(FUNC_PIR* table)
//{
//	for (size_t i = 0; table[i] != nullptr; i++)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		FUNC_PIR f = table[i];
//		f();
//	}
//	printf("\n");
//}
//int main()
//{
//	Person ps;
//	Student st;
//	int vft1 = *((int*)&ps);//ȡ��4���ֽ�
//	PrintVFT((FUNC_PIR*)vft1);
//
//	int vft2 = *((int*)&st);
//	PrintVFT((FUNC_PIR*)vft2);
//	return 0;
//}


//��̬��
//#include<iostream>
//using namespace std;
//int main()
//{
//	int i = 0;
//	double d = 1.1;
//	cout << i << endl;
//	cout << d << endl;
//	return 0;
//}


#include<iostream>
using namespace std;
class Base1 
{
public:
	virtual void func1() 
	{ 
		cout << "Base1::func1" << endl; 
	}
	virtual void func2() 
	{ 
		cout << "Base1::func2" << endl; 
	}
private:
	int b1;
};
class Base2 
{
public:
	virtual void func1() 
	{ 
		cout << "Base2::func1" << endl; 
	}
	virtual void func2() 
	{ 
		cout << "Base2::func2" << endl; 
	}
private:
	int b2;
};
class Derive : public Base1, public Base2 
{
public:
	virtual void func1() 
	{ 
		cout << "Derive::func1" << endl; 
	}
	virtual void func3() 
	{ 
		cout << "Derive::func3" << endl; 
	}
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << "����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("��%d���麯����ַ:0X%x->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	//Derive d;
	//Base1 b1;
	//Base2 b2;
	//cout << "sizeof(d):" << sizeof(d) << endl;
	//int vft1 = *((int*)&d);
	//PrintVTable((VFPTR*)vft1);

	////����1
	////int vft2 = *((int*)((char*)&d + sizeof(Base1)));
	////����2
	//Base2* ptr = &d;
	//int vft2 = *((int*)ptr);
	//PrintVTable((VFPTR*)vft2);


	Derive d;

	Base1* ptr1 = &d;
	ptr1->func1();

	Base2* ptr2 = &d;
	ptr2->func1();

	Derive* ptr3 = &d;
	ptr3->func1();
	return 0;
}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


