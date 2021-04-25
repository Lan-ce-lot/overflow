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
int t, n, m, s, d, ans, man;
int ma[maxn];
struct node {
	int to, v, ne;
}G[maxn];
int h[maxn], tot;
void add(int a, int b, int c) {
	G[tot] = {b, c, h[a]}, h[a] = tot++; 
}
vector<int> PA, ANS;
int dis[maxn], vis[maxn], prv[maxn];
int dj() {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[0] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && (u == -1 || dis[u] > dis[j])) {
				u = j;
			}
		}
		vis[u] = 1;
		for (int i = h[u]; ~i; i = G[i].ne) {
			int to = G[i].to;
			dis[to] = min(dis[to], dis[u] + G[i].v);
		}
	}
	return dis[d];
}

void dfs(int u, int sum) {
	if (u == d) {
		if (man < sum) {
			man = max(man, sum);
			ANS = PA;	
		}
		ans++;
		return;
	}
	
	
	for (int i = h[u]; ~i; i = G[i].ne) {
		int to = G[i].to;
		if (vis[to] == 0 && dis[to] == dis[u] + G[i].v) {
			vis[to] = 1;
			PA.push_back(to);
			dfs(to, sum + ma[to]);
			PA.pop_back();
			vis[to] = 0;
		}
	}
}

void solve()
{
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++) {
		cin >> ma[i];
	} 
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c); 
	}
//	debug(dj());
	dj();
	
	memset(vis, 0, sizeof vis);
	
	PA.push_back(0);
	dfs(0, ma[0]);
	cout << ans << ' ';
	cout << man << endl;
	cout << ANS[0];
	for (int i = 1; i < ANS.size(); i++) {
		cout << ' ' << ANS[i];
	}
	puts("");
		
//	debug(ans);
}


int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

