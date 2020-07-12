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

int t, n, m, color[maxn];
vector <int> G[maxn];
bool vis[maxn];

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = 0; i < G[u].size(); i++)
    {
        int j = G[u][i];
        if (color[j] == -1)//未被染且不能符合条件
        {
            if (!dfs(j, !c)) return 0;
        }
        else if (color[j] == c) return 0;//已被染且相邻相同
    }
    return 1;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memset(color, -1, sizeof color);
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0))
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
        puts("Yes");
    else
        puts("No");

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

