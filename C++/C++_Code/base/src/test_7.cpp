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
1.即使字符串为空，我们也要为它分配一个空间，一方面用于存储结束标志位'\0',另一方面用于占位；
2.思考一下，如果使用strcpy过程中，分配空间不足会怎么样？（如果空间分配不足，那么可能占用相邻空间，不会导致崩溃，但是会造成难以排查的错误！）
*/