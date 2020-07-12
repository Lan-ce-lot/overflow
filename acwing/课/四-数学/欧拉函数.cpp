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
//欧拉函数1~N中与N互质数的个数
//调用phi(int x)即可
//复杂度为分解质因数的复杂度O(sqrt(n))
//==============================================================
vector<PII> A;//底数和指数

void divide(int x)//分解质因数
{
    A.clear();
    for (int i = 2; i <= x / i; i++)//底数和指数p和a
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s++;
//            cout << i << ' ' << s << endl;
            A.push_back({i, s});
        }
    }
    if (x > 1) A.push_back({x, 1});//cout << x << ' ' << 1 << endl;
}

int phi(int x)
{
    divide(x);
    int res = x;
    for (auto i : A)//容斥定理的结论
        res = res / i.first * (i.first - 1);
    return res;
}
//==============================================================
//筛法求欧拉函数，利用线性筛顺便求欧拉函数
//O(n)
//对一个数p分三种情况:
//质数p的欧拉函数为p - 1;
//i mod p == 0时phi(p * i) = p * phi(i);
//i mod p != 0时phi(p * i) = (p - 1) * phi(i);
//==============================================================
int primes[maxn], cnt;
int euler[maxn];
bool st[maxn];

void get_eulers(int n)
{
    euler[1] = 1;//由定义
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)//这是线性的原因
            {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}



//==============================================================
void solve()
{
    ll sum = 0;
    cin >> t;
    get_eulers(t);
    for (int i = 1; i <= t; i++)
        sum += euler[i];

    cout << sum << endl;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

