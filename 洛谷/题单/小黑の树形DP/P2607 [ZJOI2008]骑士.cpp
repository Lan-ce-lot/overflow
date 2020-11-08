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
int t, n;

//struct node {
//	int to, v;
//}e[maxn];
ll e[maxn], ne[maxn], h[maxn], tot = 1;
ll node[maxn];
void add(ll a, ll b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot ++;
}
ll dp[maxn][2], ans = 0;
int root = 0;
bool vis[maxn];
int fa[maxn];
void dfs(int u) {
	vis[u] = 1;
	dp[u][0] = 0;
	dp[u][1] = node[u];
	for (int i = h[u]; i; i = ne[i]) {
		int to = e[i];
		if (to == root) {
			dp[to][1] = -INF;
			continue;
		}
		dfs(to);
		dp[u][0] += max(dp[to][1], dp[to][0]);
		dp[u][1] += dp[to][0];
	}
}

void fin_c(int x) {
	vis[x] = 1;
	root = x;
	while (!vis[fa[root]]) {
		root = fa[root];
		vis[root] = 1;
		
	}
	dfs(root);
    long long t=max(dp[root][0],dp[root][1]);
    vis[root]=1;
    root=fa[root]; 
    dfs(root);
    ans+=max(t,max(dp[root][0],dp[root][1]));
    return;	
	
}

void solve()
{
	n = read();
	
	
	for (int i = 1; i <= n; i++) {
		node[i] = read();
		ll a = read();
		
		add(a, i);
		fa[i] = a;
//		add(a, i);
	}
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            fin_c(i);
        }
    }
    printf("%lld\n",ans);	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

