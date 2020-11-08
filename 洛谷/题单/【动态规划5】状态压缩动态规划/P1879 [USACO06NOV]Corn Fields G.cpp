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
const int mod = 1e9;
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
// b
const int N = 1 << 13;
int t, n, m;
int g[maxn];
int G[15][15];
int line[15];
vector<int> line_to[15];
int dp[15][N];
//vector <int> status;
vector <int> to[N];
inline bool check(int a) {
	
	return !(a & a << 1);
}


void solve()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
//			G[i][j] = read();
			line[i] += (read() << (j - 1));
//			G[i][j] = read();
//			line[i] = (line[i] << 1) + G[i][j];
		}

//	
	for (int i = 0; i < (1 << m); i++) line_to[0].push_back(i);
//	for (int i = 0; i <= n; i++) cout << line[i] << ' ';puts("");
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (1 << m); j++) {
			if ((j & line[i]) == j && check(j)) {
				line_to[i].push_back(j);	
//				cout << j << ' ';
			}
		}
//		puts("");
	}
	
	for (int i = 0; i < (1 << m); i++) 
    	g[i] = (!(i & (i << 1))) && (!(i & (i >> 1)));
    dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
//		debug(i);
		for (auto it1 : line_to[i]) {
//			cout << it1 << ' ';
			for (auto it2 : line_to[i - 1]) {
				if ((it1 & it2) == 0) {
					dp[i][it1] = (dp[i][it1] + dp[i - 1][it2]) % mod;
				}
			}
		}
	}

	
	int ans = 0;
	for (int i = 0; i < (1 << m); i++) {
		ans = (ans + dp[n][i]) % mod;
	}
	printf("%d\n", ans);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

