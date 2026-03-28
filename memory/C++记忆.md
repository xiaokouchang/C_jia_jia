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
