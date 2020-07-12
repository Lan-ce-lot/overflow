/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
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
ll t, n;
ll a[maxn];
ll ans;

bool is_prime(ll n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void dfs(ll n, ll f)
{
	int temp = sqrt(n);
	if (is_prime(n) || n == f)
	{
		cout << n << endl;
		return;
	}
	
	else
	{
		for (int i = temp + 1; i <= n; i++)
		{
//			if (n % temp == 0)
//			{
//				dfs
//			}
			if (n % i == 0)
			{debug(n);
				dfs(i, n);
				
				break;
			}
		}
	}
}
/*
1-0
1-1
2-2
6-3
24-4
120-5
720-6
5040-7
40320-8
362880-9
3628800-10
39916800-11
479001600-12
6227020800-13
*/
ll j(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else 
		return n * j(n - 1);
}

void solve()
{
//	for (int i = 0; i < 100; i++)
//	{
//		cout << j(i) << endl;
//	}
//	debug(j(100));
	cin >> t;
	while (t--)
	{
		cin >> n;
//		n = t;
//		cout << n << ' ';
		// 1.素数
		// 2.平方数

//		if (is_prime(n))
//		{
//			cout << n << endl;
//			continue;
//		}
		int temp = sqrt(n);
//		cout << temp << endl;
//		for (int i = temp + 1; i <= n; i++)
//		{
//			if (n % i == 0)
//			{
//				cout << i << endl;
//				break;
//			}
//		}
		dfs(n, 0);
		
//		cout << ans << endl;
	}
	
}


/*
zabzzc

*/

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

