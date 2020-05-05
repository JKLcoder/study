/*关于const_cast在函数重载中的使用*/

#include <string>
#include <iostream>

using namespace std;

const string &shortstring(const string& s1,const string& s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shortstirng(string& s1,string& s2)
{
    auto &r = shortstring(const_cast<const string&>(s1),const_cast<const string&>(s2));
    return const_cast<string&>(r);
}

int main(int argc,char** argv)
{
    string s1 = "hello";
    string s2 = "world";

    cout << "The short string is:" << shortstring(s1,s2) << endl;

    return -1;
}

/*
总结：
 1.重载中，我们应该使用非const版本调用const版本；
 2.const_cast既可以将const变量转换为非const变量，也可以将非const变量转换为const变量，且这两个过程都是安全的；
 3.非const变量即使不调用const_cast也可以转换为const，但是这里为什么要使用const_cast呢？这是因为非const参数调用将优先非const版本，这将导致递归，当然另外一种办法我们也可以使用中间变量；
*/