/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
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
ll t, n = 1000100, k;
string str;
ll q_pow(int n, int x)
{
	ll res = 1;
	while (x)
	{
		if (x & 1)
		{
			res = res % mod * n % mod;
		}n  = n * n % mod;
		x >>= 1;
	}
	return res % mod;
}
void init(int t)
{
	ll res = 0;
	
//	debug(1);
	for (int i = 0; i < 20; i++)
	{
		res = 0;
		ll aa = t;
		while (aa)
		{
			res += q_pow((aa % 10), i);
			if (res > t)
			{
				break;
			}

			aa /= 10;
		}			if (res == t)
			{
				cout << t << ',';
				return ;
			}
	}
}
/*
1
2
153
*/
int da[maxn] = {1,2,3,4,5,6,7,8,9,153,370,371,407,1634,4150,4151,8208,9474,54748,92727,93084,194979,548834

};
int count1[maxn], ans = 0;
void solve()
{
//	for (int i = 1; i < n; i++)
//	{
//		init(i);
//	}
	cin >> t;
	for (int i = 0; i < 23; i++)
	{
		count1[da[i]] = 1;
//		cout << da[i] << endl;
	}
	while (t--)
	{
		cin >> n;
		if (count1[n])
		{
			ans++;
		}
	}
	cout << ans << endl;
			//cin >> n;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

