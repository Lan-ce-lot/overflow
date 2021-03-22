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
int t, n, m;
int in[maxn], pr[maxn], depth[maxn], fa[maxn][22], lg[maxn];
vector<int> G[maxn];
void build(int il, int ir, int p_l, int p_r, int f) {
	if (il > ir) return;
	int i = il;
	int now = pr[p_l];
	while (in[i] != now) i++;
	if (f != -1)
		G[f].push_back(now), depth[now] = depth[f] + 1;
	fa[now][0] = f;
	for (int i = 1; i <= lg[depth[now]]; i++)
		fa[now][i] = fa[fa[now][i - 1]][i - 1];
	build(il, i - 1, p_l + 1, p_l + 1 + i - 1 - il, now);
	build(i + 1, ir, p_l + 1 + i - il, p_r, now);
}
int lac(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	while (depth[x] > depth[y])
		x = fa[x][lg[depth[x] - depth[y]] - 1];
	if (x == y) return x;
	for (int k = lg[depth[x]] - 1; k >= 0; k--) 
		if (fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0]; 
}

void solve()
{
	set<int> S;
	n = read(), m = read();
	for (int i = 0; i < m; i++) {
		in[i] = read();
		S.insert(in[i]);
	}
	for (int j = 0; j < m; j++) {
		pr[j] = read();
	}
	for (int i = 1; i <= m; i++) {
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	build(0, m - 1, 0, m - 1, -1);
	while (n--) {
		int a = read(), b = read();
		if (!S.count(a) && !S.count(b)) {
			printf("ERROR: %d and %d are not found.\n", a, b);continue;
		}
		if (!S.count(a)) {
			printf("ERROR: %d is not found.\n", a);continue;
		}
		if (!S.count(b)) {
			printf("ERROR: %d is not found.\n", b);continue;
		}
		int ans = lac(a, b);
		if (ans == a || ans == b) {
			printf("%d is an ancestor of %d.\n", ans, a == ans ? b : a);continue;
		} else {
			printf("LCA of %d and %d is %d.\n",a, b, ans);continue;
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

