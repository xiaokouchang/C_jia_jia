#define _CRT_SECURE_NO_WARNINGS 1 
//C语言是面向过程的,关注的是过程,分析出求解问题的步骤,通过函数调用逐步解决问题
//C++是基于面向对象的,关注的是对象,将一件事情拆分成不同的对象,靠对象之间的交互完成
//面向对象关注对象和对象之间的关系和交互

//类的引入
//C语言结构体中只能定义变量, 在C++中, 结构体内不仅可以定义变量, 也可以定义函数
//之前在数据结构初阶中, 用C语言方式实现的栈, 结构体中只能定义变量;
//现在以C++方式实现,会发现struct中也可以定义函数
//C++里面花括号里面定义的都是域
//类域
//#include<iostream>
//using namespace std;
//struct Queue
//{
//
//};
//struct Stack
//{
//	//成员函数
//	void Init(int defaultcapacity = 4)
//	{
//		a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		capacity = defaultcapacity;
//		top = 0;
//	}
//	void Push(int x)
//	{
//		a[top++] = x;
//	}
//	void Destory()
//	{
//		free(a);
//		a = nullptr;
//		top = capacity;
//	}
//	//成员变量
//	//可以写在成员函数之前或之后
//	int* a;
//	int top;
//	int capacity;
//};
////C++兼容C语言,struct以前的用法都可以继续使用
////同时struct升级成了类
//int main()
//{
//	struct Stack st1;
//	st1.Init(20);
//	Stack st2;
//	st2.Init();
//	st2.Push(1);
//	st2.Push(2);
//	st2.Push(3);
//	st2.Push(4);
//	st2.Destory();
//	return 0;
//}


//类
//class className
//{
//	//类体:由成员函数和成员变量组成
//};  //一定要注意后面的分号
//访问限定符
//public修饰的成员在类外可以直接被访问
//protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
//访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
//如果后面没有访问限定符,作用域就到}即类结束
//class的默认访问权限为private,struct为public(因为struct要兼容C)
//#include<iostream>
//using namespace std;
////struct和class都可以使用访问限定符
////只要是类都可以使用访问限定符
////不写访问限定符,class默认是私有的,struct默认是公有的
//class Stack
//{
//public:
//	//成员函数
//	void Init(int defaultcapacity = 4)
//	{
//		a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		capacity = defaultcapacity;
//		top = 0;
//	}
//	void Push(int x)
//	{
//		a[top++] = x;
//	}
//	void Destory()
//	{
//		free(a);
//		a = nullptr;
//		top = capacity;
//	}
//	//成员变量
//	//可以写在成员函数之前或之后
//private:
//	int* a;
//	int top;
//	int capacity;
//};
////C++兼容C语言,struct以前的用法都可以继续使用
////同时struct升级成了类
//int main()
//{
//	struct Stack st1;
//	st1.Init(20);
//	Stack st2;
//	st2.Init();
//	st2.Push(1);
//	st2.Push(2);
//	st2.Push(3);
//	st2.Push(4);
//	st2.Destory();
//	return 0;
//}


//class Date
//{
//public:
//	void Init(int year)
//	{
//		year = year;
//	}
//	//局部优先
//private:
//	int _year;//成员变量
//	int _month;
//	int _day;
//};


//封装
//局部域和全局域会影响生命周期
//类域和命名空间域不会影响生命周期
//命名空间不展开不会访问
//#include<iostream>
//#include"class.h"
//using namespace std;
//int main()
//{
//	//类实例化对象/对象定义
//	//st1和st2是两个对象
//	Stack st1;//整体定义
//	Stack st2;
//	//不能,类访问top是声明,top不能存数据
//	//st1和st2不是同一个对象,top不同,Push是同一个函数
//	//Stack::top = 1;
//	//St1::top = 1;
//	//st1.Init();
//	//st1.top = 0;
//	//st1.Push(1);
//	//st2.Init();
//	//st2.top = 1;
//	//st2.Push(1);
//	//对象中只存储成员变量,没有存储成员函数
//	cout << sizeof(Stack) << endl;
//	return 0;
//}


//#include<iostream>
//#include"class.h"
//using namespace std;
//int main()
//{
//	//st1和st2是两个对象
//	Stack st1;//整体定义
//	Stack st2;
//	//st1和st2不是同一个对象,top不同,Push是同一个函数
//	//对象中只存储成员变量,没有存储成员函数
//	cout << sizeof(Stack) << endl;
//	cout << "&st1:" << &st1 << endl;
//	cout << "&st2:" << &st2 << endl;
//	return 0;
//}


//#include"class.h"
//#include<iostream>
//using namespace std;
//int main()
//{
//	A aa1;
//	A aa2;
//	A aa3;
//	//不考虑成员函数
//	cout << sizeof(A) << endl;
//	cout << sizeof(aa1) << endl;
//	//aa1._a = 1;
//	aa1.PrintA();
//	return 0;
//}


//#include<iostream>
//#include"class.h"
//using namespace std;
//int main()
//{
//	A2 aa1;
//	A2 aa2;
//	cout << sizeof(A1) << endl;
//	//没有成员变量的类对象,需要1byte,是为了占位,表示对象存在
//	//不存储有效数据
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	cout << &aa1 << endl;
//	cout << &aa2 << endl;
//	return 0;
//}


//this指针
//this不能在形参和实参显示传递,但是可以在函数内部显示使用
//对象大小没算this指针
//this指针存在哪里?栈 对象里面 堆 静态区 常量区
//this指针是形参,所以this指针是跟普通参数一样存在函数调用的栈帧里面。
//this存在栈区
//VS下面对this指针传递,进行了优化,对象地址是放在ecx,ecx存储this指针的值
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//void Print()
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;
//	//}
//	//this指针
//	//void Print(Date* const this)
//	void Print()
//	{
//		//this不能在形参和实参显示传递,但是可以在函数内部显示使用
//		//this = nullptr;
//		cout << this << endl;
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//private:
//	int _year;  //年,声明
//	int _month; //月
//	int _day;   //日
//};
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	d2.Print();
//	//d1.Print(&d1);
//	//d2.Print(&d2);
//	//Date::_year;
//	//d1::_year;//左边必须是类名
//	return 0;
//}


//下面程序编译运行结果是正常运行
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;//this指针是空的,但是函数内部没有对this指针解引用
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	//P调用Print,不会发生解引用,因为Print的地址不在对象中
//	//p会作为实参传递给this指针
//	return 0;
//}


//下面程序编译运行结果是运行崩溃
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;//this指针是空的,但是函数内部访问_a,本质是this->_a
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}


//C语言实现栈
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//typedef int DataType;
//typedef struct Stack
//{
//	DataType* array;
//	int capacity;
//	int size;
//}Stack;
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->array = (DataType*)malloc(sizeof(DataType) * 3);
//	if (NULL == ps->array)
//	{
//		assert(0);
//		return;
//	}
//	ps->capacity = 3;
//	ps->size = 0;
//}
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	if (ps->array)
//	{
//		free(ps->array);
//		ps->array = NULL;
//		ps->capacity = 0;
//		ps->size = 0;
//	}
//}
//void CheckCapacity(Stack* ps)
//{
//	if (ps->size == ps->capacity)
//	{
//		int newcapacity = ps->capacity * 2;
//		DataType* temp = (DataType*)realloc(ps->array,
//			newcapacity * sizeof(DataType));
//		if (temp == NULL)
//		{
//			perror("realloc申请空间失败!!!");
//			return;
//		}
//		ps->array = temp;
//		ps->capacity = newcapacity;
//	}
//}
//void StackPush(Stack* ps, DataType data)
//{
//	assert(ps);
//	CheckCapacity(ps);
//	ps->array[ps->size] = data;
//	ps->size++;
//}
//int StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return 0 == ps->size;
//}
//void StackPop(Stack* ps)
//{
//	if (StackEmpty(ps))
//		return;
//	ps->size--;
//}
//DataType StackTop(Stack* ps)
//{
//	assert(!StackEmpty(ps));
//	return ps->array[ps->size - 1];
//}
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->size;
//}
//int main()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	printf("%d\n", StackTop(&s));
//	printf("%d\n", StackSize(&s));
//	StackPop(&s);
//	StackPop(&s);
//	printf("%d\n", StackTop(&s));
//	printf("%d\n", StackSize(&s));
//	StackDestroy(&s);
//	return 0;
//}


//C++实现
//#include<iostream>
//using namespace std;
//typedef int DataType;
//class Stack
//{
//public:
//	void Init()
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * 3);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = 3;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	void Pop()
//	{
//		if (Empty())
//			return;
//		_size--;
//	}
//	DataType Top()
//	{ 
//		return _array[_size - 1]; 
//	}
//	int Empty()
//	{ 
//		return 0 == _size; 
//	}
//	int Size() 
//	{
//		return _size; 
//	}
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
//			if (temp == NULL)
//			{
//				perror("realloc申请空间失败!!!");
//				return;
//			}
//			_array = temp;
//			_capacity = newcapacity;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//int main()
//{
//	Stack s;
//	s.Init();
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//	s.Pop();
//	s.Pop();
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//	s.Destroy();
//	return 0;
//}


//如果一个类中什么成员都没有,简称为空类
//任何类在什么都不写时,编译器会自动生成以下6个默认成员函数
//默认成员函数:用户没有显式实现,编译器会生成的成员函数称为默认成员函数
//类的6个默认成员函数
//构造函数
//构造函数是一个特殊的成员函数,名字与类名相同,创建类类型对象时由编译器自动调用,
//以保证每个数据成员都有一个合适的初始值,并且在对象整个生命周期内只调用一次。
//特性
//构造函数是特殊的成员函数,需要注意的是,构造函数虽然名称叫构造,
//但是构造函数的主要任务并不是开空间创建对象,而是初始化对象
//其特征如下:
//1.函数名与类名相同
//2.无返回值
//3.对象实例化时编译器自动调用对应的构造函数
//4.构造函数可以重载


//析构函数
//与构造函数功能相反,析构函数不是完成对对象本身的销毁,局部对象销毁工作是由编译器完成的。
//而对象在销毁时会自动调用析构函数,完成对象中资源的清理工作
//特征
//1.析构函数名是在类名前加上字符~。
//2.无参数无返回值类型。
//3.一个类只能有一个析构函数。若未显式定义,系统会自动生成默认的析构函数。注意:析构函数不能重载
//4.对象生命周期结束时,C++编译系统系统自动调用析构函数。
//#include <iostream>
//using namespace std;
//typedef int DataType;
//class Stack
//{
//public:
//	//构造函数等价于Init
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = 4)" << endl;
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//	void Init()
//	{
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = 4;
//		_top = 0;
//	}
//	void Push(int x)
//	{
//		_a[_top++] = x;
//	}
//	//析构函数在对象生命周期结束后自动调用
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_a)
//		{
//			free(_a);
//			_a = nullptr;
//			_top = 0;
//			_capacity = 0;
//		}
//	}
//	void Destory()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity;
//	}
//	int Top()
//	{
//		return _a[_top - 1];
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	Stack s;
//	//构造函数等价于Init
//	//s.Init();
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	//s.Destory();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//typedef int DataType;
//class Stack
//{
//public:
//	//构造函数支持重载
//	Stack(DataType* a, int n)
//	{
//		cout << "Stack(DataType* a, int n)" << endl;
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(_a, a, sizeof(DataType) * n);
//		_capacity = n;
//		_top = 0;
//	}
//	//构造函数等价于Init
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = 4)" << endl;
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//	void Init()
//	{
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = 4;
//		_top = 0;
//	}
//	void Push(int x)
//	{
//		_a[_top++] = x;
//	}
//	//析构函数在对象生命周期结束后自动调用
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_a)
//		{
//			free(_a);
//			_a = nullptr;
//			_top = 0;
//			_capacity = 0;
//		}
//	}
//	void Destory()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity;
//	}
//	int Top()
//	{
//		return _a[_top - 1];
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	Stack s;
//	//构造函数等价于Init
//	//s.Init();
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	//s.Destory();
//	return 0;
//}


//没有构造函数
//如果类中没有显式定义构造函数,则C++编译器会自动生成一个无参的默认构造函数,
//一旦用户显式定义编译器将不再生成。
//内置类型/基本类型、语言本省定义的基础类型int/char/double/指针等等
//自定义、用struct/class等等定义的类型
//我们不写,编译器默认生成构造函数,内置类型不做处理,自定义类型会去调用它的默认构造
//一般情况下,有内置类型成员,就需要自己写构造函数,不能用编译器生成的
//全部都是自定义类型,可以考虑让编译器自己生成
//如果一旦显式定义任何构造函数,编译器将不再生成构造函数
//#include <iostream>
//using namespace std;
//typedef int DataType;
//class Stack
//{
//public:
//	//构造函数支持重载
//	Stack(DataType* a, int n)
//	{
//		cout << "Stack(DataType* a, int n)" << endl;
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(_a, a, sizeof(DataType) * n);
//		_capacity = n;
//		_top = 0;
//	}
//	//构造函数等价于Init
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = 4)" << endl;
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//	void Init()
//	{
//		_a = (DataType*)malloc(sizeof(DataType) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = 4;
//		_top = 0;
//	}
//	void Push(int x)
//	{
//		_a[_top++] = x;
//	}
//	//析构函数在对象生命周期结束后自动调用
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_a)
//		{
//			free(_a);
//			_a = nullptr;
//			_top = 0;
//			_capacity = 0;
//		}
//	}
//	void Destory()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity;
//	}
//	int Top()
//	{
//		return _a[_top - 1];
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//class Date
//{
//public:
//	//无参构造函数
//	//无参调用
//	Date()
//	{
//		cout << "Date()" << endl;
//		_year = 1;
//		_month = 2;
//		_day = 1;
//	}
//	//有参构造函数
//	Date(int year, int month, int day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//内置类型
//	//这里不是初始化,因为这里只是声明
//	//这里是缺省值,给编译器生成的默认构造函数用
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//	//自定义类型
//	//Stack _st;
//};
//int main()
//{
//	Date d1;
//	//Date d1();//不可以这样写,会跟函数声明有冲突,编译器不好识别
//	Date d2(2023, 1, 2);
//	d1.Print();
//	d2.Print();
//	return 0;
//}


//一般情况下,有动态申请资源,就需要显示写析构函数释放资源
//没有动态申请资源,不需要写析构
//需要释放资源的成员都是自定义类型,不需要写析构
//#include<iostream>
//using namespace std;
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = (int*)malloc(sizeof(int) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_top = 0;
//		_capacity = 4;
//	}
//	Stack(int capacity)
//	{
//		cout << "Stack(int capacity)" << endl;
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
////不需要写析构函数
//class Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//struct TreeNode
//{
//	TreeNode* _left;
//	TreeNode* _right;
//	int _val;
//	TreeNode(int val = 0)
//	{
//		_left = nullptr;
//		_right = nullptr;
//		_val = val;
//	}
//};
//class Tree
//{
//private:
//	TreeNode* _root = nullptr;
//};
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//int main()
//{
//	//静态的栈不需要销毁,出了作用域自动销毁
//	Stack st1;
//	//内置类型不做处理,自定义类型会去调用它的析构函数
//	Stack st2(4);
//	Tree t1;
//	TreeNode(1);
//	TreeNode(2);
//	MyQueue q1;
//	MyQueue q2;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数
//	//引用
//	Date(const Date& d)//类对象的引用
//	{
//		//引用
//		this->_year = d._year;
//		this->_month = d._month;
//		this->_day = d._day;
//	}
//
//
//	//指针
//	//Date(Date* d)
//	//{
//	//	_year = d->_year;
//	//	_month = d->_month;
//	//	_day = d->_day;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Func(Date d)
//{
//
//}
//void Func(int d)
//{
//
//}
//int main()
//{
//	Date d1(2023, 4, 25);
//	Date d2(d1);
//	//规定了自定义类型必须要用拷贝构造去完成
//	//自定义类型是拷贝构造
//	//指针
//	//Func(&d1);
//	//引用
//	//Func(d1);
//	//内置类型没有这样的规定
//	//内置类型直接拷贝
//	//Func(10);
//	return 0;
//}


//若未显式定义,编译器会生成默认的拷贝构造函数
//默认的拷贝构造函数对象按内存存储按字节序完成拷贝,这种拷贝叫做浅拷贝,或者值拷贝
//没有开辟空间
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2023, 4, 25);
//	Date d2(d1);
//	return 0;
//}


//开辟空间
//#include<iostream>
//using namespace std;
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = (int*)malloc(sizeof(int) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_top = 0;
//		_capacity = 4;
//	}
//	Stack(const Stack& st)
//	{
//		_a = (int*)malloc(sizeof(int) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	Stack st1;
//	//st2先析构,st1后析构,符合后进先出原则
//	Stack st2(st1);//拷贝构造函数拷贝的空间指向同一块内存,析构函数会将同一块内存2次释放
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = (int*)malloc(sizeof(int) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_top = 0;
//		_capacity = 4;
//	}
//	Stack(const Stack& st)
//	{
//		_a = (int*)malloc(sizeof(int) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//void func(Date& d)
//{
//
//}
////void func(Stack& st)
////{}
//
//Stack& func()
//{
//	//static Stack st;
//	Stack st;
//	return  st;
//}
//int main()
//{
//	Date d1;
//	func(d1);
//	
//	//Stack st;
//	//func(st);
//
//	//Stack st;
//	Stack ret = func();
//	return 0;
//}


//C++为了增强代码的可读性引入了运算符重载,运算符重载是具有特殊函数名的函数,
//也具有其返回值类型,函数名字以及参数列表,其返回值类型与参数列表与普通的函数类似
//函数名字为:关键字operator后面接需要重载的运算符符号
//函数原型:返回值类型operator操作符(参数列表)
//注意:
//不能通过连接其他符号来创建新的操作符:比如operator@
//重载操作符必须有一个类类型参数
//用于内置类型的运算符,其含义不能改变,例如:内置的整型+,不能改变其含义
//作为类成员函数重载时,其形参看起来比操作数数目少1,因为成员函数的第一个参数为隐藏的this
//.* :: sizeof ? : .注意以上5个运算符不能重载
//在全局函数中,操作符是几个操作数,重载函数就有几个参数。
//在成员函数中,重载函数少一个参数
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator<(const Date& x1, const Date& x2)
//{
//	if (x1._year < x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month < x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
//	{
//		return true;
//	}
//	return false;
//}
//bool operator>(const Date& x1, const Date& x2)
//{
//	if (x1._year < x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month < x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	Date d1(2023, 4, 25);
//	Date d2(2023, 5, 25);
//	d1 < d2;
//	operator<(d1, d2);
//	//内置类型可以直接比较,自定义类型不能直接比较
//	//<<流插入运算符的优先级高于比较运算符
//	/*cout << (d1 < d2) << endl;
//	cout << (operator<(d1, d2)) << endl;*/
//	//cout << (d1 > d2) << endl;
//	//cout << (operator>(d1, d2)) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	//构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//作为类成员函数重载时,其形参看起来比操作数数目少1,因为成员函数的第一个参数为隐藏的this
//	bool operator<(const Date& x)
//	{
//		if (this->_year < x._year)//这里等价于if (this->_year < x._year)
//		{
//			return true;
//		}
//		else if (this->_year == x._year && this->_month < x._month)
//		{
//			return true;
//		}
//		else if (this->_year == x._year && this->_month == x._month && this->_day < x._day)
//		{
//			return true;
//		}
//		return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 10, 27);
//	//日期-日期有意义
//	//日期+日期没意义
//	//是否要重载运算符,这个运算符对这个类是否有意义
//	//d1 < d2;//转换成operator<(d1, d2);
//	d1 < d2;//转换成d1.operator<(d2);
//	d1.operator<(d2);
//	if (d1 < d2)
//	{
//
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	//构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//作为类成员函数重载时,其形参看起来比操作数数目少1,因为成员函数的第一个参数为隐藏的this
//	bool operator<(const Date& x)
//	{
//		if (this->_year < x._year)//这里等价于if (this->_year < x._year)
//		{
//			return true;
//		}
//		else if (this->_year == x._year && this->_month < x._month)
//		{
//			return true;
//		}
//		else if (this->_year == x._year && this->_month == x._month && this->_day < x._day)
//		{
//			return true;
//		}
//		return false;
//	}
//	//void operator=(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	//函数返回会调用2次拷贝构造函数
//	//Date operator=(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//	return *this;
//	//}
//	//赋值运算符重载函数
//	//Date& operator=(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//	return *this;
//	//}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 10, 27);
//	Date d3(2018, 11, 28);
//	d1 = d2 = d3;
//
//	//d1 = d2;
//	//d1.operator=(d2);
//	//int i, j, k;
//	//i = j = k = 0;
//	return 0;
//}


//运算符重载是让自定义类型支持运算符
//两个运算符重载可以构成函数重载
//cout可以支持内置类型是因为库里面实现了
//cout可以支持自定识别类型是因为函数重载
//#include<iostream>
//#include"Date.h"
//using namespace std;
//void TestDate()
//{
//	//日期+-天数有价值
//	//Date d1(2025, 7, 12);
//	////d1 += 100;
//	//d1.operator+=(100);
//	//d1.Print();
//
//	//加不能改变自己
//	//int i = 0;
//	//i + 100;
//	//cout << i << endl;
//
//	//Date d3 = d2 + 100;//拷贝构造
//	//Date d4 = d2;//初始化d4,等价于Date d4(d2);
//	//d4 = d2;//赋值,两个已经存在的对象
//
//	//Date d2(2025, 7, 12);
//	//Date d3(d2 + 100);
//	//d2.Print();
//	//d3.Print();
//
//	//Date d1(2025, 7, 12);
//	////前置++返回++以后的对象,后置++返回++之前的对象
//	//d1++;//d1.operator++()
//	//++d1;//d1.operator++(int)
//
//	//-=
//	//Date d2(2025, 7, 12);
//	//d2 -= 50;
//	//d2.Print();
//
//	//Date d1(2025, 7, 12);
//	////Date d2(d1 + 100);
//	//Date d2 = d1 + 100;
//	//d2.Print();
//
//
//	//+= -
//	//Date d2(2025, 7, 12);
//	//d2 += -100;
//	//d2.Print();
//
//	//-= -
//	//Date d3(2025, 7, 13);
//	//d3 -= -100;
//	//d3.Print();
//
//
//	//前置++
//	//Date d3(2025, 7, 13);
//	//++d3;
//	//d3.Print();
//
//
//	////后置++
//	//Date d4(2025, 7, 13);
//	//d4++;
//	//d4.Print();
//
//
//	//前置--
//	//前置拷贝次数少
//	//Date d3(2025, 7, 13);
//	//--d3;//d3.operator--(&d3);
//	//d3.Print();
//
//
//	//后置--
//	//Date d4(2025, 7, 13);
//	//d4--;//d4.operator--(&d4, 0);
//	//d4.Print();
//
//
//	//循环n次使用n--
//	//循环n-1次使用--n
//
//
//	//Date d1(2025, 7, 13);
//	//Date d2(1930, 10, 1);
//	//cout << d1 - d2 << endl;
//	//cout << d2 - d1 << endl;
//
//
//	//流插入不能写成成员函数
//	//Date d1(2025, 7, 13);
//	//Date d2(2025, 7, 14);
//	//Date d3(2025, 7, 15);
//	////d1 += 100;
//	//d1.operator+=(100);
//	////cout << d1;//d1.operator(cout);d1流向cout
//	////d1 << cout;//d1.operator(cout);cout流向d1
//	////cout << d1;//友元函数和全局变量可以使用,单个赋值
//	//cout << d1 << d2 << d3;//可以使用引用返回,连续赋值
//
//
//	//流提取
//	//printf和scanf只能支持内置类型
//	//流可以支持内置类型和自定义类型
//	//Date d1(2025, 7, 13);
//	//Date d2(2025, 7, 14);
//	//cin >> d1 >> d2;
//	//cout << d1 << d2 << endl;
//
//
//	//const
//	//成员函数后面加const以后,普通函数和const对象都可以调用
//	//不是所有函数都要加const,要修改成员变量的函数不能加const
//	//只要成员内部函数不修改成员变量,都应该加const
//	//这样const对象和普通对象都可以调用
//	Date d1(2025, 7, 13);
//	d1.Print();//d1.Print(&d1);//Date*->Date* --- 权限的平移
//	const Date d2(2025, 7, 14);
//	d2.Print();//d2.Print(&d2);//const Date*->Date*  --- 权限的放大
//
//	//bool operator<(const Date& x);
//	//d1 < d2;//d1传this指针,Date* -> Date*
//	//d2 < d1;//d2不能传this指针,const Date* -> Date* --- 权限的放大
//}
//int main()
//{
//	TestDate();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	//Date*和const Date*构成函数重载
//	Date* operator&()
//	{
//		cout << "Date* operator&()" << endl;
//		return this;
//	}
//	const Date* operator&() const
//	{
//		cout << "const Date* operator&() const" << endl;
//		return this;
//	}
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//int main()
//{
//	//const int a = 10;
//	//int b = a;//拷贝,两个是独立的空间,不涉及权限放大
//
//	//const int a = 1;
//	//int& b = a;//b是a的别名,b的改变会影响a,涉及权限的放大
//
//	//const int a = 1;
//	//int* pb = &a;//权限的放大
//
//	Date d1;
//	const Date d2;//const对象必须初始化
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	return 0;
//}


//初始化列表
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//private:
//	int _a;
//};
//class B
//{
//public:
//	//初始化列表,对象成员定义的位置
//	//初始化列表不能出现相同的成员
//	B(int a, int& ref)//这里传的参数可以不使用
//		: _ref(ref)
//		, _n(1)
//		, _x(2)//如果初始化列表有值,则不需要缺省值
//		,_aobj(10)//为默认构造函数传参,如果默认构造函数有缺省值可以不传参,没有缺省值必须传参
//		//, _n(10)
//	{}
//private:
//	//声明
//	A _aobj;		//没有默认构造函数(编译器生成的,全缺省的,无参的)
//	//引用和const必须在定义时初始化
//	int& _ref;		//引用
//	const int _n;	//const
//	int _x = 1;     //这里1是缺省值,不是初始化
//};	
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = (int*)malloc(sizeof(int) * 4);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_top = 0;
//		_capacity = 4;
//	}
//	Stack(int capacity)
//	{
//		cout << "Stack(int capacity)" << endl;
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//class MyQueue
//{
//public:
//	MyQueue()
//	{}
//	MyQueue(int capacity)
//		:_pushst(capacity)
//		, _popst(capacity)
//	{}
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//int main()
//{
//	//对象整体定义
//	int n = 10;
//	B bb(10, n);
//	MyQueue q1;
//	MyQueue q2(100);
//	return 0;
//}


//尽量使用初始化列表初始化,因为不管你是否使用初始化列表,
//对于自定义类型成员变量,一定会先使用初始化列表初始化
//#include<iostream>
//using namespace std;
//class Stack
//{
//public:
//	Stack(int capacity = 10)
//		: _top(0)
//		, _capacity(capacity)
//		, _a((int*)malloc(sizeof(int) * capacity))
//	{
//		if (nullptr == _a)
//		{
//			perror("malloc fail");
//			return;
//		}
//		//要求数组初始化一下
//		memset(_a, 0, sizeof(int) * capacity);
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//class AA
//{
//public:
//	AA(int row = 10, int col = 5)
//		: _row(10)
//		, _col(5)
//	{
//		//指针数组
//		_aa = (int**)malloc(sizeof(int*) * row);
//		int i = 0;
//		for (i = 0; i < row; i++)
//		{
//			_aa[i] = (int*)malloc(sizeof(int) * col);
//		}
//	}
//private:
//	int** _aa;
//	int _row;
//	int _col;
//};
//int main()
//{
//	Stack st;
//	return 0;
//}


//成员变量在类中声明次序就是其在初始化列表中的初始化顺序,与其在初始化列表中的先后次序无关
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//		: _a1(a)
//		, _a2(_a1)
//	{}
//	void Print() 
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() 
//{
//	A aa(1);
//	aa.Print();
//	return 0;
//}


//explicit --- 禁止使用隐式类型转换,添加在构造函数的前面
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A aa1(1);//调用构造函数
//	A aa2 = 2;//隐式类型转换,整型转换成自定义类型
//	//使用2调用构造函数构造1个A的临时对象,临时对象再拷贝构造
//	
//	//A& aa3 = 2;
//	const A& aa3 = 2;
//
//	//类型转换会产生临时变量,临时变量具有常性
//	int i = 10;
//	double d = i;
//	//临时变量是double类型,不能使用引用
//	return 0;
//}


//#include<iostream>
//#include<string>
////#include<list>
//using namespace std;
////string类用来管理字符串
////class string
////{
////public:
////	string(const char* str)
////	{}
////private:
////};
//class list
//{
//public:
//	void push_back(const string& str)
//	{}
//};
//int main()
//{
//	string name1("张三");//构造
//	string name2 = "张三";//构造+拷贝构造+优化
//	list lt1;
//	
//	//方法1
//	string name3("李四");
//	lt1.push_back(name3);
//	
//	//方法2
//	lt1.push_back("李四");//隐式类型转换
//	return 0;
//}


//static
//全局变量的劣势是任何地方都可以随意改变
//当前还有多少个A对象正在使用
//#include<iostream>
//using namespace std;
//int _scount = 0;
//class A
//{
//public:
//	A() 
//	{ 
//		++_scount; 
//	}
//	A(const A& t) 
//	{ 
//		++_scount; 
//	}
//	~A() 
//	{ 
//		--_scount; 
//	}
//	//static int GetACount() 
//	//{ 
//	//	return _scount; 
//	//}
//private:
//	//static int _scount;
//};
////void TestA()
////{
////	cout << A::GetACount() << endl;
////	A a1, a2;
////	A a3(a1);
////	cout << A::GetACount() << endl;
////}
//A aa0;
//A Func(A aa)
//{
//	//自定义类型实参传给形参要调用拷贝构造
//	cout << __LINE__ << ":" << _scount << endl;//aa0,aa1,aa2,实参传给形参的临时拷贝:4个
//	return aa;
//}
//int main()
//{
//	//__LINE__---文件的哪一行
//	//全局函数在main函数之前调用构造
//	cout << __LINE__ << ":" << _scount << endl;//aa0:1个
//	//静态的局部的对象不会在main函数之前初始化
//	A aa1;
//	static A aa2;
//	Func(aa1);
//	cout << __LINE__ << ":" << _scount << endl;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int _scount = 0;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	//static int GetACount() 
//	//{ 
//	//	return _scount; 
//	//}
//private:
//	//static int _scount;
//};
////void TestA()
////{
////	cout << A::GetACount() << endl;
////	A a1, a2;
////	A a3(a1);
////	cout << A::GetACount() << endl;
////}
//A aa0;
//void Func()
//{
//	static A aa2;
//	cout << __LINE__ << ":" << _scount << endl;
//}
//int main()
//{
//	//__LINE__---文件的哪一行
//	//全局函数在main函数之前调用构造
//	cout << __LINE__ << ":" << _scount << endl;//aa0:1个
//	//静态的局部的对象不会在main函数之前初始化
//	A aa1;
//	Func();
//	Func();
//	return 0;
//}


//成员变量属于每一个类对象,存储在对象里面
//静态成员变量属于类,属于类的每个对象共享,存储在静态区,生命周期是全局的
//静态成员函数没有this指针,指定类域和访问限定符就可以访问,静态成员函数和静态成员变量一般是一起出现的
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	void Func1()
//	{
//		//非静态可以调用静态
//		GetACount();
//	}
//	void Func2()
//	{
//	}
//	static int GetACount()
//	{
//		//静态不可以调用非静态
//		//非静态的成员函数需要调用this指针
//		//Func2();
//		//_a1++;
//		return _scount;
//	}
//private:
//	//成员变量
//	int _a1 = 1;
//	int _a2 = 1;
//
//	//静态成员函数
//	//静态成员变量不能在声明时初始化,静态成员变量没有初始化列表
//	//成员变量可以在声明时初始化,有初始化列表初始化
//	static int _scount;//声明
//};
//int A::_scount = 0;
//A aa0;
//void Func()
//{
//	static A aa2;
//	cout << __LINE__ << ":" << aa2._scount << endl;
//}
//int main()
//{
//	//__LINE__---文件的哪一行
//	//全局函数在main函数之前调用构造
//	cout << __LINE__ << ":" << _scount << endl;//aa0:1个
//	//静态的局部的对象不会在main函数之前初始化
//	A aa1;
//	Func();
//	Func();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class MyClass 
//{
//public:
//    void Func()
//    {
//        Mcount();
//    }
//    static int Mcount()
//    {
//        Func();
//    }
//private:
//    static int count; //声明静态成员变量
//};
////类外初始化,初始值设为0
//int MyClass::count = 0;
//int main() 
//{
//    //方式一:通过类名访问
//    MyClass::count = 10;
//
//    //方式二:通过对象访问
//    MyClass obj1, obj2;
//    obj1.count = 20;  //实际上修改的是同一个count
//    cout << obj2.count << endl;  //输出20
//}



//#include<iostream>
//using namespace std;
//class MyClass 
//{
//public:
//    void Func()
//    {
//        count++;
//        Mcount();
//    }
//    static int Mcount()
//    {
//        count++;
//        //Func();
//        return count;
//    }
//private:
//    static int count; 
//};
//int MyClass::count = 0;
//int main() 
//{
//    MyClass a1;
//    a1.Func();
//    cout << a1.Mcount() << endl;
//    return 0;
//}


//设计1个类,只能在栈上创建对象
//设计1个类,只能在堆上创建对象
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	static A GetStackObj()
//	{
//		A aa;
//		return aa;
//	}
//	static A* GetHeapObj()
//	{
//		return new A;
//	}
//private:
//	A()
//	{}
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//int main()
//{
//	//都调用构造函数
//	//static A aa1;   //静态区
//	//A aa2;          //栈
//	//A* ptr = new A; //堆
//	A::GetStackObj();
//	A::GetHeapObj();
//	return 0;
//}


//友元类
//#include<iostream>
//using namespace std;
//class Time
//{
//	friend class Date; //声明日期类为时间类的友元类,则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		//直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class MyFriend
//{
//public:
//    friend void friendFunc(MyFriend obj); // 声明友元函数
//private:
//    int a = 0;
//    int b = 0;
//};
////友元函数的定义(不需要friend关键字)
//void friendFunc(MyFriend obj)
//{
//    obj.a = 10;   //可以访问私有成员
//    cout << obj.a << endl;
//}
//int main()
//{
//    MyFriend a1;
//    friendFunc(a1);
//    return 0;
//}


//普通友元函数
//#include<iostream>
//using namespace std;
//class Point 
//{
//private:
//    int x, y;
//public:
//    Point(int a = 1, int b = 2) 
//        : x(a)
//        , y(b) 
//    {}
//    friend int distance(Point p1, Point p2); //普通友元函数
//};
////计算两点之间的距离
//int distance(Point p1, Point p2) 
//{
//    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//}
//int main()
//{
//    Point p1(1, 2);
//    Point p2(2, 3);
//    int ret = distance(p1, p2);
//    cout << ret << endl;
//    return 0;
//}


//类的友元函数
//#include<iostream>
//using namespace std;
//class A;
//class B
//{
//public:
//    void func(A a);
//};
//class A 
//{
//public:
//    friend void B::func(A a); //声明B的成员函数为友元
//private:
//    int data = 0;
//};
//
//void B::func(A a)
//{
//    a.data = 100;
//    cout << a.data << endl;
//}
//int main()
//{
//    A a;
//    B b;
//    b.func(a);
//    return 0;
//}


//友元类
//#include<iostream>
//using namespace std;
//class A 
//{
//private:
//    int data = 0;
//public:
//    friend class B; //声明B为友元类
//};
//
//class B 
//{
//public:
//    void setData(A& a, int value) 
//    {
//        a.data = value; //可以访问A的私有成员
//        cout << a.data << endl;
//    }
//};
//int main()
//{
//    int value = 10;
//    A a;
//    B b;
//    b.setData(a, value);
//    return 0;
//}


//内部类
//公有和私有
//内部类是外部类的友元
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	//B在A中不占空间,对象占空间
//	class B //B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;
//			cout << a.h << endl;
//		}
//	private:
//		int b;
//	};
//private:
//	static int k;
//	int h;
//};
//int A::k = 1;
//int main()
//{
//	cout << sizeof(A) << endl;
//	A::B b;
//	b.foo(A());
//	return 0;
//}


//匿名对象
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution
//{
////public:
////	Solution(int x)
////	{}
//public:
//	int Sum_Solution(int n)
//	{
//		cout << "int Sum_Solution(int n)" << endl;
//		//...
//		return n;
//	}
//};
//int main()
//{
//	//A aa;
//	//A aa(1);//有名对象  --- 生命周期在当前函数的局部域
//	//A(1);//匿名对象  --- 生命周期在当前行,到下一行会销毁。即使用完成后就销毁
//	
//	//不能这样定义对象,因为编译器无法识别下面是一个函数声明,还是对象定义
//	//Solution sl();
//	//sl.Sum_Solution(2);
//
//	Solution().Sum_Solution(3);//括号代表构造函数没有参数
//	//Solution.Sum_Solution(3);//静态成员可以这样调用,因为没有this指针
//
//	//A& ra = A(1);//匿名对象具有常性
//	//const A& ra = A(1);//会变成野引用,const引用延长了匿名对象的生命周期,生命周期在当前函数的局部域
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//void push_back(const string& s)
//{
//	cout << "void push_back()" << s << endl;
//}
//int main()
//{
//	string str("111111");
//	push_back(str);
//	
//	//匿名对象
//	//这两行意义相同
//	push_back(string("22222"));
//	push_back("33333");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class MyClass 
//{
//public:
//    MyClass()
//    {
//        cout << "MyClass()" << endl;
//    }
//    MyClass(int num) 
//    {
//        cout << "MyClass(int num):" << num << endl;
//    }
//    void Func(int n)
//    {
//        cout << n << endl;
//    }
//};
//int main()
//{
//    MyClass my;//有名对象
//    my.Func(1);
//
//    //创建无参匿名对象
//    MyClass();
//    //创建带参匿名对象
//    MyClass(10);
//
//    MyClass().Func(1);
//    return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void Func1(A aa)
//{
//
//}
//void Func2(const A& aa)//一旦加了const类型就不一样了
//{
//
//}
//A Func3()
//{
//	A aa;
//	return aa;
//}
//A& Func4()
//{
//	static A aa;
//	return aa;
//}
//A Func5()
//{
//	A aa;//构造局部对象aa
//	return aa;//拷贝aa到返回值临时对象(第一次拷贝)
//}
//int main()
//{
//	//A a1;
//	////传参会调用拷贝构造
//	////不拷贝构造可以加引用,减少拷贝
//	////Func1和Func2构成函数重载,但是调用不明确
//	//Func1(a1);
//	//Func2(a1);
//
//	//Func3();
//
//	//Func4();
//
//	//两行,对象已经构造出来了,不会优化
//	//A aa1;
//	//Func1(aa1);
//
//	//建议这样写
//	//Func1(A(1));//构造+拷贝构造 -->构造
//    //Func1(1);//构造+拷贝构造 -->构造
//	//A aa2 = 1;//构造+拷贝构造 -->构造
//
//	//A ra1 = Func5();//拷贝构造+拷贝构造 --> 优化为拷贝构造
//	//cout << "==" << endl;
//	//A ra2;
//	//ra2 = Func5();//不会优化,赋值
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//A Func5()
//{
//	//从局部对象到返回值临时对象
//	A aa;//构造局部对象aa
//	return aa;//拷贝aa到返回值临时对象(第一次拷贝)
//	//第二次拷贝:从返回值临时对象到ret
//
//}
//int main()
//{
//	A ret = Func5();//返回的是aa的临时对象,拷贝返回值临时对象到ret(第二次拷贝)
//	const A& ret = Func5();//返回的是aa的临时对象
//	return 0;
//}


//类是对某一类实体(对象)来进行描述的,描述该对象具有那些属性,
//那些方法,描述完成后就形成了一种新的自定义类型,才用该自定义类型就可以实例化具体的对象