/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 思想：dfs是扫行，其中有一个for迭代扫列，因为行不会重复，所以只需要一个一维来标记列
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
bool vis[maxn];

int n, k;
char maze[maxn][maxn];
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
int ans;
int way;
void dfs(int i)
{
    if (way == k)
    {
        ans++;
        return;
    }
    if (i >= n)
    {
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (!vis[j] && maze[i][j] == '#')
        {
            vis[j] = 1;
            way++;
            dfs(i + 1);
            vis[j] = 0;
            way--;
        }
    }
    dfs(i + 1);
}

void solve()
{
    while (~scanf("%d%d", &n, &k))
    {
        if (n == -1 && k == -1)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
            }
        }
        dfs(0);
        cout << ans << endl;
        memset(vis, 0, sizeof(vis));
        ans = 0;
        way = 0;
    }

}

int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

