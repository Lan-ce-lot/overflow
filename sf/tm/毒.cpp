/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
ll mod = 998244353;
ll pp[50000000];
ll Pow(ll a, ll b)
{
	if (a < 50000000 && pp[a])
		return pp[a];
	ll ans = 1;
	while (b)
	{
		if (b & 1)	
			ans = ans * a % mod;
		a = a * a % mod; 
		b >>= 1;
	}
	if (a < 50000000)
		return pp[a] = ans;
	else 
		return ans;
}
ll n, m, pw;
ll dfs(ll a, ll b)
{
	if (!b)
		return (dfs(a - 1, 1) + 1) % mod;
	if (b == 1)
		return ((5 + a) % mod * (a % mod) % mod + 2) * pw % mod;
	int fw = Pow((a + b) % mod, mod - 2);
	return (a % mod * fw % mod * dfs(a + b - 1, 1) + b * fw % mod * dfs(a, b - 1) + 1) % mod;
}
void solve()
{
	pw = Pow(2, mod - 2);
	cin >> n >> m;
	printf("%lld\n", dfs(n % mod, m));
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
