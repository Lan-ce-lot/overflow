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
int t, n, m, k, ans = INF, minn = INF;
int pa[maxn], dp[maxn], tem[maxn], tot = 1, all[maxn];
int find(int x) {
	if (x == pa[x]) return x;
	else return pa[x] = find(pa[x]);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) pa[x] = y, all[y] += all[x];
}
void solve()
{
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++) {
		pa[i] = i;
		all[i] = 1;
	}
	for (int i = 1; i <= k; i++) {
		int a = read(), b = read();
		unite(a, b);
	}
	
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) {
//			dp[tot++] = all[i];
			tem[tot++] = all[i];
			
		}
	}
	for (int i = 1; i < tot; i++) {
		for (int j = n; j >= tem[i]; j--) {
			if (abs(m - dp[j]) > abs(m - dp[j - tem[i]] - tem[i])) {
				dp[j] = dp[j - tem[i]] + tem[i];
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		if (minn > abs(dp[i] - m)) {
			minn = abs(dp[i] - m);
			ans = dp[i];
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

