#include<deque>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
void test()
{
	deque<int> dq;
	dq.push_back(1); 
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	for (size_t i = 0;i < dq.size();i++)
	{
		cout << dq[i] << " ";
	}
	cout << endl;
}
void sort1()
{
	srand(time(0));
	const int N = 100000;
	vector<int> v1;
	vector<int> v2;
	v1.reserve(N);
	v2.reserve(N);
	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		auto e = rand();
		v1.push_back(e);
		v2.push_back(e);
		dq.push_back(e);
	}
	//拷贝到deque排序,排完以后再拷贝回来
	int begin1 = clock();
	for (auto e : dq)
	{
		v1.push_back(e);
	}
	sort(v1.begin(), v1.end());
	size_t i = 0;
	for (auto e : dq)
	{
		e = dq[i++];
	}
	int end1 = clock();
	int begin2 = clock();
	sort(v2.begin(), v2.end());
	int end2 = clock();
	printf("deque copy vector sort:%d\n", end1 - begin1);
	printf("vector sort:%d\n", end2 - begin2);
}
void sort2()
{
	srand(time(0));
	const int N = 1000000;
	vector<int> v1;
	vector<int> v2;
	v1.reserve(N);
	v2.reserve(N);
	deque<int> dq1;
	deque<int> dq2;
	for (int i = 0; i < N; i++)
	{
		auto e = rand();
		//v1.push_back(e);
		//v2.push_back(e);
		dq1.push_back(e);
		dq2.push_back(e);
	}
	//拷贝到deque排序,排完以后再拷贝回来
	int begin1 = clock();
	for (auto e : dq1)
	{
		v1.push_back(e);
	}
	sort(v1.begin(), v1.end());
	size_t i = 0;
	for (auto e : dq1)
	{
		e = dq1[i++];
	}
	int end1 = clock();
	int begin2 = clock();
	//sort(v2.begin(), v2.end());
	sort(dq2.begin(), dq2.end());
	int end2 = clock();
	printf("deque copy vector sort:%d\n", end1 - begin1);
	printf("deque sort:%d\n", end2 - begin2);
}
int main()
{
	//test();
	sort2();
	return 0;
}