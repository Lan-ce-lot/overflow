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
int G[2005][2005], d[maxn];
bool vis[maxn];
int prim()
{
    memset(d, 0x3f, sizeof d);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (u == -1 || d[u] > d[j]))
            {
                u = j;
            }
        }

        if (i && d[u] == INF) return INF;

        if (i) res += d[u];
        vis[u] = 1;
        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], G[u][j]);
    }
    return res;
}

void solve()
{
    cin >> n >> m;

    memset(G, 0x3f, sizeof G);//!用邻接矩阵的时候一定初始化

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = G[b][a] = min(c, G[a][b]);
    }
    int ans = prim();
    if (ans > INF / 2)
        puts("impossible");
    else
        cout << ans << endl;

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

