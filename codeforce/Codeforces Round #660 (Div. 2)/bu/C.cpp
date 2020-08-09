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

int h[maxn];
int num[maxn];
int g[maxn];
int thr[maxn];
bool vis[maxn];
//int sum[maxn];
vector<int> G[maxn];
int flag = 0;
void dfs(int now, int root) {
	thr[now] = num[now];
	if (flag) return;
	int sum = 0;
//	cout << now << '*' << root << endl;
	for (int i = 0; i < G[now].size(); i++) {
		int tem = G[now][i];
		if (tem == root) continue;
//		if (vis[tem]) continue;
//		vis[tem] = 1;
		dfs(tem, now);
		thr[now] += thr[tem];
		sum += g[tem];
//		sum[now] += sum[tem];
		vis[tem] = 0;
	}
	if ((thr[now] + h[now]) % 2) {
		flag = 1;
//		cout << 1 << "*" << now << ' ' << thr[now] << ' ' << h[now]  << endl;
		return;
	}
	g[now] = (thr[now] + h[now]) / 2;
	if (!(g[now] >= 0 && g[now] <= thr[now])) {
		flag = 1;
//		cout << 2 << "*" << now << ' ' << thr[now] << ' ' << g[now]  << endl;
		return;
	}
	if (sum > g[now]) {
		flag = 1;
//		cout << 3 << "*" << now << ' ' << sum << ' ' << g[now]  << endl;
		return;
	}
}

void solve()
{
	cin >> t; 
	while (t--) {
		flag = 0;
		n = read(), m = read();
		memset(vis, 0, sizeof vis);
//		memset(thr, 0, sizeof thr);
		for (int i = 1; i <= n; i++) {
			num[i] = read();
//			thr[i] = num[i];
		}
		for (int i = 1; i <= n; i++) h[i] = read();		
		for (int i = 1; i <= n - 1; i++) {
			int l = read(), r = read();
			G[l].push_back(r);
			G[r].push_back(l);
		}
		

		vis[1] = 1;
		dfs(1, 0);
		if (flag == 1) {
			puts("NO");
//			continue;
		} else {
			puts("YES");
		}
		for (int i = 1; i <= n; i++) {
			G[i].clear();
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

