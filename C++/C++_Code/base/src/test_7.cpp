/*自定义类，包含定义一个类所需的全部元素
1.默认构造函数、构造函数、拷贝构造函数、析构函数、赋值函数；
2.运算符重载：+、[]、<<
3.实现友元函数，作为函数接口实现的一部分；
*/

#include <string.h>
#include <iostream>
#include <ostream>

using namespace std;

class String
{
public:
    //构造函数
    String(const char *str = nullptr);

    //拷贝构造函数
    String(const String &str);

    //析构函数
    ~String();

    //赋值函数
    String &operator=(const String &str);

    //加法运算法重载
    String operator+(const String &str);

    //[]重载
    char &operator[](int pos);

    friend ostream &operator<<(ostream &os, const String &str);

private:
    char *m_data;
};

String::String(const char *str)
{
    if (str == nullptr)
    {
        m_data = new char[1];
        m_data[0] = '\0';
    }
    else
    {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}

String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

String::~String()
{
    delete[] m_data;
}

String &String::operator=(const String &str)
{
    if (this == &str)
    {
        return *this;
    }

    delete[] m_data;

    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

String String::operator+(const String &str)
{
    char *temp = new char[strlen(str.m_data) + strlen(m_data) + 1];
    strcpy(temp, m_data);
    strcat(temp, str.m_data);
    return String(temp);
}

char &String::operator[](int pos)
{
    return *(m_data + pos);
}

ostream &operator<<(ostream &os, const String &str)
{
    return os << str.m_data;
}

int main(int argc, char **agrv)
{
    String str_0("hello ");
    String str_1("world");

    String str_2 = str_0 + str_1;
    char c = str_2[3];

    cout << str_2 << endl
         << c << endl;

    return 0;
}

/*
总结：
1.如果我们没有显式的定义构造函数，那么编译器将会创建一个默认的构造函数；一旦我们定义了任何构造函数，那么除非我们再定义一个默认构造函数，否则该类讲没有默认构造函数；
2.默认构造函数与自定义的构造函数似乎没有什么不同，但是实际上还是存在区别，例如类中包含有数组和指针，默认构造函数将会导致野指针等类似问题，此时需要自定义默认构造函数再内部控制对象初始化；这种情况同样可以扩大到类中，如果该类包含其它类，但是其他类没有默认构造函数，为了完成其他类的初始化，那么为该类自定义默认构造函数同样必不可少；
3.C++中的new相当于C语言中的malloc，如果我们分配一个对象那么就用new char[],如果要分配一组对象那么就要用new char[n]；但是需要注意的是，前者可以用delete m_data,也可以用delete []释放空间，但是后者只能用delete []释放空间，如果用delete释放new []分配的空间，那么将会只释放第一个，从而导致内存泄漏；基于上述原因，所以我们一律使用delete[]在析构函数中释放分配的空间；
4.即使字符串为空，我们也要为它分配一个空间，一方面用于存储结束标志位'\0',另一方面用于占位；
5.需要注意赋值函数的以下几点：
  返回引用；（当我们给一个值赋值时，只有返回其本身引用才有意义，否则如果返回一个新的变量，那么将会毫无意义；）
  自我判断；（赋值时无法避免把自己赋给自己，所以必须在函数内部加以判断；）
  释放原有空间，分配新的空间 ；（为什么不在原有空间上赋值，而必须销毁之前的，再创建一个新的呢？首先无法确保原有空间是否足够，其次就算足够如果我们使用strcpy，那么将会自动加一个\0，导致后面空间浪费了！）
6.思考一下，如果使用strcpy过程中，分配空间不足会怎么样？（如果空间分配不足，那么可能占用相邻空间，不会导致崩溃，但是会造成难以排查的错误！）
7.浅拷贝支付至指向某个对象的指针，而不复制对象本身，新旧对象还是共享同一块内存，而深拷贝会另外创造一个一模一样的对象，新对象与原对象不共享内存，修改新对象不会修改原对象；如果一个类里有指针，那么则必须对该指针进行深拷贝，反之，浅拷贝即可满足条件；
8.为什么在可以使用类成员函数进行运算符重载的情况下，还要使用友元函数进行运算符重载，这是因为可能存在下列情况：A = B*2.75;那么这个对应的是A = B.operaotr*(2.75);那么反过来呢？A=2.75*B；由于2.75并非对象，那么这种情况就无法成立，在此基础上，所以需要使用友元函数进行运算符重载；针对A=2.75*B就可以和class1 operator*（double m，const class1 &t）进行匹配；于非成员重载运算符函数来来说，运算符表达式左边的操作数对应于运算符函数的第一个参数，运算符表达式右边的操作数对应于运算符函数的第二个参数。因此，友元函数重载运算符一般是为了解决交换律的问题；
*/