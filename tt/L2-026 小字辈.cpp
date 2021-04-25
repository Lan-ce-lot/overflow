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
#define x first
#define y second
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
int t, n;
int root;
int a[maxn];
int h[maxn], e[maxn], ne[maxn], tot;
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}
int hh[maxn], maxx = 0, d[maxn];
void bfs() {
	queue<PII> Q;
	Q.push({root, 1});
	d[root]--;
	hh[root] = 1;
	while (Q.size()) {
		auto top = Q.front();
		Q.pop();
		maxx = max(top.y, maxx);
		for (int i = h[top.x]; ~i; i = ne[i]) {
			Q.push({e[i], top.y + 1});
			hh[e[i]] = top.y + 1;
		}
	}
}
void solve()
{
	cin >> n;
	memset(h, -1, sizeof h);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == -1) root = i, d[i]++;
		else add(a[i], i);
	}
	bfs();
	cout << maxx << endl;
	int ff = 0;
	for (int i = 1; i <= n; i++) {
//		cout << hh[i] << endl;
		
		if (hh[i] == maxx) {if (ff) cout << ' ';
			cout << i;ff++;
		}
	}
	puts("");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

