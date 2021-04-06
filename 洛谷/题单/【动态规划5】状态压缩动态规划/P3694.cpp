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
const int maxn = 1e5 + 10;
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
int t, n, a[maxn], m, ans, res, f[1 << 23], maxx;
int sum[25][maxn], len[1 << 21];

int num[1 << 21];

int dp(int s) {
	if (f[s] != 1 << 30) return f[s];
	for (int i = 1; i <= m; i++) {
		if (s & (1 << (i - 1))) {
			int l = num[s] - len[i] + 1, r = num[s];
			f[s] = min(f[s], dp(s ^ (1 << (i - 1))) + len[i] - (sum[i][r] - sum[i][l - 1]));
		}
	}
	return f[s];
}

void solve() {
	cin >> n >> m;	
	maxx = (1 << m) - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		len[a[i]]++;
		for (int j = 1; j <= m; j++)
			sum[j][i] += sum[j][i - 1];
		sum[a[i]][i] ++;
	}

    for(int i = 1;i<=maxx;++i)
        f[i] = 1<<30;
//	f[0] = 0;
	for (int i = 1; i <= maxx; i++)
		for (int j = 1; j <= m; j++)
			if (i & (1 << (j - 1))) num[i] += len[j];
	cout << dp((1 << m) - 1) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

