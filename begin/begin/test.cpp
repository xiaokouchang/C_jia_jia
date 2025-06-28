#define _CRT_SECURE_NO_WARNINGS 1 
//解决C语言的不足
//namespace --- 命名空间
//#include <stdio.h>
//#include <stdlib.h>
//int rand = 0;//rand重定义和库里面的函数冲突
//
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int a = 20;
//int main()
//{
//	int a = 10;
//	printf("%d\n", a);
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int a = 20;
//namespace N1
//{
//	int a = 30;
//}
//int main()
//{
//	int a = 10;
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	printf("%d\n", N1::a);
//	return 0;
//}



//局部域
//全局域
//#include <stdio.h>
//#include <stdlib.h>
//int a = 20;
//
//int main()
//{
//	int a = 10;
//	printf("%d\n", a);
//	//::域作用限定
//	printf("%d\n", ::a);
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
////局部域>全局域
//int a = 0;//全局域
//namespace space
//{
//	//命名空间域
//	int a = 1;//rand重定义和库里面的函数冲突
//}
////展开了命名空间域(相当于暴露到全局,不能和全局变量同时存在)
//using namespace space;
////指定命名空间域
//int main()
//{
//	//局部域
//	int a = 2;
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	printf("%d\n", space::a);
//	return 0;
//}


//如果变量名和库里面函数名相同,可以使用命名空间,只能使用指定命名空间域,如果使用展开命名空间域,代码会报错
//#include <stdio.h>
//#include <stdlib.h>
//namespace space
//{
//	//命名空间域
//	int rand = 1;
//}
////展开了命名空间域(相当于暴露到全局,不能和全局变量同时存在)
////using namespace space;
////指定命名空间域
//int main()
//{
//	//局部域
//	printf("%p\n", rand);//和头文件不同,要注意展开
//	printf("%d\n", space::rand);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//int main()
//{
//	printf("%d\n", N1::a);
//	printf("%d\n", N1::Add(1, 2));
//	return 0;
//}


//#include<stdio.h>
//int x = 30;
//namespace N1
//{
//	int x = 20;
//}
//using namespace N1;
//int main()
//{
//	int x = 10;
//	printf("%d\n", x);
//	return 0;
//}


//#include<stdio.h>
//namespace N1
//{
//	int x = 10;
//	int y = 20;
//}
//using N1::x;
//int main()
//{
//	printf("%d\n", x);
//	printf("%d\n", y);
//	return 0;
//}


//#include"Queue.h"
//#include"Stack.h"
//
//int main()
//{
//	printf("%d\n", N1::x);//命名空间发生合并,如果同一个命名空间有同一个变量会报错,可以嵌套来解决
//	printf("%d\n", N1::y);
//	return 0;
//}


//#include <iostream.h>//很老的编译器有.h
//#include <iostream>
////直接展开会有风险,我们定义如果跟库重名,就报错了
////建立项目里不要展开,日常练习可以
////项目里建议指定访问,不要轻易展开命名空间
//
////全部展开
////using namespace std;//std包含在iostream中
////把常用的展开---指定展开
//using std::cout;
//using std::endl;
//
//int main()
//{
//	//std::cout << "hello world" << std::endl;
//	//展开后可以加也可以不加
//	cout << "hello world" << endl;
//	return 0;
//}


//printf比C++的IO输入输出快
//#include<iostream>
//using namespace std;
//int main()
//{
//	int x = 10;
//	double d = 11.11;
//	//<< 流插入运算符
//	//endl等价于'\n'
//	//cout可以自动识别类型
//	//>> 流提取运算符
//	cin >> d;
//	cout << "hello world" << d << '\n' << endl;
//	//保留小数位数,用printf
//	return 0;
//}


//缺省参数
//没有传参时,使用参数的默认值
//传参时,使用指定的实参
//#include <iostream>
//using namespace std;
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func();   //没有传参时,使用参数的默认值
//	Func(10); //传参时,使用指定的实参
//	return 0;
//}


//全缺省参数
//#include <iostream>
//using namespace std;
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func();
//	Func(1);
//	Func(1, 2);
//	Func(1, 2, 3);
//	return 0;
//}


//半缺省 --- 从右往左缺省
//1.半缺省参数必须从右往左依次来给出,不能间隔着给
//2.缺省参数不能在函数声明和定义中同时出现
//#include <iostream>
//using namespace std;
//void Func(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	//Func();//如果函数有一个参数没给值,这里必须传至少一个值
//	Func(1);
//	Func(1, 2);
//	Func(1, 2, 3);
//	return 0;
//}


//#include<iostream>
//using namespace std;
////#define DEFAULT_CAPACITY 4
//struct stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//void StackInit(struct stack* pst, int defaultCapacity = 4)
//{
//	pst->a = (int*)malloc(sizeof(int) * defaultCapacity);
//	if (pst->a == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	pst->top = 0;
//	pst->capacity = 4;
//}
//
//int main()
//{
//	//插入100个数据,减少扩容的消耗
//	//struct stack st;
//	//StackInit(&st, 100);
//	//不知道要插入多少数据,可以使用缺省参数
//	struct stack st;
//	StackInit(&st);
//	return 0;
//}


//缺省值必须是常量或者全局变量
//C语言不支持(编译器不支持)
//不允许函数定义和声明同时都有缺省参数,防止缺省参数的值不一致
//允许函数声明给,函数定义不给参数
//#include "Stack.h"
//int main()
//{
//	struct stack st;
//	StackInit(&st);
//	return 0;
//}


//函数重载
//函数的一种特殊情况,C++允许在同一作用域中声明几个功能类似的同名函数,
//这些同名函数的形参列表(参数个数或类型或类型顺序)不同,
//常用来处理实现功能类似数据类型不同的问题
//对返回值没有要求
//C语言不允许同名函数
//C++允许同名函数
//参数类型不同,名字相同类型的顺序不同会构成重载,如果函数参数相同会报错
//#include<iostream>
//using namespace std;
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//int main()
//{
//	//自动匹配类型
//	cout << Add(2, 3) << endl;
//	cout << Add(2.1, 3.1) << endl;
//	return 0;
//}


//类型相同,名字不同,不构成重载
//#include<iostream>
//using namespace std;
//void f(int a, char b)
//{
//	cout << "f(int a, char b)" << endl;
//}
//void f(int b, char a)
//{
//	cout << "f(int b, char a)" << endl;
//}
//int main()
//{
//	f(1, 'x');
//	return 0;
//}


//构成重载,类型相同,顺序不同
//#include<iostream>
//using namespace std;
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//void f(int a, char b)
//{
//	cout << "f(int a, char b)" << endl;
//}
//void f(char a, int b)
//{
//	cout << "f(char b, int a)" << endl;
//}
//int main()
//{
//	f(1);
//	f(1, 'x');
//	f('x', 1);
//	return 0;
//}


//参数个数不同
//#include<iostream>
//using namespace std;
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	f();
//	f(10);
//	return 0;
//}


//构成重载
//不明确的调用
//#include<iostream>
//using namespace std;
//void f()
//{
//	cout << "f()" << endl;
//}
////缺省函数调用时可以不传参,与第1个f()函数重复
////如果函数调用传参会调用void f(int a = 0)这个函数
//void f(int a = 0)
//{
//	cout << "f(int a = 0)" << endl;
//}
//int main()
//{
//	//f();
//	f(1);
//	return 0;
//}


//为什么C语言不支持重载?
//C++支持重载
//函数名修饰规则
//编译链接过程
//自动识别类型就是函数重载
//编译链接
//第1步:预处理(头文件展开/宏替换/条件编译/去掉注释),处理完成之后,没有.h文件
//生成两个文件Stack.i和test.s
//第2步:编译:检查语法,生成汇编代码(指令集的代码)
//第3步:汇编:生成.o文件,call是调用函数
//第4步:链接:生成可执行程序xxx.exe/a.out
//CPU看不懂汇编代码,机器只识别二进制,将汇编转换成二进制的机器码
//#include <stdio.h>
//#include <stdlib.h>
//#include "Stack.h"
//int main()
//{
//	struct Stack st;
//	StackInit(&st);//call StackInit(地址),编译阶段有这个地址吗,没有,地址在符号表里
//	StackPush(&st, 1);
//	StackPush(&st, 1.1);
//	return 0;
//}


//编译:承诺
//链接:兑现承诺
//#include <iostream>
//using namespace std;
//int Func()
//{
//	return 1;
//}
//double Func()
//{
//	return 1.1;
//}
//int main()
//{
//	Func();//调用歧义
//	return 0;
//}


//引用
//给已存在的变量取别名
//引用在定义时必须初始化
//一个变量可以有多个引用
//引用一旦引用一个实体,再不能引用其他实体
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//	int& d = a;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	b++;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << d << endl;
//	d++;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << d << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	int& d = a;
//	int x = 11;
//	//d变成x的引用还是别名
//	d = x;//赋值
//	return 0;
//}


//做参数(输出型参数)
//#include<iostream>
//using namespace std;
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int x = 0;
//	int y = 1;
//	Swap(&x, &y);
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//void Swap(int*& a, int*& b)
//{
//	int* tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int x = 0;
//	int y = 1;
//	int* px = &x;
//	int* py = &y;
//	cout << *px << " " << *py << endl;
//	Swap(px, py);
//	cout << *px << " " << *py << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//typedef struct ListNode
//{
//	struct ListNode* next;
//	int val;
//}LTNode, *PLTNode;
////LTNode == struct ListNode;
////PLTNode == struct ListNode*;
//void ListPushBack(PLTNode& phead, int x)
//{
//
//}
//int main()
//{
//	PLTNode plist = NULL;
//	ListPushBack(plist, 1);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 1;
//	int& b = a;
//	int& c = b;
//	int& d = c;
//	int x = 10;
//	d = x;//改变了a的值
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << d << endl;
//	cout << x << endl;
//	d++;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << d << endl;
//	cout << x << endl;
//	return 0;
//}


//引用做参数可以提高效率(大对象/深拷贝类对象)
//#include <time.h>
//#include<iostream>
//using namespace std;
////C++里结构体可以用A或者struct A
//struct A 
//{ 
//	int a[10000]; 
//};
//void TestFunc1(A a) 
//{}
//void TestFunc2(A& a) 
//{}
//void TestRefAndValue()
//{
//	A a;
//	//以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//	{
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//	//以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//	{
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//	//分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}


//引用做返回值
//#include<iostream>
//using namespace std;
//int Count()
//{
//	static int n = 0;
//	n++;
//	return n;//一定会产生了临时变量,关注的是类型
//}
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//	return 0;
//}


//传引用返回
//必须是静态变量
//减少拷贝,提高效率
//修改返回值
//返回的是n的别名,即n的引用
//#include<iostream>
//using namespace std;
//int& Count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//	return 0;
//}


//函数结束后空间销毁
//#include<iostream>
//using namespace std;
////Count函数结束,函数栈帧销毁,没有清理栈帧,ret的结果是正确的
////如果清理栈帧,返回的是随机值
//int& Count()
//{
//	int n = 0;
//	n++;
//	return n;
//}
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//	return 0;
//}


//引用返回
//基本任何场景用引用传参
//谨慎使用引用作为返回值,出了函数作用域,对象不在了,就不能使用引用返回,
//否则还在就可以用引用返回
//局部变量谨慎用引用返回,静态变量,全局变量,动态内存分配可以用引用返回
//#include<iostream>
//using namespace std;
////Count函数结束,函数栈帧销毁,没有清理栈帧,ret的结果是正确的
////如果清理栈帧,返回的是随机值
//int& Count(int x)
//{
//	int n = 0;
//	//cout << "n:" << &n << endl;
//	n++;
//	return n;
//}
//int main()
//{
//	int& ret = Count(10);//ret是n的别名,连续取别名
//	//cout << "ret:" << &ret << endl;
//	cout << ret << endl;//随机值
//	//Count(20);
//	printf("sssss\n");
//	cout << ret << endl;//随机值
//	return 0;
//}


//#include <assert.h>
//#include <iostream>
//using namespace std;
//typedef struct SeqList
//{
//	int a[100];
//	int size;
//}SeqList;
//int SLGet(SeqList* ps, int pos)
//{
//	assert(pos < 100 && (pos >= 0));
//	return ps->a[pos];
//}
//void SLModify(SeqList* ps, int pos, int x)
//{
//	assert(pos < 100 && (pos >= 0));
//	assert(ps);
//	ps->a[pos] = x;
//}
//int& SLAt(SeqList* ps, int pos)
//{
//	assert(pos < 100 && pos >= 0);
//	return ps->a[pos];
//}
//int& SLAt(SeqList& ps, int pos)
//{
//	assert(pos < 100 && pos >= 0);
//	return ps.a[pos];
//}
//int main()
//{
//	SeqList s;
//	SLModify(&s, 0, 1);
//	cout << SLGet(&s, 0) << endl;
//	//对第0个位置+5
//	int ret = SLGet(&s, 0);
//	SLModify(&s, 0, ret + 5);
//	//引用(读写)
//	SLAt(&s, 0) = 1;
//	cout << SLAt(&s, 0) << endl;
//	SLAt(&s, 0) += 5;
//
//	SLAt(s, 0) = 1;
//	cout << SLAt(s, 0) << endl;
//	SLAt(s, 0) += 5;
//	return 0;
//}


//#include <assert.h>
//#include <iostream>
//using namespace std;
//struct SeqList
//{
//	int a[100];
//	size_t size;
//	int& at(int pos)
//	{
//		assert(pos >= 0 && pos < 100);
//		return a[pos];
//	}
//	int& operator[](int pos)
//	{
//		assert(pos >= 0 && pos < 100);
//		return a[pos];
//	}
//};
//int main()
//{
//	SeqList s;
//	s.at(0) = 0;
//	s.at(0)++;
//	cout << s.at(0) << endl;
//	s[1] = 10;
//	s[1]++;
//	cout << s[1] << endl;
//	return 0;
//}


//#include <time.h>
//#include <iostream>
//using namespace std;
//struct A
//{ 
//	int a[10000]; 
//};
//A a;
////值返回
//A TestFunc1() 
//{ 
//	return a; 
//}
////引用返回
//A& TestFunc2() 
//{ 
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	//以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	//以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	//计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
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