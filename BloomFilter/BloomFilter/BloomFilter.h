#pragma once
#include <bitset>
#include <string>
#include <vector>
#include<iostream>
using namespace std;
struct BKDRHash
{
    size_t operator()(const string& str)
    {
        register size_t hash = 0;
        for (auto ch : str)
        {
            hash = hash * 131 + ch;
        }
        //cout << "BKDRHash:" << hash << endl;
        return hash;
    }
};
struct APHash
{
    size_t operator()(const string& str)
    {
        register size_t hash = 0;
        size_t ch;
        for (size_t i = 0; i < str.size(); i++)
        {
            size_t ch = str[i];
            if ((i & 1) == 0)
            {
                hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
            }
            else
            {
                hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
            }
        }
        //cout << "APHash:" << hash << endl;
        return hash;
    }
};
struct DJBHash
{
    size_t operator()(const string& str)
    {
        register size_t hash = 5381;
        for (auto ch : str)
        {
            hash += (hash << 5) + ch;
        }
        //cout << "DJBHash:" << hash << endl;
        return hash;
    }
};

template<size_t N,class K = string,class Hash1 = BKDRHash,class Hash2 = APHash,class Hash3 = DJBHash>
class BloomFilter
{
public:
    //不支持reset,删除一个值,可能会影响其他值,同1个位标识不同的值
    //使用引用计数
	void Set(const K& key)
	{
        size_t hash1 = Hash1()(key) % N;
        _bs.set(hash1);

        size_t hash2 = Hash2()(key) % N;
        _bs.set(hash2);

        size_t hash3 = Hash3()(key) % N;
        _bs.set(hash3);
        //cout << "hash1:" << hash1 << endl;
        //cout << "hash2:" << hash2 << endl;
        //cout << "hash3:" << hash3 << endl << endl;
	}
    bool Test(const K& key)
    {
        size_t hash1 = Hash1()(key) % N;
        if (_bs.test(hash1) == false)
        {
            return false;
        }

        size_t hash2 = Hash2()(key) % N;
        if (_bs.test(hash2) == false)
        {
            return false;
        }

        size_t hash3 = Hash3()(key) % N;
        if (_bs.test(hash3) == false)
        {
            return false;
        }
        return true;
    }
private:
	bitset<N> _bs;
};