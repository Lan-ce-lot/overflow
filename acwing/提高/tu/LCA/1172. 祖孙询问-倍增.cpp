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
const int N = 40010, M = N * 2; 
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
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][16];
int q[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
//inline void dfs(int k,int fa)
//{
//	d[k]=d[fa]+1;// 子节点的层数只其父节点层数+1
//	deep[k]=d[k];
//	maxx=max(maxx,d[k]);// 统计最大层数
//	p[k][0]=fa;
//	for(int i=1;(1<<i)<=d[k];i++)
//	{
//		p[k][i]=p[p[k][i-1]][i-1];// 倍增的关键！！！
//	}
//	for(int i=head[k];i;i=e[i].next)
//	{
//		int b=e[i].b;
//		if(b!=fa) dfs(b,k); // 如果没有处理过，就跑一边 dfs的思想
//	}
//}
// fa -> p
// d -> depth
// deep -> q
int ans0 = 0;
void dfs(int k, int f) {
	depth[k] = depth[f] + 1;
	q[k] = depth[k];
	ans0 = max(ans0, depth[k]);
	fa[k][0] = f;
	for (int i = 1; (1 << i) <= depth[k]; i++)
		fa[k][i] = fa[fa[k][i - 1]][i - 1];
	for (int i = h[k]; i; i = ne[i]) 
		if (e[i] != f) dfs(e[i], k);
}
void bfs(int root) {
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[root] = 1;
	int hh = 0, tt = 0;
	q[0] = root;
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; i; i = ne[i]) {
			int j = e[i];
			if (depth[j] > depth[t] + 1) {
				depth[j] = depth[t] + 1;
				q[++tt] = j;
				fa[j][0] = t;
				for (int k = 1; k <= 15; k++) {
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
				}
			} 
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 15; k >= 0; k--) // 跳同一层 
		if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
	if (a == b) return a;
	for (int k = 15; k >= 0; k--) // 同时往上跳 
		if (fa[a][k] != fa[b][k]) a = fa[a][k], b = fa[b][k];
	return fa[a][0];
	
}

void solve()
{
	n = read();
	int root = 0;
	memset(h, 0, sizeof h);
	idx = 1;
	for (int i = 0; i < n; i++) {
		int a = read(), b = read();
		
		if (b == -1) root = a;
		else add(a, b), add(b, a);
	}
	dfs(root, 0);
//	bfs(root);
//	for (int i = 0; i < 500; i ++) cout << depth[i] << endl;
	m = read();
	while (m--) {
		int a, b;
		a = read(), b = read();
		int p = lca(a, b);
		if (p == a) puts("1");
		else if (p == b) puts("2");
		else puts("0"); 
	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

