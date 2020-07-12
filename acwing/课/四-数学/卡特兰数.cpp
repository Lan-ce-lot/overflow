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
const int maxn = 1000005;

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
int t, n;

//给定n个0和n个1，它们按照某种顺序排成长度为2n的序列，
//满足任意前缀中0的个数都不少于1的个数的序列的数量为：
//Cat(n) = C(2n, n) / (n + 1)

int q_pow(int n, int x, int mod)
{
    ll res = 1;
    while (x)
    {
        if (x & 1)
        {
            res = (ll) res * n % mod;
        }
        n = (ll)n * n % mod;
        x >>= 1;
    }
    return res;
}
ll C(int a, int b, ll mod)//快速幂 + 逆元求组合数
{
    ll res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        res = res * j % mod;
        res = res * q_pow(i, mod - 2, mod) % mod;

    }
    return res;
}

ll Lucas(ll a, ll b, ll mod)//调用即可，C(a, b)
{
    if (a < mod && b < mod)
    {
        return C(a, b, mod);
    }
    return C(a % mod , b % mod, mod) * Lucas(a / mod, b / mod, mod) % mod;

}
void solve()
{
    cin >> n;
    cout << Lucas(2 * n, n, mod) * q_pow(n + 1, mod - 2, mod) % mod << endl;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

