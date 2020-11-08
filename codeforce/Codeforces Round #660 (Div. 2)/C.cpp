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
ll t, n;
void get_near() {
	for (int i = 0; i <= n; i++) {
	}
} 
void solve()
{
	cin >> t;
	while (t--) {
		n = read();
		// 6, 8, 10
		// 15
		if (n <= 6 + 10 + 14) {
			puts("NO");
		} else {
//			ll tem = n - ((6 + 10 + 14));
			puts("YES");
			if (n == 36) {
				cout << 5 << ' ' << 6 << ' ' << 10 << ' ' <<  15 << endl;
				continue;
			} else if (n == 40) {
				cout << 6 << ' ' << 14 << ' ' << 15 << ' ' << 5 << endl;
				continue;				
			} else if (n == 44) {
				puts("6 7 10 21");
//				cout << 6 << ' ' << 14 << ' ' << 15 << ' ' << 9 << endl;
				continue;				
			}
			
//			if ()
			cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - (6 + 10 + 14) << endl; 
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

