/*关于类的成员函数指针的使用*/

#include<iostream>
#include<cmath>
using namespace std;

class CA;
typedef int (CA::*pFun)(int,int);  

class CA
{
	public:
	int Max(int a,int b)
	{
		return a > b ? a:b;
	}

	int Min(int a,int b)
	{
		return a < b? a:b;
	}

	static int sMax(int a,int b)
	{
		return a < b?a :b;
	}

	static int Sum(int a,int b)
	{
		return a+b;
	}

	int Result(pFun fun,int a,int b)
	{
		return (this->*fun)(a,b);
	}
};

int Result(CA* pA,pFun fun,int a,int b)
{
	return (pA->*fun)(a,b);
}


int main()
{
	int n = 10;
    
    CA ca;

	int a = 3;
	int b = 4;

	cout << "1:" << ca.Result(CA::Max,a,b) << endl;
	cout << "2:" << Result(&ca,CA::Max,a,b) << endl;

	return 0;
}

/*
总结：
1.我们声明类的成员函数指针必须要确保：成员函数指针必须包含类名，因此类必须已经声明
2.因为成员函数指针必须依赖于类的实例化存在，所以这里这也决定了在该类中调用及类外调用该成员函数指针存在不同：该类中调用，实际已经存在了this，所以不需要传入类的实例化，我们把this当做这个实例化使用，而类外，则必须传入一个类的实例化对象；但是如果是一个静态成员函数呢？那么即使是类外，我们也是不需要传入实例化对象的；此时等同于普通函数；	
3.为什么必须要是用pA->*fun而不是pA->fun呢？如果我们把函数也作为类的成员，那么该类拥有的其实是函数对象，而非其其指针，所有我们需要解引用；
*/