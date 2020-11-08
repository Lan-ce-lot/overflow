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
int t, n, m, v;
int c[maxn], d[maxn];
ll p[maxn], all_c[maxn], all_d[maxn];
ll dp[maxn];
int find(int x) {
	if (x == p[x]) {
		return x;
	} else {
		
		p[x] = find(p[x]);
		
		return p[x];
	}
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		all_c[y] += all_c[x];
		all_d[y] += all_d[x];
		p[x] = y;
	}
}
int zfp_c[maxn], zfp_d[maxn], tot = 1;
void solve()
{
	
	n = read(), m = read(), v = read();
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		all_c[i] = c[i] = read();
		all_d[i] = d[i] = read();
		
	}
	for (int i = 1; i <= m; i++) {
		int aa = read(), bb = read();
		unite(aa, bb);
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) {
			
			zfp_c[tot] = all_c[i];
			zfp_d[tot] = all_d[i]; 
			tot++;
		} 
	}
	for (int i = 1; i < tot; i++) {
		for (int j = v; j >= zfp_c[i]; j--) {
			dp[j] = max(dp[j], dp[j - zfp_c[i]] + zfp_d[i]);
		}
	}
	cout << dp[v] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

