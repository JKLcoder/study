/*
关于写入文件
*/
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
    outFile << "Was asking:" << a_price << endl;

    outFile.close();

    //read data from file
    ifstream inFile("carinfo.txt");
    if (!inFile.is_open())
        return 0;

    string str;
    cout << "read data from file:" << endl;

    while (getline(inFile, str))
        // while (inFile >> str)
        cout << str << endl;

    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

    return 0;
}

/*
总结：
 1.这里面提供了两种文件打开方式，一种是使用outFile.open("carinfo.txt");另一种是ifstream inFile("carinfo.txt");后者在进行类构造时会默认打开文件；
 2.从文件中读取时可以使用两种方式，getline(inFile, str)；inFile >> str；前者是一行一行读取，以换行符作为结束符，后者以空格作为结束符，如果要一行一行读取，只能使用getline；
 3.使用is_open判断文件是否打开；
 4.读取文件时什么状况会返回inFile.fail()呢？假设上面从文件中读取文件时，str时int类型，那么此时就会出现不匹配，从而出现此错误；
 5.考虑一下，为什么while (inFile >> str)可以用于判断文件读取流是否成功呢？结合源码如下：
   operator void *() const {
        if(state&(badbit|failbit) )
            return 0;
        return (void* )this;
    }
   当我们读取从文件中读取时，stream.iostate状态一旦出现badbit或failbit，那么就会返回空，也就是false状态；
6.当一个流对象离开其作用域时，会自动关闭；
*/