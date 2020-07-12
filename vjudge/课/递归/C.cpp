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
int t, n, a[maxn], ans = INF, k;
int temp[11];
map<int, bool> M;


bool test(int a)
{
	for (int i = 0; i < k; i++)
	{
		if (a == temp[i])
		{
			return 1;
		}
	}
	return 0;
}
void  dfs(int ss, int a1, int res)
{
	if (ss == n)
	{
		ans = min(res, ans);
		return ;
	}
	if (test(a1))
	{
		dfs(ss + 1, a[ss + 1], res);
	}
	else
	{
		if (ss < k)
		{
			temp[ss] = a1;
			res++;
			dfs(ss + 1, a[ss + 1], res);
		}
		else
		{
			for (int i = 0; i < k; i++)
			{
				int tt = temp[i];
				temp[i] = a1;
			
				dfs(ss + 1, a[ss + 1], res + 1);
				temp[i] = tt;
		}
		}

	}
}


void solve()
{
	cin >> t;
	while (t--)
	{
		ans = INF;
		memset(temp, 0, sizeof temp);
		cin >> k >> n;
//		M.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		dfs(0, a[0], 0);
		
		cout << ans <<endl;
	 } 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

