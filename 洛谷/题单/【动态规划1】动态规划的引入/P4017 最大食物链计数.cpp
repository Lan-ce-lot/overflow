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
int t, n, m, ans;
vector<int> G[5005];
vector<int> revG[5005];
int GG[5005][5005];
int ru[5005];
int cu[5005];
int dp[5005];
void solve()
{
	n = read(), m = read();
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		a= read(), b = read();
		G[b].push_back(a);
		ru[b] ++;
		revG[a].push_back(b);
		cu[a] ++;
		GG[a][b] = 1;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (ru[i] == 0) {
			dp[i] = 1;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int a = Q.front();	
		Q.pop();
		for (int k = 1; k <= n; k++) {
			if (GG[a][k] == 0) continue;
			dp[k] = (dp[k] + dp[a]) % 80112002;
			ru[k]--;
			if (ru[k] == 0) {
				if (cu[k] == 0) {
					ans = (ans + dp[k]) % 80112002;
					
				}
				Q.push(k);
			}
		}
	}
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

