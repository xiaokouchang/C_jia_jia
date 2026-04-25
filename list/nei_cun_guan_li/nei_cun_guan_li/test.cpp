#define _CRT_SECURE_NO_WARNINGS 1 

//内存管理
//程序中的数据
//局部数据:目前使用,过一会就会销毁,存储在函数的栈帧里面
//静态数据和全局数据:生命周期在全局,可以一直用,在局部域或者当前文件使用
//常量数据:直接定义的,不能修改
//动态申请数据:数据结构
//程序存储在磁盘上,是文件

//#include<iostream>
//using namespace std;
//int main()
//{
//	//a和b存储在栈区
//	int a = 1;
//	const int b = 2;
//	cout << &a << endl;
//	cout << &b << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//void Test()
//{
//	//动态申请一个int类型的空间
//	//C
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	//C++
//	int* p2 = new int;
//	delete p2;//free(p2);
//
//	//动态申请10个int类型的空间
//	//C
//	int* p3 = (int*)malloc(sizeof(int) * 10);
//	free(p3);
//	//C++
//	int* p4 = new int[10];
//	delete[] p4;
//
//	//动态申请一个int类型的空间并初始化为10
//	//C
//	int* p5 = (int*)calloc(10, sizeof(int));
//	free(p5);
//	//C++
//	int* p6= new int(10);
//	delete p6;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//C语言
//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int _val;
//	struct ListNode* _next;
//};
//struct ListNode* BuyListNode(int x)
//{
//	//单纯的开空间
//	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	newnode->_next = NULL;
//	newnode->_val = x;
//	return newnode;
//}
//int main()
//{
//	struct ListNode* n1 = BuyListNode(1);
//	struct ListNode* n2 = BuyListNode(2);
//	struct ListNode* n3 = BuyListNode(3);
//	return 0;
//}


//C++
//#include<iostream>
//using namespace std;
//class ListNode
//{
//public:
//	//构造函数
//	ListNode(int x)
//	//初始化列表
//		: _val(x)
//		, _next(NULL)
//	//函数体
//	{}
//private:
//	int _val;
//	struct ListNode* _next;
//};
//int main()
//{
//	//开空间并调用构造函数
//	ListNode* nn1 = new ListNode(1);
//	ListNode* nn2 = new ListNode(2);
//	ListNode* nn3 = new ListNode(3);
//	return 0;
//}


//malloc和free、delete和new匹配使用
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0,int b = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	//A(int a = 0,int b = 0)
//	//	: _a(a)
//	//{
//	//	cout << "A():" << this << endl;
//	//}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1,1);
//	free(p1);
//	delete p2;
//	//内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	//A* p6 = new A[4]{ 1,2,3,4 };
//	//A(int a) --- 构造函数
//	//A* p6 = new A[4]{ A(1),A(2),A(3),A(4) };
//	//A(int a, int b) --- 构造函数
//	A* p6 = new A[4]{ A(1,1),A(2,2),A(3,3)};
//	free(p5);
//	delete[] p6;
//	return 0;
//}


//面向对象语言处理失败,不使用返回值,更建议用抛异常
//使用new会调用operator new,operator new对malloc进行了封装,如果开辟空间失败会抛出bad allocation
//开辟空间成功后会调用构造函数。
//delete先调用析构函数清理资源,然后释放空间,释放空间时调用operator delete,然后调用free函数
//#include<iostream>
//using namespace std;
//int main()
//{
//	//int* p1 = (int*)operator new(sizeof(int));
//	//operator delete(p1);
//	//int* p2 = new int;
//	//delete(p2);
//
//
//	//x86是32位的,x64是64位的
//	//32位是4G
//	int* p1 = nullptr;
//	try
//	{
//		do
//		{
//			//p1 = (int*)malloc(1024 * 1024);//失败了返回NULL,申请的是虚拟内存
//			p1 = new int[1024 * 1024];
//			cout << p1 << endl;
//		} while (p1);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}
//int main()
//{
//	//需要申请1个堆上的栈对象
//	Stack* p1 = new Stack;
//	delete p1;
//	return 0;
//}


//定位new
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	//p1现在指向的只不过是与A对象相同大小的一段空间,还不能算是一个对象,因为构造函数没有执行
//	//任何类型的指针都是内置类型
//	//只有自定义类型才能自动调用构造函数和析构函数
//	//内置类型不会自动调用构造函数和析构函数。
//	A* p1 = (A*)malloc(sizeof(A));
//	//显示调用构造函数
//	new(p1)A; //如果A类的构造函数有参数时,此处需要传参
//	p1->~A();
//	free(p1);
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}


//内存泄漏
//普通程序内存泄漏影响不大,进程正常结束后会正常释放资源
//长期运行的程序内存泄漏危害很大
//#include<iostream>
//using namespace std;
//int main()
//{
//	char* p1 = new char[1024 * 1024 * 1024] {'b', 'o', 'y', '\0'};
//	cout << (void*)p1 << endl;
//	_CrtDumpMemoryLeaks();
//	//delete[] p1;
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