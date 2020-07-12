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
int t, n, d;
map<int, int> M;
int max_u = INF, max_d = 0, max_l = INF, max_r = 0, res = 0;
struct node
{
	int x, y, v;
}a[1025];




void solve()
{
	cin >> d >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].v;
//		G[a[i].x][a[i].y] = a[i].v;
//		max_u = min(max_u, a[i].x);
//		max_d = max(max_d, a[i].x);
//		max_l = min(max_l, a[i].y);
//		max_r = max(max_r, a[i].y);
	}
	
	for (int i = 0; i <= 1024; i++)
	{
		for (int j = 0; j <= 1024; j++)
		{
			int temp = 0;
			for (int k = 0; k < n; k++)
			{
				if (i - d <= a[k].x && i + d >= a[k].x && j - d <= a[k].y && j + d >= a[k].y)
				{
					temp += a[k].v;
				}
			
			}
			M[temp] ++;
			res = max(res, temp);
		}
	}
	cout << M[res] << ' ' <<res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

