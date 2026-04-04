# endl和\n

`endl` = **换行 + 刷新缓冲区**

高频输出优先用 `\n`（更快），需要**立即输出**时用 `endl`

![](D:\VS_code\gitee\C_jia_jia\图片\endl.png)

![](D:\VS_code\gitee\C_jia_jia\图片\没有endl.png)

执行到endl，就一定会立即刷新。

`\n` = 换行，但不一定立刻刷新。

**\n刷新的3种情况**

1、遇到**下一个\n**时刷新

2、**缓冲区满了**自动刷新

3、**程序结束**自动刷新

**立刻看到输出,实时输出** → 用 `endl`

**程序跑得快** → 用 `\n`

***

# sleep

sleep(3)表示睡眠3秒

# 内联函数与成员函数

**成员函数如果在类体中直接定义，编译器会自动为其添加 `inline` 关键字（隐式内联）**。

**类内定义成员函数**：自动隐式内联，天然满足声明和定义不分离。



![](D:\VS_code\gitee\C_jia_jia\图片\声明和定义.png)

![](D:\VS_code\gitee\C_jia_jia\图片\不能分开放.png)

# 递归

![image-20260328104753308](D:\VS_code\gitee\C_jia_jia\图片\递归.png)

![](D:\VS_code\gitee\C_jia_jia\图片\递归1.png)



![](D:\VS_code\gitee\C_jia_jia\图片\递归2.png)

# 类模板中的typename与class

使 用 类 模 板 使 用 :: 时 要 注 意 前 面 是 类 型 还 是 对 象。如 果 是 类 型，前 面 要 加 typename，如 果 是 对 象，前 面 不 需 要。

![](D:\VS_code\gitee\C_jia_jia\图片\模版编译.png)

![](D:\VS_code\gitee\C_jia_jia\图片\class和typename的区别.png)

# 结构体指针和类模板实例化后的类指针

```C++
//C++
template<class K>
class BSTreeNode
{
public:
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};
//C
typedef int BTDataType;
typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTDataType data;
};
```

```c++
//三种写法完全一样
//写法1：老式冗余写法
template<class K> 
class BSTreeNode 
{
public:
    class BSTreeNode<K>* _left;
    class BSTreeNode<K>* _right;
};

// 写法2：正常写法
template<class K> 
class BSTreeNode 
{
public:
    BSTreeNode<K>* _left;
    BSTreeNode<K>* _right;
};

// 写法3：最简标准写法（推荐）
template<class K> 
class BSTreeNode 
{
public:
    BSTreeNode* _left;
    BSTreeNode* _right;
};
```

# 拷贝交换法

必须传值，绝对不能传引用！传引用会修改等号右边的对象。传值调用拷贝构造函数生成临时变量，交换指针的地址（等号左边的对象与临时变量），函数结束后，临时变量被销毁。全程没有改变等号右边的变量。

赋值运算符的规则：只能修改等号左边，绝对不能修改等号右边！

**交换指针的地址**

```c++
void swap(Node*& root1, Node*& root2)
{
	Node* tmp = root1;
	root1 = root2;
	root2 = tmp;
}
```

**交换值**

```c
void Swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}
```

# 值和迭代器的区别

这个值如果在,两种都删除,如果不在,迭代器会崩溃,传值会正常运行。C++所有容器都支持

**不要直接删除 `find` 返回的迭代器**，必须先判断是否有效

```c++
auto pos = s.find(3);
if(pos!=s.end())
{
    s.erase(pos);//迭代器位置
}
s.erase(3);//值
s.erase(30);//值
```

# 迭代器区间

C++ STL所有迭代器区间是左闭右开。

# map中的[ ]



**`map[]` 底层 = 调用 `insert`**

**`insert` 返回值固定：`pair<迭代器, bool>`**

- `key 已存在` → 返回**已存在节点的迭代器** + `false`
- `key 不存在` → 返回**新插入节点的迭代器** + `true`

```c++
// map 的 [] 运算符底层源码（简化版）
V& operator[](const K& key)
{
    // 1. 调用 insert 插入 {key, 默认值}
    pair<iterator, bool> ret = insert(make_pair(key, V()));
    
    // 2. 返回 迭代器指向的 value 的引用
    return ret.first->second;
}
```

```c++
(*((this->insert(make_pair(k,mapped_type()))).first)).second
```

这两段代码是等价的

![](D:\VS_code\gitee\C_jia_jia\图片\map的[ ]覆盖.png)

![map中的[ ]](D:\VS_code\gitee\C_jia_jia\图片\map中的[ ].png)

| 操作            | 底层行为               | key 存在                     | key 不存在                    | 返回值               |
| --------------- | ---------------------- | ---------------------------- | ----------------------------- | -------------------- |
| `insert({k,v})` | 直接插入               | 不插入，返回旧迭代器 + false | 插入，返回新迭代器 + true     | `pair<迭代器, bool>` |
| `map[k]`        | 调用 insert + 返回引用 | 返回旧 value 引用            | 插入默认值，返回新 value 引用 | `value&`（可赋值）   |
