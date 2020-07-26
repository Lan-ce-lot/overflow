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
const int N = 12, M = 1 << 10, K = 110;
ll dp[N][K][M];
vector<int> state;
vector<int> head[M];
int cnt[M];

inline int lowbit(int x) {
	return x & -x;
}
//int count(int n1) {
////	int res = 0;
////	while (n) {
////		n -= lowbit(n);
////		res++;
////	}
////	int i;
////	for (i = 0; n; i++) n -= lowbit(n);
////	return i;
//	int res = 0;
//	for (int i = 0; i < n; i++) res += n1 >> i & 1;
//	return res;
//}
int count(int state)
{
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += state >> i & 1;
    return res;
}

//bool check(int s) {
//	for (int i = 0; i < n; i++) {
//		if ((s >> i & 1) && (s >> i + 1 & 1)) {
//			return 0;
//		}
//	} 
//	return 1;
//} 
bool check(int state)
{
    for (int i = 0; i < n; i ++ )
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < 1 << n; i++) {
		if (check(i)) {
			state.push_back(i);
			cnt[i] = count(i);
		}
	}
	
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			int a = state[i], b = state[j];
			if ((a & b) == 0 && check(a | b)) {
				head[i].push_back(j);
			}
		}
	} 
	
	dp[0][0][0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= m; j++) {
			for (int a = 0; a < state.size(); a++) {
				for (int b : head[a]) {
					int c = cnt[state[a]];
					if (j >= c) {
						dp[i][j][a] += dp[i - 1][j - c][b];
					}
				}
			}
		}
	}
	cout << dp[n + 1][m][0] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

