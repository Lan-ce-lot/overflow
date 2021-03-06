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
//一个正奇数(除1外)与两个和等于此正奇数平方的连续正整数是一组勾股数。
//
//设n为一正奇数(n≠1)，那么以n为最小值的一组勾股数可以是:n，(n*n-1)/2，(n*n+1)/2。
void solve()
{
	t = read();
	while (t--) {
		n = read();
		// 二分找 (a*a+1)/2 <= n
//		cout << n / 2 - 1 << endl;
//		n = 1;
		ll l = 0, r = n;
		while (l < r) {
			ll mid = l + r + 1 >> 1;
			if ((mid * mid + 1) / 2 <= n) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		if (l % 2 == 0) {
			l--;
		}
		cout << l / 2 << endl;
//		cout << l / 2<< endl; 
//		for (int a = 1; a <= n - 2; a++) {
//			for (int b = a; b <= n - 1; b++) {
//				for (int c = b; c <= n; c++) {
//					if (a * a + b * b == c * c && c == a * a - b) {
//						cout << a << ' ' << b << ' ' << c << endl;
//					}
//				}
//			}
//		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

