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
int t, n, m, a[maxn], res;
bool vis[maxn], f[maxn];
void dp() {
	memset(f, 0, sizeof f);
	f[0] = 1;
	int tot = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		for (int j = tot; j >= 0;j--) {
			if (f[j] && !f[j + a[i]])
			f[j + a[i]] = 1, ans ++;
		}
		tot += a[i];
	}
	res = max(ans, res);
}

void dfs(int cn, int now) {
	if (now > m) return ;
	if (cn == n) {
		if (now == m) dp();
		return;
	}
	dfs(cn + 1, now);
	vis[cn + 1] = 1;
	dfs(cn + 1, now + 1);
	vis[cn + 1] = 0;
}



void solve()
{
	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(0, 0);
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

