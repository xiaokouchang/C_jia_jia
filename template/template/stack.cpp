#include"stack.h"
using namespace sta;

template<class T, class Container>
void stack<T,Container>::push(const T& x)
{
	_con.push_back(x);
}

template<class T, class Container>
void stack<T, Container>::pop()
{
	_con.pop_back();
}

void A::func1()
{

}
//void A::func2()

template
class stack<int>;