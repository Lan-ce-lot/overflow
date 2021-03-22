#include <bits/stdc++.h>
using namespace std;
int t, n, m, f[1005][1005];
int dp(int n, int m) {
	if (~f[n][m]) return f[n][m];
	if (!n) return f[n][m] = 1;
	if (!m) return f[n][m] = 0;
	if (m > n) return f[n][m] = dp(n, n);
	return f[n][m] = dp(n, m - 1) + dp(n - m, m);//盘子数小于等于苹果数 -> 分类讨论： 有盘子为空，没有盘子为空
//有盘子为空的时候即至少有一个盘子为空，f(x,y-1);没有盘子为空即最少每个盘子都有一个,f(x-y,y)   
}
void solve()
{
	cin >> t;
	while (t--) {
		memset(f, -1, sizeof f);
		cin >> n >> m;
		cout << dp(n, m) << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

