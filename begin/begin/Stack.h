#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
namespace N1
{
	int x = 10;
}

struct Stack
{
	int* a;
	int top;
	int capacity;
};


//void StackInit(struct Stack* pst, int defaultCapacity = 4);
//void StackPush(struct Stack* pst, int x);
//void StackPush(struct Stack* pst, double x);