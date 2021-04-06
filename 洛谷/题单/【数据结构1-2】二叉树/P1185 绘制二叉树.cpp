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
int t, n, m, len, lend2, del[maxn][2];
char line[3 * (1 << 9)][6 * (1 << 9)];

void dfs(int y, int x, int p) {
	line[y][x] = 'o';
	if (y + 1 >= lend2) return ;
	int t = (lend2 - y) / 2 + 1;
	if (!del[p][0]) {
		for (int i = 1; i < t; i++) line[y + i][x - i] = '/';
		dfs(y + t, x - t, p << 1);
	}
	if (!del[p][1]) {
		for (int i = 1; i < t; i++) line[y + i][x + i] = '\\';
		dfs(y + t, x + t, p << 1 | 1);
	}
}

void solve()
{
	cin >> m >> n;
	len = (1 << (m - 2)) * 6 - 1;
	lend2 = len / 2;
	for (int i = 1, a, b; i <= n; i++) {
		cin >> a >> b;
		del[((1 << (a - 2)) + (b - 1) / 2)][(b & 1) ^ 1] = 1;
	}
	memset(line, ' ', sizeof line);
	dfs(0, lend2, 1);
	for (int i = 0; i <= lend2; i++)
		line[i][len] = 0, cout << line[i] << '\n';
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

