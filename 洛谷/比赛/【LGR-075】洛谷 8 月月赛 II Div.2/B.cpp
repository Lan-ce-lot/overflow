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
#define x first
#define y second
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 2000010;
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
int t, n, k;
//map<ll, ll> M;
ll M[maxn];
ll tem[maxn];
ll con = 0;
bool vis[maxn];
void solve()
{
	n = read(), k = read();
	int flag = 0;
	
	for (int i = 0; i < n; i++) {
		ll a = read(), b = read();
		M[a] += b;
		tem[i] = a;
	}
//	cout << M.size();
	ll ans = -INF;
	for (int i = 0; i < n; i++) {
		vis[tem[i] + k] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (vis[tem[i]]) flag = 1;
	}
	if (k == 0) {
		int flag1 = 0;
		for (int i = 0; i < 1e6 + 5; i++) {
			if (M[i] >= 2) {
				flag1 = 1;
			}
		}
		if (flag1 == 0) {
			puts("NO");
			return;
		}
	}
	if (flag == 0) {
		puts("NO");
		return;
	}	
	if (k == 0) {
		for (int i = 0; i < 1e6 + 5; i++) {
			ans = max(ans, M[i] * i);
		}
		printf("%lld\n", ans);
		return;
	}
	for (int i = 0; i < 1e6 + 5; i++) {
		ll from = i;
		ll to = i + k;
		ans = max(ans, (i + i + k) * min(M[from], M[to]));
//		ans = max(ans, (k) * min(M[from], M[to]));
	}
	printf("%lld\n", ans);

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

