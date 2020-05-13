/*自定义类，包含定义一个类所需的全部元素*/

#include <string.h>
#include <iostream>

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

using namespace std;

int main(int argc, char **agrv)
{
    string str("hello world");

    cout << str;

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
*/