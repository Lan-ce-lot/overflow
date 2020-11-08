#include<iostream>
#include<cmath> 
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 4e6 + 5;
struct edge{
	int to, nxt;
}e[N];
int head[N], tot = 1;
void add(int v, int u)
{
	e[tot].to = u, e[tot].nxt = head[v], head[v] = tot++;
}
ll dp[N][2], dep[N];
void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	ll mx = 0, sum = 0, num = 0, dsum = 0, lnum = 0, rnum = 0;
	
	for (int i = head[x]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (v == fa)	continue;
		dfs(v, x);
		num++;
		mx = max(mx, dp[v][1] - dp[v][0] + 1);
		sum += dp[v][0];
		if (dp[v][1] - dp[v][0] + 1 <= dep[x] - 1)
		{
			lnum++;
			dsum += dp[v][1] - dp[v][0] + 1;
		}
		else
		{
			rnum++;
		}
	}
	if (num == 0)
	{
		dp[x][0] = dp[x][1] = dep[x] - 1;
	}
	else
	{
		if (!lnum)
		{
			dp[x][0] = sum;
			dp[x][1] = sum + dep[x] - 1;
		}
		else
		{
			dp[x][0] = dsum + sum - mx - (lnum - 1) * (dep[x] - 1);
			dp[x][1] = dsum + sum - mx + min(mx, dep[x] - 1);
		}
	}
} 
int T, n;
int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		dp[1][0] = 0;
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
			head[i] = 0;
		tot = 1;
		for (int i = 2; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			add(a, i);
			add(i, a);
		}
		dfs(1, 0);
		printf("Case #%d: %lld\n", t, dp[1][0]);
	}
}


