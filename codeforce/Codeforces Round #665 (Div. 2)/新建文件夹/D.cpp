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
int t, n, m;
vector<ll> G[maxn];
ll k[maxn];
ll con[maxn];
void dfs(int x, int fa) {
	
	for (int i = 0; i < G[x].size(); i++) {
		ll tem = G[x][i];
		if (fa != tem) {
			dfs(tem, x);
		}
	}
	
} 


void solve()
{
	t = read();
	while (t--) {
		n = read();
		for (int i = 0; i <= n; i++) G[i].clear();
		memset(k, 0, sizeof k);
		for (int i = 0; i < n - 1; i++) {
			ll a = read(), b = read();
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int all = n - 1;
		m = read();
		for (int i = 0; i < m; i++) {
			k[i] = read();
		}
		
		if (n - 1 > m) {
			for (int i = m; i < all; i++) k[i] = 1;
		} else {
			for (int i = m; i >= m; i--) k[all] = k[all] * k[i];
		}
		sort(k, k + all);
		for (int i = 0; i < all; i++) {
			cout << k[i] << ' ';
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

