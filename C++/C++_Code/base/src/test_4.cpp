/*关于函数返回数组*/

#include <iostream>

using namespace std;

//方案一：使用类型别名
using arrT = int[10];
arrT *CreateVec1()
{
    static arrT t;  //这里相当于int t[10],此外static必不可少
    for (int i = 0; i < 10; ++i)
    {
        t[i] = i * 2;
        cout << "LK:" << t[i] << endl;
    }
    return &t;
}
//方案二：声明一个返回数组指针的函数
//方案三：使用尾置返回类型
//方案四：使用decltpe

int main(int argc, char **argv)
{
    arrT *a = CreateVec1();
    for (int i = 0; i < 10; ++i)
        cout << i << ":" << *(*a+i) << endl;  //要注意，a是指向数组的指针，而数组名本身就代表指针，所以a是二级指针，那么*a才是第一个元素的地址

    return -1;
}