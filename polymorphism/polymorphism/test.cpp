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
#include<iostream>
using namespace std;
class Person 
{
public:
	~Person() 
	{ 
		cout << "~Person()" << endl; 
	}
};
class Student : public Person 
{
public:
	~Student() 
	{ 
		cout << "~Student()" << endl; 
		delete[] ptr;
	}
private:
	int* ptr = new int[10];
};
int main()
{
	//Person p;
	//Student s;

	Person* p = new Person;
	delete p;

	p = new Student;
	delete p;//p->destructor() + operator delete(p)

	//这里期望p->destructor()是一个多态调用,而不是普通调用
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


