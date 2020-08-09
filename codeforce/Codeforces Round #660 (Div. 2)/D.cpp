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
int num[maxn];
int h[maxn];
vector<int> G[maxn];
bool vis[maxn];
ll co[maxn];
void bfs() {
	queue<int> Q;
	Q.push(1);
	vis[1] = 1;
	while (!Q.empty()) {
		int top = Q.front();
		Q.pop();
		for (int i = 0; i < G[top].size(); i++) {
			int tem = G[top][i];
			if (vis[tem] == 0) {
				Q.push(tem);
				vis[tem] = 1;
				
			}
		}
	}
}
ll cou[maxn];
ll tro[maxn];
int flag = 0;
void dfs(int top) {
	if (flag == 1) return;
	for (int i = 0; i < G[top].size(); i++) {
		int tem = G[top][i];
		if (vis[tem] == 0) {
			vis[tem] = 1;
			dfs(tem);
			tro[top] += tro[tem];
			cou[top] += h[tem];
			vis[tem] = 0;
		}
	}
	tro[top] += num[top];
	if (cou[top] > abs(h[top]) || abs(h[top]) > tro[top]) {
//		debug(1);
//		cout << cou[top] << ' ' << h[top] << ' ' << top << endl;
		cout << top << ' ' << h[top] << ' ' << tro[top] << endl;
		flag = 1;
	}
}

void solve()
{
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		flag = 0;
		memset(cou, -INF, sizeof cou);
		n = read(), m = read();
		for (int i = 0; i <= n; i++) G[i].clear();
		
		for (int i = 1; i <= n; i++) {
			num[i] = read();
//			tro[i] = num[i];
		}
		for (int i = 1; i <= n; i++) h[i] = read();
		for (int i = 1; i <= n - 1; i++) {
			int a = read(), b = read();
			G[a].push_back(b);
			G[b].push_back(a);
			
		}
		dfs(1);
		if (flag) {
			puts("NO");
		} else {
			puts("YES");
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

