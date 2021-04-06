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
char M[105][102], ans[105][105];
// yizhong
// 7
bool check[105][105];
int dir[8][2] = 
{1, 0, 0, 1, -1, 0, 0, -1,
 1, 1, 1, -1, -1, -1, -1, 1};
// izhong
char tar[15] = " yizhong";
bool dfs(int x, int y, int now, int f) {
	if (now == 7) return (tar[now] == M[x][y] ? ans[x][y] = M[x][y], 1: 0);
	if (tar[now] != M[x][y]) return 0;
	return dfs(x + dir[f][0], y + dir[f][1], now + 1, f) ? ans[x][y] = M[x][y], 1: 0;
}
void solve()
{
	cin >> n;
//	strcpy(" yizhong", tar);
	memset(ans, '*', sizeof ans);
//debug(1111);
	for (int i = 1; i <= n; i++)
		cin >> M[i] + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (M[i][j] == 'y') for (int k = 0; k < 8; k++) dfs(i, j, 1, k);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ans[i][j];
		}
		puts("");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

