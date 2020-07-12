#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*string s, ss;
    ios::sync_with_stdio(false);//加速getline中cin的读入
    getline(cin, s);//读取一整行的字符包含空格，遇到换行结束，
    stringstream sin(s);//字符串读入流ss,从s中读入,必须加头文件<sstream>
    while(sin >> ss)
        cout << ss << endl;*/

    stringstream ss;
    int first;
    double second;
    ss << "456";//将“456”字符串输入流
    ss >> first;
    cout << first << endl;
    ss.clear();//清除,定义的stringstream的名称.clear();
    ss << "12.2";
    ss >> second;
    cout << second << endl;
    cout << first+second << endl;
    return 0;
}