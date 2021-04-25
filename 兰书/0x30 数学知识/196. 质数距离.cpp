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
ll t, n, l, r;

int vis[maxn], pr[maxn], tot;
int is_p(int n) {
	memset(vis, 0, sizeof vis);
	tot = 0;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[tot++] = i;
		for (int j = 0; pr[j] <= n / i; j++) { 
			vis[pr[j] * i] = 1;
			if (i % pr[j]== 0) break;
		}	
	}
}
void solve()
{
	
	while (cin >> l >> r) {
		is_p(100000);
		memset(vis, false, sizeof vis);
		for (int i = 0; i < tot; i++) {
			int p = pr[i];
			for (ll j = max(p * 2ll, (l + p - 1) / p * p); j <= r;j+=p) {
				vis[j - l] = 1;
			}
		}
		tot = 0;
		for (int i = 0; i <= r - l; i ++) {
			if (!vis[i] && i + l > 1) {
				pr[tot++] = i + l;
			}
		}
		if (tot < 2) {
			printf("There are no adjacent primes.\n");
		} else {
			int minp = 0, maxp = 0;
			for (int i = 0; i + 1 < tot;i ++) {
				int d =  pr[i + 1] - pr[i];
				if (d < pr[minp + 1] - pr[minp]) minp = i;
				if (d > pr[maxp + 1] - pr[maxp]) maxp = i;
				
			}
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", 
			pr[minp], pr[minp + 1], 
			pr[maxp], pr[maxp + 1]);
		}
		
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

