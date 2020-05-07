#include<iostream>
#include<cmath>
using namespace std;

double Getln2(int n)
{
	int i;
	double sum = 0;
	for (i = 1; i <= n; i++)
	{
		double j = 1.0 / i * pow(-1, i - 1);
		sum = sum + j;
	}
	return sum;
}

int main()
{
	int n = 10;
	double ln2 = 0.69314718;
	double R = Getln2(10);
	while (fabs(ln2 - R) > 2.0e-5)
	{
		n++;
		R = Getln2(n);
	}

	cout << "根据泰勒展开式（麦克劳林展开式），由前" << n << "项可得" << endl;
	cout << "ln2 = " << Getln2(n) << endl;

	return 0;
}