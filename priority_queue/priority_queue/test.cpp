//#include<iostream>
//#include<queue>
//using namespace std;


//#include"priority_queue.h"
//using namespace prior;
//void test1()
//{
//	//priority_queue<int, deque<int>, greater<int>> pq;
//
//	//С��
//	priority_queue<int, vector<int>,Greater<int>> pq;
//	
//	//���
//	//priority_queue<int> pq;
//
//	pq.push(3);
//	pq.push(5);
//	pq.push(1);
//	pq.push(4);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//void test2()
//{
//	//priority_queue<Date> pq;//
//	priority_queue<Date,vector<Date>,greater<Date>> pq;
//	pq.push(Date(2025, 10, 2));
//	pq.push(Date(2025, 12, 2));
//	pq.push(Date(2025, 11, 2));
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//void test3()
//{
//	//priority_queue<Date*> pq;
//	priority_queue<Date*,vector<Date*>,LessPDate> pq;
//	pq.push(new Date(2025, 10, 2));
//	pq.push(new Date(2025, 12, 2));
//	pq.push(new Date(2025, 11, 2));
//	while (!pq.empty())
//	{
//		cout << *pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//int main()
//{
//	//test1(); //��������
//	test3();   //�Զ�������
//	//�º���/��������
//	//��Ķ���Ҳ��������һ��ʹ��
//	//Less<int> lessfunc;
//	//cout << lessfunc(1, 2) << endl;
//	//cout << lessfunc.operator()(1, 2) << endl;
//	return 0;
//}


#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> lt(4, 4);
	auto rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	return 0;
}


//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//struct Person 
//{
//    string name;
//    int age;
//};
//
////�Զ���Ƚ���:����������(С������)
//struct CompareAge 
//{
//    bool operator()(const Person& a, const Person& b) 
//    {
//        return a.age > b.age; // ע�⣺���ȶ���Ĭ���� <�������� > ʵ������
//    }
//};
//
//int main() 
//{
//    priority_queue<Person, vector<Person>, CompareAge> pq;
//    pq.push({ "Alice", 25 });
//    pq.push({ "Bob", 20 });
//    pq.push({ "Charlie", 30 });
//    while (!pq.empty()) 
//    {
//        cout << pq.top().name << "(" << pq.top().age << ")" << " ";
//        pq.pop();
//    }
//    return 0;
//}


//#include"priority_queue.h"
//using namespace prior;
//int main()
//{
//	//���
//	priority_queue<int, vector<int>, Less<int>> pq1;
//	pq1.push(3);
//	pq1.push(5);
//	pq1.push(1);
//	pq1.push(4);
//	while (!pq1.empty())
//	{
//		cout << pq1.top() << " ";
//		pq1.pop();
//	}
//	cout << endl;
//	//С��
//	priority_queue<int, vector<int>, Greater<int>> pq2;
//	pq2.push(3);
//	pq2.push(5);
//	pq2.push(1);
//	pq2.push(4);
//	while (!pq2.empty())
//	{
//		cout << pq2.top() << " ";
//		pq2.pop();
//	}
//	cout << endl;
//	return 0;
//}