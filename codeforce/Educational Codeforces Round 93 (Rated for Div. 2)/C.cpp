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
const int maxn = 100005;
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
int t, n;
ll sum[maxn];
ll a[maxn];
ll con_1[maxn];
ll sum_turn[maxn];
char str[maxn];
map<ll, ll> M;
void solve()
{
	t = read();
	while (t--) {
		n = read();
		memset(con_1, 0, sizeof con_1);
		M.clear();
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++) {
			a[i] = str[i] - '0';
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 0; i <= n; i++) {
			sum_turn[i] = sum[i] - i;
			M[sum_turn[i]] ++;
		}
//		for (int i = 0; i < n; i++) {
//			cout << 
//		}
		ll ans = 0;
		for (auto it : M) {
			ll tem = it.second;
//			if (tem == 2) {
//				tem == 1;
//			}
			if (tem == 0) continue;
			ans += (tem - 1) * tem / 2;
		}
		printf("%lld\n", ans);
		// 
//		for (int i = 1; i <= n; i++) {
//			cout << a[i] << endl;
//		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

