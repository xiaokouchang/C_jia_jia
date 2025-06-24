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
//
//int main()
//{
//	int a = 10;
//	printf("%d\n", a);
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


//#include"Queue.h"
//#include"Stack.h"
//#include<stdio.h>
//using namespace std;
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
//using namespace std;//std包含在iostream中
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