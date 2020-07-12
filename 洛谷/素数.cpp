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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 10000005;

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
int t, n, m, ans = 0;
int primes[maxn], cnt = 0;
bool st[maxn];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

string str, strr;
void solve()
{
    int l, r;
    while (cin >> l >> r)
    {
        if (r > 10000000)
            r = 10000000;
        get_primes(r);
//        debug(100);
        for (int i = 0; i < cnt; i++)
        {
            str = strr = "";
            if (primes[i] < l)
                continue;
            else
            {
                int tem = primes[i];
                while (tem)
                {
                    str += '0' + tem % 10;
                    tem /= 10;
                }
                strr = str;
                reverse(str.begin(), str.end());
                if (strr == str)
                {
                    cout << str << endl;
                }
            }
        }
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    return 0;
}

