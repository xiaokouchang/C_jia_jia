//布隆过滤器
//降低误判率,无法消除误判
//字符串
//转成整形
//可能会存在冲突导致误判
//在:可能存在误判
//不在:准确
//应用
//(容忍误判)
//不需要精确的场景,比如判断昵称是否注册过
//可以降低查询负载压力,提高效率

#include"BloomFilter.h"

void test1()
{
	BloomFilter<10> bf;
	bf.Set("孙悟空");
	bf.Set("猪八戒");
	bf.Set("牛魔王");
	bf.Set("二郎神");
	cout << bf.Test("猪八戒") << endl;
	cout << bf.Test("孙悟空") << endl;
	cout << bf.Test("沙悟净") << endl;
}
void test2()
{
	srand(time(0));
	const size_t N = 100000;
	BloomFilter<N * 8> bf;//空间大,误判率越小

	std::vector<std::string> v1;
	//std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	std::string url = "猪八戒";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	//v2跟v1是相似字符串集(前缀一样),但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string urlstr = url;
		urlstr += std::to_string(9999999 + i);
		v2.push_back(urlstr);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str)) //误判
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	//不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		//string url = "zhihu.com";
		string url = "孙悟空";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}
	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}