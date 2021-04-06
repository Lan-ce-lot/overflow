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
ll t, n, c, a[maxn], ans;

void solve()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	/*
	A - B = C
	A = B + C 
	*/
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = l + r >> 1;
			if (a[mid] + c >= a[i])
				r = mid;
			else
				l = mid + 1;
		}
		int l1 = 1, r1 = i;
		while (l1 < r1) {
			int mid = l1 + r1 + 1 >> 1;
			if (a[mid] + c <= a[i]) l1 = mid;
			else r1 = mid - 1;
		}
//		int l = lower_bound(a + 1, a + i + 1, a[i] - c) - a, l1 = upper_bound(a + 1, a + i + 1, a[i] - c) - a;
//		l1--;
//		debug(l);
//		debug(l1);
		if (a[l] + c == a[i] && a[l1] + c == a[i] && l != i) ans += (l1 - l + 1);
	}
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

