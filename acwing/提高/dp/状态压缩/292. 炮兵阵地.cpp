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
int t, n, m;
const int N = 16, M = 1 << 11, K = 110;
ll dp[2][M][M];
vector<int> state;
vector<int> head[M];
int line[maxn];
int cnt[maxn];
int ma[1005][1005];
bool check(int s) {
	for (int i = 0; i < m; i++) {
		if ((s >> i & 1) && ((s >> i + 1 & 1) || (s >> i + 2 & 1))) {
			return 0;
		}
	}return 1;
}

inline int lowbit(int x) {
	return x & -x;
}

int count(int s) {
	int res = 0;
	while (s > 0) {
		res ++;
		s -= lowbit(s);
	} return res;
}

void solve()
{
	n = read(), m = read();
	char s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s;
			if (s == 'P') {
				line[i] += (1 << (j - 1));
			} 
		}
	}
	for (int i = 0; i < 1 << m; i++) {
		if (check(i)) {
			state.push_back(i);
			cnt[i] = count(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < state.size(); j++) {
			for (int k = 0; k < state.size(); k++) {
				for (int u = 0; u < state.size(); u++) {
					int a = state[j], b = state[k], c = state[u];
					if (a & b | a & c | b & c) continue;
					if (((line[i] | b) > line[i]) | ((line[i - 1] | a) > line[i - 1])) continue;
					dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i - 1 & 1][u][j] + cnt[b]);
				}
			}
		}
	}
	int res = 0;
    for (int i = 0; i < state.size(); i ++ )
        for (int j = 0; j < state.size(); j ++ )
            res = max(res * 1ll, dp[n & 1][i][j]);
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

