/*当const修饰指针时，我们需要分辨顶层指针与底层指针*/

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{

    int a = 23;
    int b = 34;

    const int *p1 = &a;  //指针指向常量对象
    int *const p2 = &b;  //常量指针
    
    //修改指向常量的指针指向
    p1 = &b;

    //修改指向常量的指针的值
    //*p1 = 24;  //报错：assignment of read-only location '* p1'

    //修改常量指针的指向
    //p2 = &a; //报错：assignment of read-only variable 'p2'

    //修改常量指针的值
    *p2 = 33;


    return -1;
}