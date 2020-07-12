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
const int maxn = 10005;
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
int happy[maxn];
vector<int> G[maxn];
int dp[maxn][2];
bool has_f[maxn];

void dfs(int p)
{
    dp[p][1] = happy[p];

    for (int i = 0; i < G[p].size(); i++)
    {
        int j = G[p][i];
        dfs(j);

        dp[p][0] += max(dp[j][0], dp[j][1]);
        dp[p][1] += dp[j][0];
    }
}


void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> happy[i];
    }

//    memset()

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
        has_f[a] = 1;
    }

    int root = 1;
    while (has_f[root])
        root++;

    dfs(root);

    cout << max(dp[root][0], dp[root][1]);

    return;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

