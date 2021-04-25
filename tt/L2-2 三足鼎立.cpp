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
ll t, n, m, a[maxn], ans = 0;

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	a[0] = -INF * 1000, a[n + 1] = INF * 1000;
	for (int i = 1; i <= n; i++) {
		ll tmp = m + a[i], tmp2 = abs(a[i] - m);
		int xj, sj;
		int l = 1, r = n;
		// 2 16 27 35 42 51 92
		while (l < r) {
			int mid = l + r >> 1;
			if (a[mid] > tmp2) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		xj = l;
		// zuida
		l = 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (a[mid] >= tmp) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
//		sj = l;
//		debug(tmp2);
//		debug(tmp);
//		cout << xj << ' ' << sj << endl;
//		cout << a[xj] << ' ' << a[sj] << endl;
//		if (xj > sj) continue;
//		ans += (sj - xj);	
		
		int p=lower_bound(a+1+i,a+1+n,a[i]+m)-(a+1+i); 
        int q=upper_bound(a+1+i,a+1+n,abs(a[i]-m))-(a+1+i);
//        cout << p << ' ' << q << endl;
        ans += p - q;
//        cnt+=p-q;
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

