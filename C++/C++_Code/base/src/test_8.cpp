#include <fstream>
#include <iostream>

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;
    outFile.open("carinfo.txt");
    if (!outFile.is_open())     
        return 0;

    cout << "Enter the make and model of automobile:";
    cin.getline(automobile, 50);
    cout << "Enter the model year:";
    cin >> year;
    cout << "Enter the original asking price:";
    cin >> a_price;

    d_price = 5 * a_price;

    //display information on srceen with cout

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model:" << automobile << endl;
    cout << "Year:" << year << endl;
    cout << "Was asking" << a_price << endl;
    cout << "Now aksing" << d_price << endl;

    //now do exact same things using outFile instead of cout
    outFile << fixed;
    outFile.precision(2);              //用两位小数显示输出
    outFile.setf(ios_base::showpoint); //强制显示小数点输出
    outFile << "Make and Model:" << automobile << endl;
    outFile << "Year:" << year << endl;
    outFile << "Was asking" << a_price << endl;

    outFile.close();
    return 0;
}