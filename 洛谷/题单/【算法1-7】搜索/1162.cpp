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
const int N = 35;
int M[N][N];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && M[xx][yy] == 0) {
			M[xx][yy] = 2;
			dfs(xx, yy);
		}
	}
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> M[i][j];
	for (int i = 0; i <= n + 1; i++) {
		dfs(i, 0);
		dfs(i, n + 1);
		dfs(0, i);
		dfs(n + 1, i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (M[i][j] == 0)
				M[i][j] = 2;
			else if (M[i][j] == 2) M[i][j] = 0;
			cout << M[i][j] << ' ';
		}puts("");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

