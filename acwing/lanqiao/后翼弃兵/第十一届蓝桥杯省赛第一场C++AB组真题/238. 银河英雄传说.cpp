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
int t, n, p[maxn], d[maxn], all[maxn];

int find(int x) {
	if (x != p[x]) {
		int r = find(p[x]);
		d[x] += d[p[x]];
		return p[x] = r;
	}
	return p[x];
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) p[i] = i, all[i] = 1; 
	for (int i = 1; i <= n; i++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == 'M') {
			a = find(a), b = find(b);
			if (a != b) {
				p[a] = b;
				d[a] = all[b];
				all[b] += all[a];
				all[a] = 0;
			}
		} else {
			if (find(b) == find(a)) {
				cout << abs(d[a] - d[b]) - 1 << endl;
			} else {
				puts("-1");
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

