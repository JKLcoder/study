/*关于函数传参,主要针对可变形参进行研究,可变形参分为两部分：initializer_list适用于所有实参类型相同，可变参数模板则没有这种限制*/

#include <iostream>

using namespace std;

//initializer_list的使用
int add(initializer_list<int> list)
{
    int sum = 0;
    for (int i : list)
        sum += i;

    //list[5] = 12;  //报错：没有匹配的运算符；事实上，c++根本就没有为initializer_list实现类似[]、at()这种访问及修改借口

    return sum;
}

//可变参数模板
template <typename T>
ostream &My_Print(ostream &os, const T &t) //此函数必须定义，负责终止递归并打印初始调用中的最后一个实参
{
    return os << t;
}

//typename... Args,表示多个模板参数；const Args &... rest，表示多个函数参数
template <typename T, typename... Args>   
ostream &My_Print(ostream &os, const T &t, const Args &... rest)  //这个是可变参数模板，它打印绑定到t的实参，并调用自身来打印函数参数保重的剩余值
{
    os << t << ", ";
    return My_Print(os, rest...);
}

int main(int argc, char *argv[])
{

    //initializer_list的使用
    int sum = add({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    cout << "The sum is:" << sum << endl;

    //函数参数模板
    My_Print(cout,12,"hello",34);


    return -1;
}

/*
总结：
 initializer_list貌似和vector类似，但区别在于，initializer_list中是常量值，我们无法改变它其中元素的值；
 函数参数模板通常都是递归的，我们必须注意到这一点，第一个用于终止这种递归，另一个用于递归，在这个函数中，为了完成递归，其参数列表必须要包含可绑定的参数t，以及函数参数包，在最后终止时，也就是函数参数包为空了，此时代码自动调用第一个函数；
*/