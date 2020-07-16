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
int t, n;
int a[maxn];
bool vis[maxn];
int ans = 0;
vector<int> G[maxn];

bool pre(int a, int b) {
	if (__gcd(a, b) == 1) {
		return 0;
	} return 1;
}

void dfs(int num, int room) {
	if (room >= ans) {
		return;
	}
	if (num > n) {
//		for (int j = 1; j <= room; j++) {
//			for (auto i : G[j])
//				cout << i << ' ';
//			puts("");			
//		}
		ans = min(ans, room);
		return;
	}
//	cout << num << ' ' << room << endl;
	for (int i = 1; i <= room; i++) {
		int flag = 0;
		for (int j = 0; j < G[i].size(); j++) {
			if (pre(a[num], G[i][j])) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
//			cout << '-' << 1;
			G[i].push_back(a[num]);
			dfs(num + 1, room);
			G[i].pop_back();
		}
	}
	G[room + 1].push_back(a[num]);
	dfs(num + 1, room + 1);
	G[room + 1].pop_back();
}


void solve()
{
//	cout << pre(147, 49) << endl;
	ans = INF;
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	dfs(1, 0);
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

