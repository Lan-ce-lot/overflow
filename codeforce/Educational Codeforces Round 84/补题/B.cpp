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
const int maxn = 100005;
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
int t, n, k;
int vis[maxn];vector<int> A[maxn];
void solve()
{
	cin >> t;
//	debug(1);
	while (t--)
	{
		cin >> n;
		memset(vis, 0, sizeof vis);
		
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			for (int j = 0; j < k;j++)
			{
				int tem;
				cin >> tem;
				A[i].push_back(tem);
			}
			
		}
		
		
		queue<int> Q;
		for (int i = 0; i < n; i++)
		{
			int flag = -1;
			for (int j = 0; j < A[i].size(); j++)
			{
				if (!vis[A[i][j] - 1])
				{
//					vis[j] = i;
					flag = A[i][j] - 1;
					break;
				}
			}
			if (flag != -1)
			{
				vis[flag] = 1;
			}
			else
			{
				Q.push(i + 1);
			}A[i].clear();
		}
		
		if (Q.size() == 0 )
		{
			cout << "OPTIMAL" << endl;
		}
		else
		{
			cout << "IMPROVE" << endl;
			for (int i = 0; i < n; i ++)
			{
				if (!vis[i])
				{
					cout << Q.front() << ' ' << i + 1 << endl;
					break;
				}
			}			
		}

	}
}

int main()
{
//debug(1);
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

