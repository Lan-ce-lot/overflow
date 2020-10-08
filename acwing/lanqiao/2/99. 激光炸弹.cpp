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
int t, cnt, n, m, res = 0;
//int a[maxn];
int pre[5010][5010];
//int G[5010][5010]; 
void solve()
{
	cnt = read(), t = read();
	t = min(5001, t);
	n = m = t;
	for (int i = 0; i < cnt; i++) {
		int x = read() + 1, y = read() + 1;
		pre[x][y] += read();
		n = max(n, x), m = max(m, y);
	}
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	}
	
	for (int i = t; i <= n; i++) {
		for (int j = t; j <= m; j++) {
			res = max(res, pre[i][j] - pre[i][j - t] - pre[i - t][j] + pre[i - t][j - t]); 
		}
	}
	cout << res << endl;
	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << G[i][j] << ' ';
//		}puts("");
//	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

