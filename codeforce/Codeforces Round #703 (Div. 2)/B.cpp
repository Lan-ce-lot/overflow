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
int xx[maxn], yy[maxn];
deque<PII > X;
deque<PII > Y;
bool vis[maxn];
int tmp[maxn];
void solve()
{
	t = read();
	while (t--) {
		map<PII, int> M; 
		n = read();
		for (int i = 0; i < n; i++) {
			xx[i] = read(), yy[i] = read();
			X.push_back({xx[i], i});
			Y.push_back({yy[i], i});
		}
		memset(vis, 0, sizeof vis);
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		while (X.size() > 4 && Y.size() > 4) {
			while (vis[X.front().y] == 1 && X.size() > 0) {
				X.pop_front();
			}
			while (vis[Y.front().y] == 1 && Y.size() > 0) {
				Y.pop_front();
			}
			while (vis[X.back().y] == 1 && X.size() > 0) {
				X.pop_back();
			}
			while (vis[Y.back().y] == 1 && Y.size() > 0) {
				Y.pop_back();
			}
			if (vis[X.front().y] == 0) {
				vis[X.front().y] == 1;
				X.pop_front();
			}
			if (vis[Y.front().y] == 0) {
				vis[Y.front().y] == 1;
				Y.pop_front();
			}
			if (vis[X.back().y] == 0) {
				vis[X.back().y] == 1;
				X.pop_back();
			}
			if (vis[Y.back().y] == 0) {
				vis[Y.back().y] == 1;
				Y.pop_back();
			}
		}
		ll ans = 0;
		int con = 0;
		while (X.size()) {
			tmp[con++] = X.front().y;
		}
		if (con == 0) {
			
		} else if (con == 1) {
			
		} else if (con == 2) {
			
		} else if (con == 3) {
			
		}
		cout << ans << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

