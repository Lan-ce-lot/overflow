/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
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
const int maxn = 1005;

ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

string str1(int x, int i = 0, string s = string(""))
{
    if (x == 0)
        return string("0");
//    s = (i == 1 ? "2" : "2(" + str1(i) + ")") + (s == "" ? "" : "+") + s;
    do if (x & 1)
        s = (i == 1 ? "2" : "2(" + str1(i) + ")") + (s == "" ? "" : "+") + s;
    while (++i, x >>= 1);
    return s;
}
int t, n;
int main()
{
    ios::sync_with_stdio(false);
    int a = 3, b = 2;
    do
        if (a>b)
            printf("do if: a=%d\n",a);

    while (b--);cout << b;
    while (b++)
        if (a>b)
            printf("while if: a=%d\n",a);
    cin >> n;
    cout << str1(n) << endl;
    return 0;
}
