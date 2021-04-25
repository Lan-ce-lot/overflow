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
int t, n, m, p[maxn], d[maxn], a, len, b, l[maxn], r[maxn], lsh[maxn], op[maxn];
char c[10];
int find(int x) {
	if (x != p[x]) {
		int r = find(p[x]);
		d[x] ^= d[p[x]];
		return p[x] = r;
	}
	return x;
}
int M[maxn];

int f(int x) {
	int p = x % 1000003;
	for (;M[p] != x && M[p];) p++;
	return p;
}

int val(int v) {
	return lower_bound(lsh + 1, lsh + 1 + len, v) - lsh;
}
void solve()
{
	cin >> n >> m;
	int ff = 1;
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i];
		r[i]++;
		char c[7];
		cin >> c;
		c[0] == 'e' ? op[i] = 1 : op[i] = 2;
		lsh[i] = l[i], lsh[i + m] = r[i];
	} 
	sort(lsh + 1, lsh + 1 + 2 * m);
	len = unique(lsh + 1, lsh + 1 + 2 * m) - lsh - 1;
	for (int i = 1; i <= len; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		l[i] = val(l[i]), r[i] = val(r[i]);
	}
	for (int i = 1; i <= m; i++) {
		int xx = find(l[i]), yy = find(r[i]);
		if (xx != yy) {
			if (op[i] == 1) p[xx] = yy, d[xx] = (d[l[i]] ^ d[r[i]]);
			else p[xx] = yy, d[xx] = (d[l[i]] ^ d[r[i]] ^ 1);
		} else {
			int v = (d[l[i]] ^ d[r[i]]);
			if (v == 1 && op[i] == 1) {
				cout << i - 1, ff = 0; break; 
			}
			if (v == 0 && op[i] == 2) {
				cout << i - 1, ff = 0; break; 	
			}
		}
	}
	if (ff) cout << m;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

