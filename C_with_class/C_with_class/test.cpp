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
#include<iostream>
using namespace std;
//struct和class都可以使用访问限定符
//只要是类都可以使用访问限定符
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
private:
	int* a;
	int top;
	int capacity;
};
//C++兼容C语言,struct以前的用法都可以继续使用
//同时struct升级成了类
int main()
{
	struct Stack st1;
	st1.Init(20);
	Stack st2;
	st2.Init();
	st2.Push(1);
	st2.Push(2);
	st2.Push(3);
	st2.Push(4);
	st2.Destory();
	return 0;
}


//#include<iostream>
//using namespace std;
//int main()
//{
//
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