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
int t, n, m;
int dis[65][65];
bool G[65][65][65];
int h[maxn], e[maxn], ne[maxn], ind = 0;
void add(int a, int b) {
	e[ind] = b, ne[ind] = h[a], h[a] = ind++;
}


void work() {
	for (int k = 1; k <= 64; k++) {
		for (int i = 1; i <= n; i++) {
			for (int t = 1; t <= n; t++) {
				for (int j = 1; j <= n; j++) {
					if (G[i][t][k-1]&&G[t][j][k-1]) {
						G[i][j][k] = 1;
						dis[i][j] = 1;
					}
				}
			}
		}
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void solve()
{
	n = read(), m = read();
	ind = 1;
	memset(dis,INF,sizeof(dis));
	memset(h, 0, sizeof h);
	for (int i = 0;  i < m; i ++) {
		int a = read(), b = read();
//		add(a, b);
		dis[a][b] = 1;
		G[a][b][0] = 1;
		
	}
	work();
	floyd();
    printf("%d",dis[1][n]);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

