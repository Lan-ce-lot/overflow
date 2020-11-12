#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream> 
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#define ls (k << 1)
#define rs (ls | 1)
using namespace std;
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<ll, int> P; 
typedef pair<ull, ull> pll; 
const ll mod = 1e9 + 7;
const int N = 2e2 + 5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-12;
 
struct ed{
    int to, nxt, w;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v, int w){
    e[tot].to = v, e[tot].w = w, e[tot].nxt = head[u], head[u] = tot++;
}


int n;
ll f[N][7], ans;
ll qpow(int a, int x)
{
	int ans = 1;
	while (x)
	{
		if (x & 1)
			ans *= a;
		x >>= 1;
		a *= a;
	}
	return ans;
}
int main()
{
	while (~scanf("%d", &n))
	{
		ans = 0;
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				for (int x = 1; x <= 6; x++)
				{
					if (abs(x - j) == 5)	continue;
						f[i][j] += f[i - 1][x];
					for (int y = 1; y <= 6; y++)
					{
						if (x == y || x == j || y == j || abs(x - y) == 5)
							continue;
						if (i >= 3)
						{
							f[i][j] += qpow(2, i - 2) - 1;
						}
					}
				}
			}
		}
		ans = 0;
		for (int i = 1; i <= 6; i++)
			ans += f[n][i];
		printf("%lld\n", ans);
	}
}

