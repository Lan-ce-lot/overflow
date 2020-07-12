/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

//所有数据：25%s是整数，不大于20位
//
//25%s是小数，整数部分和小数部分均不大于10位
//
//25%s是分数，分子和分母均不大于10位
//
//25%s是百分数，分子不大于19位
string str;

string del_0(string str)
{
    while (str.size() > 1 && str[str.size() - 1] == '0')
    {
        str = str.substr(0, str.length() - 1);
    }
    return str;
}

string del_1(string str)
{
    while (str.size() > 1 && str[0] == '0')
    {
        str = str.substr(1, str.length() - 1);
    }
    return str;
}

void solve()
{
    cin >> str;
    int len = str.size();
    int flag = 0;
    string str1, str2;

    if (str[0] == '-')
    {
        flag = 1;

        str = str.substr(1, len - 1);
    }



    if (flag == 0)
    {
        str = del_0(str);
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    else
    {
        str = del_0(str);
        reverse(str.begin(), str.end());
        cout << '-' << str << endl;
    }
}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}


