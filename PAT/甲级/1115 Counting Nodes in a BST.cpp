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
int t, n;
struct node {
	int l, r, e;
}T[maxn];
int dep[maxn], maxdep = -INF, ind = 1, a[maxn];
void build(int u, int e, int fa, int f, int d) {
	if (u == 0) {
		if (f) {
			T[ind].e = e;
			T[fa].r = ind++;
		} else {
			T[ind].e = e;
			T[fa].l = ind++;
		}
		dep[d]++;
		maxdep = max(d, maxdep);
		return;
	}
	if (e <= T[u].e) {
		build(T[u].l, e, u, 0, d + 1);
	} else {
		build(T[u].r, e, u, 1, d + 1);
	}
}
void solve()
{
	n = read();
	for (int i = 0; i < n; i++) {
		a[i] = read(); 
		if (i == 0) {
			ind++;
			dep[1] = 1;
			maxdep = 1;
			T[1].e = a[i]; 
		} else {
			build(1, a[i], 1, 0, 1);
		}
	}
	cout << dep[maxdep] << " + " << dep[maxdep - 1] << " = " << dep[maxdep] + dep[maxdep - 1] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

