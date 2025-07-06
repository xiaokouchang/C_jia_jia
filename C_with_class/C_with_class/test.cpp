#define _CRT_SECURE_NO_WARNINGS 1 
//C语言是面向过程的,关注的是过程,分析出求解问题的步骤,通过函数调用逐步解决问题
//C++是基于面向对象的,关注的是对象,将一件事情拆分成不同的对象,靠对象之间的交互完成
//面向对象关注对象和对象之间的关系和交互

#include<iostream>
using namespace std;
class Stack
{
public:
	//成员函数
	void Init(int defaultcapacity = 4)
	{
		a = (int*)malloc(sizeof(int) * capacity);
		if (nullptr == a)
		{
			perror("malloc申请空间失败");
			return;
		}
		capacity = defaultcapacity;
		top = 0;
	}
	void Push(int x)
	{
		a[top++] = x;
	}
	void Destory()
	{
		free(a);
		a = nullptr;
		top = capacity;
	}
	//成员变量
	//可以写在成员函数之前或之后
	int* a;
	int top;
	int capacity;
};
int main()
{
	Stack st1;
	st1.Init();
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	st1.Destory();
	return 0;
}


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
//	//st1.Init();
//	//st1.top = 0;
//	//st1.Push(1);
//	//st2.top = 1;
//	//st2.Push(1);
//	//对象中只存储成员变量,没有存储成员函数
//	cout << sizeof(Stack) << endl;
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
//	aa1._a = 1;
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
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
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


//#include<iostream>
//using namespace std;
//int main()
//{
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