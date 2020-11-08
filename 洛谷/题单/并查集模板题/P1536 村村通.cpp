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
int t, n, m;

int pa[maxn];
int find(int x) {
	if (x == pa[x]) return x;
	else return pa[x] = find(pa[x]);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		pa[x] = y;
	}
}

void solve()
{
	
	while (~scanf("%d", &n)) {
		int ans = 0;
		if (n == 0) {
			return;
		}
		m = read();
		for (int i = 1; i <= n; i++) {
			pa[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			int a = read(), b = read();
			unite(a, b);
		}
		for (int i = 1; i <= n; i++) {
			if (i == pa[i]) ans++;
		}
		cout << ans - 1 << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

