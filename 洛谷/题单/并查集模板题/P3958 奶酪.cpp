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
ll t, n, h, r;
ll par[maxn];

struct node {
	ll x, y, z;
}N[maxn];

ll dis(node a, node b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.x - b.x) + (a.z - b.z) * (a.z - b.z);
}
ll top[maxn], down[maxn], tot_top = 0, tot_down = 0;

int find(int x) {
	if (x == par[x]) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		par[x] = y;
	}
}

void solve()
{
	t = read();
	while (t--) {
		n = read(), h = read(), r = read();
		for (int i = 0; i <= n; i++) {
			par[i] = i;
		}
		tot_top = 0, tot_down = 0;
		for (int i = 1; i <= n; i++) {
			N[i].x = read(), N[i].y = read(), N[i].z = read();
			if (N[i].z + r >= h) {
				top[tot_top++] = i;
			} 
			if (N[i].z - r <= 0) {
				down[tot_down++] = i;
			}
			for (int j = 1; j <= i; j++) {
				if ((N[i].x - N[j].x) * (N[i].x - N[j].x) + (N[i].y - N[j].y) * (N[i].y - N[j].y) + (N[i].z - N[j].z) * (N[i].z - N[j].z) > 4*r*r) continue;
				if (dis(N[i], N[j]) / 4.0 <=  r * r) {
					unite(i, j);
				}
			}
		}
		
		int ans = 0;
		for (int i = 0; i < tot_top; i++) {
			for (int j = 0; j < tot_down; j++) {
				if (find(top[i]) == find(down[j])) {
					puts("Yes");
					ans = 1;
					break;
				}
			}
			if (ans == 1) break;
		}
		if (!ans) {
			puts("No");
		}
		
		
	}
}

int main()
{

//    freopen("D:/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

