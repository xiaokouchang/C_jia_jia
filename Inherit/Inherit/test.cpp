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
//	string _name = "peter"; //����
//	int _age = 18;			//����
//};
//class Student : public Person
//{
//protected:
//	int _stuid; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; //����
//};
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//	//��ֵ����
//	//p = t;//������Ը�����
//	//t = p;
//	//t = (Student)p;
//
//	//Person& p1 = s;
//	//Person p2 = s;
//	//s._name = "����";
//
//	Person* ptr = &s;
//	ptr->_name = "����";
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
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void func(int i)
//	{
//		//����͸��������func��������/�ض���
//		cout << "Student : public Person" << endl;
//	}
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;//�ͽ�ԭ��,�Ȳ��������������
//	}
//protected:
//	int _num = 999; // ѧ��
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
//	string _name; // ����
//	string* _pstr = new string("111111");
//};
//class student : public Person
//{
//public:
//	student(const char* name = "����",int id = 0)
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
//		//���ں����̬��ԭ��,���������ĺ����������⴦��
//		//ͳһ�����destructor
//		cout << *_pstr << endl;
//		//Person::~Person();
//		//��ʾ���ø�������,�޷���֤���Ӻ�
//		//������������������ɺ�,�Զ����ø�������,�����ͱ�֤�����Ӻ�
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
//	student s3("����", 1);
//	s1 = s3;
//	return 0;
//}


//��Ԫ
//#include<iostream>
//using namespace std;
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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


//��̬��Ա
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person() { ++_count; }
////protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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
//	string _name; // ����
//	int _age;
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
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


