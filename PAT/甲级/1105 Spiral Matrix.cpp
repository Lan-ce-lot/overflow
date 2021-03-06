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
int t, n, a[maxn];
int ans[1000][1000], N, M;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void dfs(int x, int y, int flag, int step) {

	ans[x][y] = a[step];	
	if (step == n) 
		return;
	int xx = x + dir[flag][0], yy = y + dir[flag][1];
	if (xx >= 1 && xx <= M && yy >= 1 && yy <= N && ans[xx][yy] == 0) {
		dfs(xx, yy, flag, step + 1);
	} else {
		flag++;
		flag %= 4;
		xx = x + dir[flag][0], yy = y + dir[flag][1];
		dfs(xx, yy, flag, step + 1);
	}
}

void solve()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		int i = 1;
		for (; i * i < n; i++);
		N = i;
		for (; N > 0; N--) {
			if (n % N == 0) break; 
		}
		M = n / N;
		if (M < N) {
			swap(M, N);
		}
		sort(a + 1, a + 1 + n, greater<int> ());
		dfs(1, 1, 0, 1);
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				cout << ans[i][j];
				if (j == N) {
					puts("");
				} else {
					cout << ' ';
				}
			}
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

