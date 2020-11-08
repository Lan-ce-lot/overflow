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
int t, n, ans = 0;

void solve()
{
	t = read();
	while (t--) {
		ans = 0;
		n = read();
		int tem = 0;
		int flag = 0;
		for (int i = 0; i * 3 <= n; i++) {
			tem = 0;
			if (flag == 1) break;
			for (int j = 0; j * 5 <= n; j++) {
				if (flag == 1) break;
				for (int k = 0; k * 7 <= n; k++) {
					tem = i * 3 + j * 5 + k * 7;
					if (tem > n) continue;
					if (tem == n) {
						cout << i << ' ' << j << ' ' << k << endl;
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag == 0) cout << -1 << endl;
//		if (n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 8 == 0 || n % 13 == 0) {
//			if (n % 3 == 0) {
//				cout << n / 3 << ' ' << 0 << ' ' << 0 << endl;
//			} else if (n % 5 == 0) {
//				cout << 0 << ' ' << n / 5 << ' ' << 0 << endl;
//			} else if (n % 7 == 0) {
//				cout << 0 << ' ' << 0 << ' ' << n / 7 << endl;
//			} else if (n % 8 == 0) {
//				cout << n / 8 << ' ' << n / 8 << ' ' << 0 << endl;
//			}
//		} else {
//			cout << -1 << endl;
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

