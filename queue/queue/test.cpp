#include"queue.h"
using namespace que;
int main()
{
	queue<int, list<int>> q1;//Ð§ÂÊµÍ
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;
	return 0;
}