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
ll t, n, k;
vector<int> Q[maxn];
int M[maxn];
int W[maxn];
void solve()
{
	cin>> t;
	while (t--)
	{
		n = read();
		memset(M, 0, sizeof M);
		memset(W, 0, sizeof W);
		
		for (int i = 0; i < n; i++)
		{
			k = read();
			for (int j = 0; j < k; j++)
			{
				int tem = read();
				Q[i].push_back(tem);
 
			}
//			sort(Q[i].begin(), Q[i].end());
		}
		
		
//		debug(1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < Q[i].size(); j++)
			{
				int tt = Q[i][j] - 1;
				if (M[tt] == 0 && W[i] == 0)
				{
					M[tt] = i + 1;
					W[i] = tt + 1;
//					debug(M[tt])
//	cout << i << ' ' << M[tt] << ' ' << W[i] << endl;
					break;
				}
				
			}
			Q[i].clear();
		}
//		for (int i = 0; i < n; i++)
//		{
//			cout << M[i] << ' ' << W[i] << endl;
//		}
		int flag = 0;
		for (int i = n - 1; i >= 0; i --)
		{
			if (W[i] == 0)
			{
				for (int j = n - 1; j >= 0; j --)
				{
					if (M[j] == 0)
					{
						cout << "IMPROVE" << endl;
						cout << i + 1 << ' ' << j + 1 << endl;
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
		}
		
		if (flag != 1)
		{
			cout << "OPTIMAL" << endl;
		}
 
	}
}
//10 4
int main()
{
 
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
