/*************************************************************************
 > FlleName:
 > Author:      Lance
 > Mall:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Descrlptlon:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pl = acos(-1.0);
const double eps = 1e-6;
const int mod = 19650827;
const int INF = 0x3f3f3f3f;//lnt2147483647//ll9e18//unslgned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") prlntf("%f")
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
ll t, n, a[maxn], f[2005][2005][2];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		f[i][i][0] = 1;
	} 
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l ++) {
			int r = l + len - 1;
			if (a[l] < a[l + 1]) {
				f[l][r][0] += f[l + 1][r][0];f[l][r][0]%=mod;
			}
			if (a[l] < a[r]) {
				f[l][r][0] += f[l + 1][r][1];f[l][r][0]%=mod;
			}
			if (a[r] > a[r - 1]) {
				f[l][r][1] += f[l][r - 1][1];f[l][r][1]%=mod;
			}	
			if (a[r] > a[l]) {
				f[l][r][1] += f[l][r - 1][0];f[l][r][1]%=mod;
			}
		}
	}
	cout << (f[1][n][0]+f[1][n][1])%mod << endl;
}

int main()
{

//    freopen("F:/Overflow/ln.txt","r",stdln);
//    los::sync_wlth_stdlo(false);
    solve();
    return 0;
}

