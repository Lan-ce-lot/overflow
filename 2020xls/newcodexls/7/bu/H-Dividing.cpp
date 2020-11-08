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
ll t, n, N, K, ans = 0;

void solve()
{
	N = read(), K = read();
	// n是k的倍数 n=xk
	for (ll i = 2, j; i <= K; i = j + 1) {
		ll x = N / i;
		if (x == 0) break;
		j = N / x;
		ans = (ans + ((min(j, K) - i + 1) % mod * (x % mod))) % mod;
	}
	// n-1是k的倍数 n=xk+1
	for (ll i = 2, j; i <= K; i = j + 1) {
		ll x = (N - 1) / i;
		if (x == 0) break;
		j = (N - 1) / x;
		ans = (ans + ((min(j, K) - i + 1)) % mod * (x % mod)) % mod;
	}
	ans = (ans + N + K - 1) % mod;
	cout << ans << '\n';
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

