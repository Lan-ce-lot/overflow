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
int t, n, p;
double sum = 0;
struct node {
	int a, b;
}N[maxn];
ll ans = 0;

bool check(double m) {
	double res = p * m, sum = 0;
	for (int i = 1; i <= n; i++) {
		if (N[i].a * m > N[i].b) {
			sum += (N[i].a * m - N[i].b);
		}
	}
	return res >= sum;
}

void solve()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> N[i].a >> N[i].b;
	}
	// ai
	// p
	// 二分枚举时间
	double l = 0, r = 1e12;
	while (r - l > eps) {
		double m = (l + r) / 2.0;
		if (check(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	if (l >= 1e10) puts("-1");
	else printf("%.10lf\n", l);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

