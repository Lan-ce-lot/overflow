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
int t, n, p[maxn], d[maxn], la[maxn], m;


int find(int x) {
	if (x == p[x] || p[p[x]] == p[x]) {
		return p[x];
	}		
	int r = find(p[x]);
	d[x] += d[p[x]];
	p[x] = r;
	return r;
	
}
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b = find(b), c = find(c);
			if (b != c)
				p[b] = c, d[b] = d[b] - d[c];
		} else {
			b = find(b);
			d[b] += c;
		}
	}
	
	
	for (int i = 1; i <= n; i ++) {
		if (i == find(i)) cout << d[i] << ' ';
		else cout << d[i] + d[find(i)] << ' ';
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

