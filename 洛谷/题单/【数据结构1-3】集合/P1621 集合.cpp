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
int t, n, a, b, p, ans;
int pa[maxn], primes[maxn], cnt, myp[maxn], mcnt;
bool vis[maxn];
void isp(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) primes[cnt++] = i; 
		for (int j = 0; primes[j] <= n / i; j++) {
			vis[primes[j] * i] = 1;
			if (i % primes[j] == 0) break;
		}
	}
}

int find(int x) {
	if (x != pa[x]) {
		return pa[x] = find(pa[x]);
	} else {
		return x;
	}
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	pa[x] = y;
}

void solve()
{
	cin >> a >> b >> p;
	isp(b);
	for (int i = p; i <= b; i++)
		if (!vis[i]) myp[mcnt++] = i;
	for (int i = 1; i <= b; i++)
		pa[i] = i;
	for (int i = 0; i < mcnt; i++) {
		int cc = 0;
		while (cc * myp[i] < a) cc++;
		while ((cc + 1) * myp[i] <= b) {
			Union(cc * myp[i], (cc + 1) * myp[i]);
			cc++;
		}
	}
	for (int i = a; i <= b; i++)
		ans += (pa[i] == i);
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

