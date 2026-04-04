//异常
//try catch throw发生异常
//catch跳异常不会执行
//#include<iostream>
//#include<string>
//using namespace std;
////全局是非常危险的
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		//throw "Division by zero condition!";//throw发生异常
//		//throw 1;//没有意义,执行第1个throw直接跳转到catch,第2个throw不会执行
//		string s("Division by zero condition!");//string执行完成后会析构
//		throw s;
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//void Func()
//{
//	//try 
//	//{
//	//	int len, time;
//	//	cin >> len >> time;
//	//	cout << Division(len, time) << endl;
//	//}
//	//catch (const string& errmsg)//成功捕获异常后代码继续执行
//	//{
//	//	cout << errmsg << endl;
//	//	cout << "yyy" << endl;
//	//}
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//int main()
//{
//	//异常通常在循环里面,进行监控
//	//捕获异常后一般会记录进日志里面
//	try 
//	{
//		//可能是Func也可能是Func的里面
//		Func();
//	}
//	catch (int errmsg)//发生异常会进入catch,类型不匹配无法捕获
//	{
//		cout << errmsg << endl;
//	}
//	catch (const char* errmsg)//成功捕获异常后代码继续执行
//	{
//		cout << errmsg << endl;
//		cout << "xxx" << endl;
//	}
//	catch (...)//捕获任意类型的异常,不知道异常错误是什么,未知异常会放在最后,放在前面代码会报错,前面没有按规范写
//	{
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}


//异常至少要包含2种信息,错误的编号和错误描述
//可以抛出派生类对象使用基类捕获
//#include<iostream>
//#include<string>
//using namespace std;
////服务器开发中通常使用的异常继承体系
//class Exception
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg)
//		, _id(id)
//	{
//	}
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//protected:
//	string _errmsg;
//	int _id;
//};
//int main()
//{
//	int n = 0;
//	while (n--)
//	{
//		try
//		{
//			SeedMsg(msg);
//			break;
//		}
//		catch (const Exception& e)
//		{
//			if (e.getid() == 3)
//			{
//				continue;
//			}
//			else
//			{
//				//记录日志
//				break;
//			}
//		}
//	}
//	return 0;
//}


// 服务器开发中通常使用的异常继承体系
//#include<iostream>
//#include<Windows.h>
//using namespace std;
//class Exception
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg)
//		, _id(id)
//	{
//	}
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//protected:
//	string _errmsg;
//	int _id;
//};
//class SqlException : public Exception
//{
//public:
//	SqlException(const string& errmsg, int id, const string& sql)
//		:Exception(errmsg, id)
//		, _sql(sql)
//	{
//	}
//	virtual string what() const
//	{
//		string str = "SqlException:";
//		str += _errmsg;
//		str += "->";
//		str += _sql;
//		return str;
//	}
//private:
//	const string _sql;
//};
//class CacheException : public Exception
//{
//public:
//	CacheException(const string& errmsg, int id)
//		:Exception(errmsg, id)
//	{
//	}
//	virtual string what() const
//	{
//		string str = "CacheException:";
//		str += _errmsg;
//		return str;
//	}
//};
//class HttpServerException : public Exception
//{
//public:
//	HttpServerException(const string& errmsg, int id, const string& type)
//		:Exception(errmsg, id)
//		, _type(type)
//	{
//	}
//	virtual string what() const
//	{
//		string str = "HttpServerException:";
//		str += _type;
//		str += ":";
//		str += _errmsg;
//		return str;
//	}
//private:
//	const string _type;
//};
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("权限不足", 100, "select * from name = '张三'");
//	}
//	//throw "xxxxxx";
//	cout << "执行成功" << endl;
//}
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("权限不足", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("数据不存在", 101);
//	}
//	SQLMgr();
//}
//void HttpServer()
//{
//	// ...
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw HttpServerException("请求资源不存在", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("权限不足", 101, "post");
//	}
//	CacheMgr();
//}
//int main()
//{
//	while (1)
//	{
//		Sleep(500);
//		//this_thread::sleep_for(chrono::seconds(1));
//		try 
//		{
//			HttpServer();
//		}
//		catch (const Exception& e) // 这里捕获父类对象就可以,这是父类的引用,抛出派生类对象
//		{
//			//多态,异常是多态的应用
//			cout << e.what() << endl;//what指向谁调用谁
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}


//C++标准库继承在exception中
//#include<exception>
//bad_alloc
//out_of_range
//new抛异常
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}


//异常规范
//没有强制
//throw()表示不抛异常
//这里表示这个函数会抛出A/B/C/D中的某种类型的异常
//void fun() throw(A,B,C,D);

//这里表示这个函数只会抛出bad_alloc的异常
//void* operator new (std::size_t size) throw (std::bad_alloc);

//这里表示这个函数不会抛出异常
//void* operator delete (std::size_t size, void* ptr) throw();

//C++11中新增的noexcept,表示不会抛异常
//thread() noexcept;
//thread(thread&& x) noexcept;


//new和delete之间慎用异常防止发生内存泄漏
//智能指针
//int main()
//{
//	int* p1 = new int;
//	int* p2 = new int;
//	func();
//	//new和func抛异常不好处理
//	delete p1;
//	delete p2;
//	return 0;
//}