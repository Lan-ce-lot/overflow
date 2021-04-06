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
int t, n, m, ans = 0;
char M[55][55];
int hq[55][55], bq[55][55];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int vis[55][55], cnt = 1, sum_q, sum = 0;
int q[55][55], st[55][55];
bool check(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bjq(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if(check(xx, yy) && M[xx][yy] == '.' && st[xx][yy] == 0) {
			st[xx][yy] = 1;
			q[xx][yy] = 1;
			sum++;
		}
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if(check(xx, yy) && M[xx][yy] == '*' && vis[xx][yy] == 0) {
			vis[xx][yy] = 1;
			bjq(xx, yy);
		}
	}
}
void getq(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if(check(xx, yy) && M[xx][yy] == '.' &&  q[xx][yy] == 0 && st[xx][yy] == 0) {
			st[xx][yy] = 1;
			sum_q++;
		}
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if(check(xx, yy) && M[xx][yy] == '.' && q[xx][yy] == 1 && vis[xx][yy] == 0) {
			vis[xx][yy] = 1;
			getq(xx, yy);
		}
	}
}
void solve()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cnt = 1;
		ans = 0, sum_q = 0, sum = 0;
		memset(q, 0, sizeof q);
		memset(st, 0, sizeof st);
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++)
			cin >> M[i] + 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (M[i][j] == '*' && vis[i][j] == 0) {
					vis[i][j] = 1;
					memset(st, 0, sizeof st);
					
					bjq(i, j);
				}
			}
		}
		if (sum == 0) {
			puts("NO");
			continue;
		}
		memset(st, 0, sizeof st);
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (M[i][j] == '.' && q[i][j] == 1 && vis[i][j] == 0) {
					memset(st, 0, sizeof st);
					vis[i][j] = 1;
					sum_q = 0;
					getq(i, j);
//					debug(sum_q);
					if (sum_q == 0) ans++;
				}

			}
		}
		
		
		if (ans <= 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

