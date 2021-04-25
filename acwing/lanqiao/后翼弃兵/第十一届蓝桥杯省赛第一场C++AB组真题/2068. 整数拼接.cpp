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
const int maxn = 100010;
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
ll t, n, k, a[maxn], ans;
ll cnt[11][maxn];

int log_10(int x) {
	int res = 0;
	while (x) {
		x /= 10;
		res ++;
	}
	return res;
}

void work() {
	for (int i = 1; i <= n; i++) {
		ans += cnt[log_10(a[i])][(k - a[i] % k) % k];
		for (int j = 0, power = 1; j < 11; j++) {
            cnt[j][power * 1ll * a[i] % k] ++ ;
            power = power * 10 % k;
		}
	}
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	work();
	memset(cnt, 0, sizeof cnt);
	reverse(a + 1, a + n + 1);
	work();
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

