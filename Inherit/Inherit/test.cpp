//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//	string _name = "peter"; //姓名
//	int _age = 18;			//年龄
//};
//class Student : public Person
//{
//protected:
//	int _stuid; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; //工号
//};
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//	//赋值兼容
//	//p = t;//子类可以给父类
//	//t = p;
//	//t = (Student)p;
//
//	//Person& p1 = s;
//	//Person p2 = s;
//	//s._name = "张三";
//
//	Person* ptr = &s;
//	ptr->_name = "李四";
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	void func()
//	{
//		cout << "Person" << endl;
//	}
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void func(int i)
//	{
//		//子类和父类的两个func构成隐藏/重定义
//		cout << "Student : public Person" << endl;
//	}
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;//就近原则,先查找子类的作用域
//	}
//protected:
//	int _num = 999; // 学号
//};
//int main()
//{
//	Student s1;
//	s1.Print();
//	s1.func(1);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//		delete _pstr;
//	}
//protected:
//	string _name; // 姓名
//	string* _pstr = new string("111111");
//};
//class student : public Person
//{
//public:
//	student(const char* name = "张三",int id = 0)
//		:Person(name)
//		,_id(0)
//		//,_name(name)
//	{ }
//	student(const student& s)
//		:_id(s._id)
//		, Person(s)
//	{}
//	student& operator=(const student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//		return *this;
//	}
//	~student()
//	{
//		//由于后面多态的原因,析构函数的函数名被特殊处理
//		//统一处理成destructor
//		cout << *_pstr << endl;
//		//Person::~Person();
//		//显示调用父类析构,无法保证先子后父
//		//所以子类析构函数完成后,自动调用父类析构,这样就保证了先子后父
//		delete _ptr;
//	}
//protected:
//	int _id;
//	int* _ptr = new int;
//};
//int main()
//{
//	student s1;
//	student s2(s1);
//	student s3("李四", 1);
//	s1 = s3;
//	return 0;
//}


//友元
//#include<iostream>
//using namespace std;
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}


//静态成员
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person() { ++_count; }
////protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//int main()
//{
//	Person p;
//	Student s1;
//	Student s2;
//	cout << p._count << endl;
//
//	//cout << &p._name << endl;
//	//cout << &s._name << endl;
//	//cout << &p._count << endl;
//	//cout << &s._count << endl;
//	//cout << &Person::_count << endl;
//	//cout << &Student::_count << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	string _name; // 姓名
//	int _age;
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	Assistant as;
//	as.Teacher::_age = 18;
//	as.Student::_age = 30;
//	as._age = 19;
//	return 0;
//}


#include<iostream>
using namespace std;
class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;
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


