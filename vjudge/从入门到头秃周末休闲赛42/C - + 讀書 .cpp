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
ll t, n, m, k, ans = 0;
ll a[maxn], b[maxn], suma[maxn], sumb[maxn];

/*
5 5 70
30 5 5 5 5
29 100 100 100 100
*/
void solve()
{
	n = read(), m = read(), k = read();
	int ind_A = 0, ind_B = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		suma[i] = suma[i - 1] + a[i];
	}
	for (int i = 1; i <= m;i++) {
		b[i] = read();
		sumb[i] = sumb[i - 1] + b[i];
	}
	if (suma[n] + sumb[m] <= k) {
		cout << n + m << endl;
		return ;
	}
	ll sy = k;
	for (ll i = 0; i <= n && sy >= 0; i++) {
		sy = k;
		sy -= suma[i];
		if (sy < 0) {
			ans = max(i - 1, ans);continue;
		}
		int l = 0, r = m;
		
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (sumb[mid] <= sy) {
				l = mid;
			} else {
				r = mid - 1;
			}
			
		}
		ans = max(ans, i + l);
		
//		for (ll j = 0; j <= m && sy >= 0; j++) {
//			if (sy - sumb[j] < 0) {
//				ans = max(ans, i + j - 1);break;
//			}
//		}
	} 
	cout << ans << endl;
	// a х╚дц  
//	while (suma[ind_A] <= k && ind_A <= n) {
//		ind_A++;
//	}
//	ind_A--;
//	ll sy = k - suma[ind_A];
//	
//	while () {
//		
//	}
//	
//	while ()
	
	
	
	
//	while (k >= 0) {
//		if (ind_A <= n && ind_B <= m) {
//			if (a[ind_A] <= b[ind_B]) {
//				k -= a[ind_A++];
//			} else {
//				k -= b[ind_B++];
//			}
//		} else {
//			if (ind_A <= n) {
//				k -= a[ind_A++];
//			} else if (ind_B <= m) {
//				k -= b[ind_B++];
//			} else {
//				break;
//			}
//		}
////		if (a[ind_A] <= b[ind_B] && ind_A <= n) {
////			k -= a[ind_A++];
////			
////		} else if (a[ind_A] > b[ind_B] && ind_B <= m){
////			k -= b[ind_B++];
////		}
//		if (k >= 0) ans++;
//	}
//	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

