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
ll t, n, k;
ll dp[31][31][31][31][31];
void solve() {
	while (cin >> k, k) {
		int tm[6] = {0};
		for (int i = 0; i < k; i++) 
			cin >> tm[i];
        memset(dp, 0, sizeof dp);
        dp[0][0][0][0][0] = 1;
		for (int a = 0; a <= tm[0]; a++)
			for (int b = 0; b <= min(a, tm[1]); b++)
				for (int c = 0; c <= min(b, tm[2]); c++)
					for (int d = 0; d <= min(c, tm[3]); d++)
						for (int e = 0; e <= min(d, tm[4]); e++) {
							ll &p = dp[a][b][c][d][e];
							if (a && a - 1 >= b) p += dp[a - 1][b][c][d][e];
							if (b && b - 1 >= c) p += dp[a][b - 1][c][d][e];
							if (c && c - 1 >= d) p += dp[a][b][c - 1][d][e];
							if (d && d - 1 >= e) p += dp[a][b][c][d - 1][e];
							if (e) p += dp[a][b][c][d][e - 1];
						}
		cout << dp[tm[0]][tm[1]][tm[2]][tm[3]][tm[4]] << endl;
	} 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

