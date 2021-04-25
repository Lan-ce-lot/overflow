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
int t, n, a, b;
int pa[maxn], d[maxn], si[maxn];

int find(int x) {
	if (x != pa[x]) {
		int root = find(pa[x]);
		d[x] += d[pa[x]];
		return pa[x] = root;
	}
	return x;
}
void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		pa[x] = y;
		d[x] = si[y];
		si[y] += si[x];
	}
}

void solve()
{
	cin >> n;
	char c;
	for (int i = 1; i <= 30000; i++) {
		pa[i] = i;
		si[i] = 1;
		d[i] = 0;
	}
	for (int i = 1 ; i <= n; i++) {
		cin >> c >> a >> b;
		if (c == 'M') {
			Union(a, b);
		} else {
			if (find(a) != find(b))
				cout << -1 << endl;
			else
				cout << abs(d[a] - d[b]) - 1 << endl;
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

