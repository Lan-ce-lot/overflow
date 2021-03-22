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
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 20005;
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
int t, n, m, q, e, ans = 0;
unordered_set<int> S;
vector<int> G[maxn], tmp;

struct node {
	int first, second;
	bool operator < (node &W) {
		if (W.first != first) {
			return first < W.first;
		}
		return second < W.second;
	}
};vector<node> res;
bool sex[maxn], vis[maxn];
void dfs(int u, int step, int flag) {
	if (step > 3) return;
	if (u == e) {
		if (step == 3) {
			ans++;
			res.push_back({tmp[0], tmp[1]});
		}
		return ;
	}
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		if (!vis[to]) {
			if (flag && sex[u] == sex[to]) {
				vis[to] = 1;
				tmp.push_back(to);
				dfs(to, step + 1, flag);
				tmp.pop_back();
				vis[to] = 0;
			}
			if (!flag) {
				if (step & 1 && sex[u] != sex[to]) {
					vis[to] = 1;
					tmp.push_back(to);
					dfs(to, step + 1, flag);
					tmp.pop_back();
					vis[to] = 0;
				}
				if (!(step & 1) && sex[u] == sex[to]) {
					vis[to] = 1;
					tmp.push_back(to);
					dfs(to, step + 1, flag);
					tmp.pop_back();
					vis[to] = 0;
				}
			}
		}
	}
}
void solve()
{
	n = read(), m = read();
	memset(sex, 0, sizeof sex);
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		int a_i = stoi(a), b_i = stoi(b);
		if (a[0] == '-') {
			a_i = abs(a_i);
			sex[a_i] = 1;
		}
		if (b[0] == '-') {
			b_i = abs(b_i);
			sex[b_i] = 1;
		}
		G[a_i].push_back(b_i);
		G[b_i].push_back(a_i);
		S.insert(a_i);
		S.insert(b_i);
	}
//	for (auto it : S)
//		sort(G[it].begin(), G[it].end());
	
	q = read();
	while (q--) {
		string a, b;
		tmp.clear();
		cin >> a >> b;
		int a_i = stoi(a), b_i = stoi(b);
		if (a[0] == '-') {
			a_i = abs(a_i);
		}
		if (b[0] == '-') {
			b_i = abs(b_i);
		}
		e = b_i;
		ans = 0;
		res.clear();
		dfs(a_i, 0, sex[a_i] == sex[b_i]);
		cout << ans << endl;
		sort(res.begin(), res.end());
		for (auto it : res) {
			printf("%4d %4d\n", it.first, it.second);
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

