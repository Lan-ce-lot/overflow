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
typedef pair<int, int> PII;
typedef unsigned long long ULL;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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
int t, n, m;
//==============================================================

//!!!!!!!!!!!str从下标1开始输入
const int P = 131;//13331
char str[maxn];
ULL h[maxn], p[maxn];//h前缀，p次方


ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
//==============================================================
int f1[maxn];
int f(int a, int b, int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (f1[n])
    {
        return f1[n];
    }
    return (a * f(a, b, n - 1) + b * f(a, b, n - 2)) % 7;
}
string strl;
int a, b ,c;
void solve()
{
    while (~scanf("%d%d%d", &a, &b, &c), a || b || c)
    {

        cout << f(a, b, c) << endl;
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

