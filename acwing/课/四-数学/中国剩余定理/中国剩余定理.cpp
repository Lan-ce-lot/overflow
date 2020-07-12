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
//==============================================================
//中国剩余定理
//1.exgcd求gcd和线性方程的两个参数
//2.乘上倍数
//3.
//==============================================================
ll x = 0, m1, a1;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve()
{
    cin >> t;
    t--;
    cin >> a1 >> m1;
    while (t--)
    {
        ll m2, a2;
        cin >> a2 >> m2;
        ll k1, k2;//k1 * a1 - k2 * a2 = m2 - m1;
        ll d = exgcd(a1, -a2, k1, k2);
        if ((m2 - m1) % d)
        {
            x = -1;
            break;
        }

        k1 *= (m2 - m1) / d;
        ll tem = a2 / d;
        k1 = (k1 % tem + tem) % tem;

        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }

    if (x != -1) x = (m1 % a1 + a1) % a1;

    cout << x << endl;

    return ;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

