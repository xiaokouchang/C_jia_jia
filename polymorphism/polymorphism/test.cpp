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


