//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")
 
 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
//#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll; 
typedef unsigned int ull; 
//typedef pair<int, int> P; 
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
struct ed{
	int to, nxt, w;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v){
	e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}
 
ll gt[N], siz[N], P[N], tp[N], ans;
int t, n, num;
void dfs(int x, int fa)
{
	siz[x] = 1;
	int s = 0;
//	ll sum = 0, res = 0;
	ll res = 0;
	for (int i = head[x]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (v == fa)	continue;
		dfs(v, x);
		gt[v - 1] = siz[v] * (n - siz[v]);
		siz[x] += siz[v];
	}
}
int  main()
{
	scanf("%d", &t);
	while (t--){
		ans = 0;
		scanf("%d", &n);
		tot = 1;
		for (int i = 1; i <= n; i++)
		{
			head[i] = 0;
			siz[i] = 0;
			gt[i] = 0;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b);
			add(b, a);
		}
		int ff = n - 1;
		scanf("%d", &num);
		if (ff > num)
		{
			for (int i = 0; i < ff - num; i++)
				P[i] = 1;
			for (int i = ff - num; i < ff; i++)
				scanf("%lld", &P[i]);	
			sort(P + ff - num, P + ff);
		}
		else
		{
			for (int i = 0; i < num; i++)
				scanf("%lld", &P[i]);
			sort(P, P + num);
			for (int i = ff; i < num; i++)
				P[ff - 1] = P[ff - 1] * P[i] % mod;
		}
		dfs(1, 0);
		sort(gt + 1, gt + ff + 1);
		for (int i = 1; i <= ff; i++)
		{
			ans += P[i - 1] * (gt[i] % mod);
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
}
