#define _CRT_SECURE_NO_WARNINGS 1 

//一个通用的交换函数
//#include<iostream>
//using namespace std;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	return 0;
//}


//函数模板
//#include<iostream>
//using namespace std;
//template<typename T>//T是模板参数,定义的是类型
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 1;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//	cout << c << " " << d << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 1;
//	int b = 2;
//	cout << a << " " << b << endl;
//	swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}



//函数模板
//函数模版根据调用,自己推导出模版参数的类型,实例化出对应的函数
//#include<iostream>
//using namespace std;
////template<typename T>
//template<class T>
//void Swap(T& x, T& y)
//{
//	T& tmp = x;
//	x = y;
//	y = tmp;
//}
//template<class T1, class T2>
//T1 Func(const T1& x, const T2& y)
//{
//	cout << x << " " << y << endl;
//	return x;
//}
//int main()
//{
//	int a = 0;
//	int b = 1;
//	Swap(a, b);
//	Func(1, 2.2);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	//cout << Add(a1, a2) << endl;
//	//cout << Add(d1, d2) << endl;
//	
//	//强制类型转换
//	//cout << Add(a1, (int)d1) << endl;
//	//cout << Add((double)a1, d1) << endl;
//	
//	//显示类型转换
//	cout << Add<int>(a1, d2) << endl;
//	cout << Add<double>(a1, d2) << endl;
//	return 0;
//}


//有些函数无法自动推导,只能显示实例化
//#include<iostream>
//using namespace std;
//template<typename T>
//T* Alloc(int n)
//{
//	return new T[n];
//}
//int main()
//{
//	double* p1 = Alloc<double>(10);
//	return 0;
//}


//类模板
//#include<iostream>
//using namespace std;
//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "StackInt(size_t capacity = 3)" << endl;
//		_array = new T[capacity];//只需要个数
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const T& data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		cout << "~StackInt()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	T* _array;
//	int _capacity;
//	int _size;
//};
////惠普实验室   STL---标准模版库,常见的数据结构和算法的库 
//int main()
//{
//	Stack<int> s1;//int
//	Stack<double> s1;//double
//	return 0;
//}