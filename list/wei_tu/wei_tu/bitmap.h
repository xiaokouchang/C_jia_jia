#pragma once
#include<iostream>
#include<vector>
using namespace std;
//2^32个比特位标记对应值在不在
//i = x / 32 第i个整形上面
//j = x % 32 第这个整形的第几个位上面
namespace BitMap
{
	template<size_t N>
	class bitmap
	{
	public:
		bitmap()
		{
			_a.resize(N / 32 + 1);//最坏情况下浪费32个比特位
		}
		//x标记的位映射成1
		void set(size_t x)
		{
			size_t i = x / 32;//第i个整形上面
			size_t j = x % 32;//这个整形的第几个位上面
			_a[i] |= (1 << j);
		}
		//x标记的位映射成0
		void reset(size_t x)
		{
			size_t i = x / 32;//第i个整形上面
			size_t j = x % 32;//这个整形的第几个位上面
			_a[i] &= ~(1 << j);
		}
		//判断在不在
		bool test(size_t x)
		{
			size_t i = x / 32;//第i个整形上面
			size_t j = x % 32;//这个整形的第几个位上面
			return _a[i] & (1 << j);
		}
	private:
		vector<int> _a;
	};
	template<size_t N>
	class twobitmap
	{
		//两个位
	public:
		//x标记的位映射成1
		void set(size_t x)
		{
			//00 -> 01
			if (!_bs1.test(x) && !_bs2.test(x))
			{
				_bs2.set(x);
			}
			else if (!_bs1.test(x) && _bs2.test(x))
			{
				//01 -> 10
				_bs1.set(x);
				_bs2.reset(x);
			}
			//本身10代表出现两次及以上,就不变了
		}
		bool is_once(size_t x)
		{
			return !_bs1.test(x) && _bs2.test(x);
		}
	private:
		bitmap<N> _bs1;
		bitmap<N> _bs2;
	};
}
