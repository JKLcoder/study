/*关于函数传参,主要针对指针传递进行研究*/

#include <iostream>

using namespace std;

void reset(int *p)
{
    *p = 5;
    p = nullptr;
}

void reset_1(int **p)
{
    *p = nullptr;
}

int main(int argc, char **argv)
{
    int a = 42;
    int *p1 = &a;

    cout << "before:"
         << "a:" << a << endl;
    cout << "before:"
         << "p1:" << p1 << endl << endl;

    reset(p1);

    cout << "after:"
         << "a:" << a << endl;
    cout << "after:"
         << "p1:" << p1 << endl << endl;

    reset_1(&p1);

    cout << "after:"
         << "p1:" << p1 << endl;

    return -1;
}

/*
输出：
 before:a:42
 before:p1:0x61fe1c

 after:a:5
 after:p1:0x61fe1c

 after:p1:0

结论：
 从结果上来看，通过指针，我们可以修改指针所指向地址的值，但是并未改变指针所指向的地址；如果想要改变指针所指向的地址，必须传入其指针地址，即二级指针；
*/
