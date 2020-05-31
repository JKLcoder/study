/*实现引用计数*/
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)),
                                         i(0),
                                         use(new size_t(1)) {}
    HasPtr(const HasPtr &p) : ps(p.ps),
                              i(p.i),
                              use(p.use) { ++*use; }
    HasPtr &operator=(const HasPtr &);
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;     //递增右侧运算对象的引用计数
    if (--*use == 0)//递减左侧对象的引用计数，如果为0，那么就删除，如果还有那么说明该对象并非最后一个，可以不用管，只改变引用计数即可
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;//将左侧引用计数指针指向右侧引用计数指针指向的空间
    return *this;
}

int main(int argc, char **argv)
{
    return 0;
}