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
ll ans = 0;
const int N1 = (1 << 10);
int N;
const int M = 9 * 9 + 50;
ll dp[20][M][N1];// row, con, status

int cont_1[N1];
vector<int> to[N1];
bool vis[N1];
vector<int> status;
inline int lowbit(int x) {
	return x & -x;
}

int cont(int x) {
	int res = 0;
	while (x) {
		res++;
		x -= lowbit(x);
	}
	return res;
}
int cont_(int x) {
	int res = 0;
	for (int i = 0; (x >> i) > 0 ; i++) {
		if (x >> i & 1) {
			res++;
		}
	}
	return res;
}

bool check_row(int x) {
	for (int i = 0; x >> i > 0 ; i++) {
		if ((x >> i & 1) && (x  >> i + 1 & 1)) return 0;
	}
	return 1;
}

bool check_col(int x, int y) {
	return !(x & y);
}


void solve()
{

	n = read(), k = read();
	N = 1 << n;
	for (int i = 0; i < N; i++) {
		cont_1[i] = cont(i);
	}
	for (int i = 0; i < N; i++) {
		vis[i] = check_row(i);
		status.push_back(i);
	}
	for (int i = 0; i < N; i++) {
		if (!vis[i]) continue;
		for (int j = 0; j < N; j++) {
			if ((i & j) == 0 && check_row(i | j)) {
				to[i].push_back(j);
			}
		}
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= k; j++) {
			for (int q = 0; q < status.size(); q++) {
				int tt = status[q];
				int _1 = cont_1[tt];
				for (auto it : to[tt]) {
					if (j >= _1) {
						dp[i][j][tt] += dp[i - 1][j - _1][it];
					}
				}
			}
		}
	}
	cout << dp[n + 1][k][0] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

