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
int t, n;
ll W[maxn];
ll dp[100005];
ll ans = -INF;
vector<ll> G[maxn];
bool has_f[maxn];
bool vis[maxn];
void dfs(int p, int f)
{

    dp[p] = W[p];
    for (auto i : G[p])
    {
        if (i == f)//防止走重复路径
            continue;
        dfs(i, p);
        ans = max(ans, dp[p] + dp[i]);//两个子树连起来
        dp[p] = max(dp[p], dp[i] + W[p]);//选一个最大的子树连根

    }

}

void solve()
{
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> W[i];
        ans = max(ans, W[i]);
    }

    for (int i = 0; i < t - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, -1);

    cout << (ans) << endl;

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

