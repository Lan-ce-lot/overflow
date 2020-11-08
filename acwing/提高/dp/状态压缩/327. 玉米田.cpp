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
const int mod = 100000000;
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
int ma[1005][1005];
vector<int> state;
vector<int> head[20];
int cnt[maxn];
ll line[maxn];
ll dp[20][1 << 10];
bool check(int s) {
	for (int i = 0; i < m; i++) {
		if ((s >> i & 1) && (s >> i + 1 & 1)) {
			return 0;
		}
	}
	return 1;
}

inline int lowbit(int x) {
	return x & -x;
}

int count(int state)
{
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += state >> i & 1;
    return res;
}

void solve()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ma[i][j] = read();
		}
	}

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ma[i][j] == 1) {
				line[i] += (1 << (j - 1));
			}
			
		}
//		cout << line[i] << endl;
	}
	debug((1 << m));
//	cout << (1 << m) << endl;
	for (int i = 0; i < 1 << m; i++) {
		if (check(i)) {
			state.push_back(i);
//			cout << i  << ' ' << cnt[i]<< endl;
		}
	}
//		cout << state.size() << endl;
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			int a = state[i], b = state[j];
			if ((a & b) == 0) {
				head[i].push_back(j);
			}
		}
	}
//	cout << 1;
	dp[0][0] = 1;
	
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j < state.size(); j++) {
			if ((state[j] | line[i]) <= line[i]) {
				for (int b : head[j]) {
					dp[i][j] = (dp[i][j] + dp[i - 1][b]) % mod;
				}
			}
		}
	}
	cout << dp[n + 1][0] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

