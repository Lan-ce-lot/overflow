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
ll t, n, f[2][1 << 11][1 << 11], s[1 << 11], cnt[1 << 11], m;
vector<int> S;
char maze[1005][1005];
/*
用本行和上一行一起来维护当前状态
 
*/
bool check(int x) {
	for (int i = 0; i < m; i++) 
		if ((x >> i & 1) && ((x >> i + 1 & 1) || (x >> i + 2 & 1))) return 0;
	return 1;
	
}
int lowbit(int x) {
	return x & -x;
}
int cnted(int s) {
	int res = 0;
	while (s > 0) {
		res ++;
		s -= lowbit(s);
	} return res;
}
void solve()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		scanf("%s", maze[i] + 1);
	int maxx = 1 << m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (maze[i][j] == 'P')
				s[i] = (s[i] << 1) + 1;
			else s[i] = (s[i] << 1);
				
	for (int i = 0; i < maxx; i++)
		if (check(i)) S.push_back(i), cnt[i] = cnted(i);
			
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < S.size(); j++) 
			for (int k = 0; k < S.size(); k++)
					for (int u = 0; u < S.size(); u++) {
						int a = S[j], b = S[k], c = S[u];
						if (a & b | a & b | b & c) continue;
						if (((s[i] | b) > s[i]) | ((s[i - 1] | a) > s[i - 1])) continue;
						f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
					}
					
	int res = 0;
    for (int i = 0; i < S.size(); i ++ )
        for (int j = 0; j < S.size(); j ++ )
            res = max(res * 1ll, f[n & 1][i][j]);
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

