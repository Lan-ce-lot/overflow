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
ll t, n, m, a[maxn], k, counter;
ll tem[maxn];
map<ll, bool> vis;
//i < 64
// > 10^16 break
int ff = 0;
void test(ll a, ll ans)
{
	if (ans == a)
	{
//		debug(11);
		ff = 1;
		return;
	}
	for (int i = 0; i < counter; i++)
	{
		if (!vis[tem[i]] && ans <= a - tem[i])
		{
			vis[tem[i]] = 1;
//			debug(ans + tem[i]);
			test(a, ans + tem[i]);
			if (ff)
			{
				return;
			}
			if (ff == 0)
			{
				vis[tem[i]] = 0;
			}
			
		}

	}
	return;
}

ll sum = 0;
void solve()
{
	cin >> t;
while (t--)
{
	ff = 0;
	sum = 0;
	cin >> n >> k;
	counter = 1;
	vis.clear();
	int flag = 0;
	tem[0] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	sort(a, a + n, greater<ll> ());
	
	for (int i = 1; i < 164; i++, counter++)
	{
		if (tem[i - 1]  > a[0] / k)
		{
			break;
		}
		
		else
		{
			tem[i] = tem[i - 1] * k;
		}
	}
//	for (int i = 0; i < counter; i++)
//	{
//		cout << tem[i] <<' ';
//	}
	test(sum, 0);
	if (!ff)
	{
		cout << "NO" << endl;
		continue;
	}
	vis.clear();
	for (int i = 0; i < n; i++)
	{
		ff = 0;
		if (a[i] == 0)
		{
			continue;
		}
		test(a[i], 0);
		if (!ff)
		{
		//	debug(a[i]);
			cout << "NO" << endl;
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		cout << "YES" << endl;
	}
}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*
5
4 100
0 0 0 0
1 2
1
3 4
1 4 1
3 2
0 1 3
3 9
0 59049 810

100
4 2
1 2 4 8
4 2
0 1 2 3
4 10
0 0 1110 0
4 100
1 10000000000000000 0 0


*/
