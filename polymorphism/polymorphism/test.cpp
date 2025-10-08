//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	//虚函数
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};


//全局函数不能构成虚函数,只有成员函数前面添加virtual才能构成虚函数
//virtual void BuyTicket()
//{
//	cout << "买票-全价" << endl;
//}


//正常情况
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
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


//特殊情况
//派生类可以不写virtual
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
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


//协变
//情况1 --- 当前父子关系
//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	virtual Person* BuyTicket()
//	{ 
//		cout << "买票-全价" << endl;
//		return 0;
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual Student* BuyTicket() 
//	{ 
//		cout << "买票-半价" << endl; 
//		return 0;
//	}
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
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


//协变
//情况2 --- 不是当前父子关系
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
//		cout << "买票-全价" << endl;
//		return 0;
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual B* BuyTicket() 
//	{ 
//		cout << "买票-半价" << endl; 
//		return 0;
//	}
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
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


//析构函数加virtual,是虚函数重写,因为类析构函数都被处理成destructor这个统一的名字
//为什么要这样处理?因为要让他们构成重写
//为什么要让他们构成重写?
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
//	//这里期望p->destructor()是一个多态调用,而不是普通调用
// 	return 0;
//}


//final,修饰虚函数,表示该虚函数不能再被重写
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
//		cout << "Benz-舒适" << endl;
//	}
//};
//int main()
//{
//	Benz b;
//	b.Drive();
//	return 0;
//}


//override:检查派生类虚函数是否重写了基类某个虚函数,如果没有重写编译报错。
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
//		cout << "Benz-舒适" << endl; 
//	}
//};
//int main()
//{
//	Benz b;
//	b.Drive();
//	return 0;
//}


//设计一个类,不能被继承
//方法1
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


//方法2
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	static A CreatObj()
//	{
//		//对象调函数,函数创建对象
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


//方法3
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
//方法4
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


//虚函数放在代码段里,虚函数表里存放着虚函数的地址
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
//		cout << "Benz-舒适" << endl; 
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
//		cout << "买票-全价" << endl;
//	}
//	int _a = 1;
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() 
//	{ 
//		cout << "买票-半价" << endl; 
//	}
//	int _b = 1;
//};
//void Func(Person& p)
//{
//	//不符合多态,编译器时就确认地址
//	//符合多态,运行时到指向对象的虚函数表中找调用函数的地址
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
//		func();//this*指向的是B*
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
//		cout << "买票-全价" << endl;
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
//		cout << "买票-半价" << endl;
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
//	//三种切片
//	ps = st;
//	Person* ptr = &st;
//	Person& ref = st;
//	//Func(j);
//	return 0;
//}


//验证虚表存储在代码区
//#include<iostream>
//using namespace std;
//class Person 
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
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
//		cout << "买票-半价" << endl;
//	}
//protected:
//	int _b = 1;
//};
//int main()
//{
//	int a = 0;
//	printf("栈:%p\n", &a);
//	static int b = 0;
//	printf("静态区:%p\n", &b);
//	int* c = new int;
//	printf("堆区:%p\n", &c);
//	const char* d = "hello world";
//	printf("常量区(代码段):%p\n", d);
//	Person ps1;
//	Student st1;
//	printf("虚表1:%p\n", *((int*)&ps1));
//	printf("虚表2:%p\n", *((int*)&st1));
//	return 0;
//}


#include<iostream>
using namespace std;
class Person 
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
	virtual void Func1()
	{
		cout << "Person:Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Person:Func2()" << endl;
	}
//protected:
	int _a = 0;
};
class Student : public Person 
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
	virtual void func3()
	{
		cout << "Student:Func3()" << endl;
	}
protected:
	int _b = 1;
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps1;
	Student st1;

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


//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


