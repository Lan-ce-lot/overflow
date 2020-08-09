#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lowbit(x) ((x)&(-x))
#define inf 0x3f3f3f3f
#define endl "\n"
#define MP(x,y) (make_pair(x,y))
#define pii pair<int,int>
#define pll pair<long long,long long>
const double PI = acos(-1);
using namespace std;
const int mod = 1e9+7;
const int N = 300005;
struct edge{
	int to, nxt;
}e[N];
int head[N], tot = 1;
void add(int u, int v)
{
	e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}

int dep[N], mx[N], fa[N];
void dfs(int x, int f)
{
	dep[x] = dep[f] + 1;
	fa[x] = f;
	mx[x] = dep[x];
	for (int i = head[x]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (v == f)
			continue;
		dfs(v, x);
		mx[x] = max(mx[x], mx[v]);
	}
}
int n, m, s, t, ans;
int main(){
   scanf("%d%d", &n, &m);
   dep[0] = -1;
   s = 1, t = n;
   for (int i = 0; i < n - 1; i++)
   {
   		int x, y;
   		scanf("%d%d", &x, &y);
   		add(x, y);
   		add(y, x);
   }
   dfs(n, 0);
   for (int i = 0; i < m; i++)
   {
   		s = fa[s];
   }
   if (dep[s] <= dep[t])
   {
		printf("0\n");
		return 0;
   }
   ans = min(dep[s] - dep[t], (mx[t] - dep[n] + 1) / 2);
   t = 0;
	while (t < dep[s])
	{
		s = fa[s];
		t += 2;
		ans = max(min(dep[s] - t, (mx[s] - t + 1) / 2) + t / 2, ans);
	}
	printf("%d\n", ans);
}

