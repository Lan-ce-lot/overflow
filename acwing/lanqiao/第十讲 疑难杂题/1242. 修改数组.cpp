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
int t, n, a[maxn], p[maxn], vis[maxn], ans[maxn];
set<int> S;
int find(int x) {
	if (x != p[x]) {
		return p[x] = find(p[x]);
	}
	return x;
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y)
		if (x > y)
			p[y] = x;
		else
			p[x] = y;
}


void solve()
{
	cin >> n;
	for (int i = 1; i <= 1000006; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
//		if (S.count(a[i])) {
		if (vis[a[i]]) {
			int tmp = find(a[i]);
			vis[tmp + 1] = 1;
			Union(tmp + 1, tmp);
			ans[i] = tmp + 1;
		} else {
			if (a[i] - 1 > 0)
				Union(a[i], a[i] - 1);
			vis[a[i]] = 1;
			ans[i] = a[i];
//			S.insert();
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
 
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

