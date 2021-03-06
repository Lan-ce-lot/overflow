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
int t, n, u, r, d, l;
int rl[4], crl[4];
void solve()
{
	t = read();
	while (t--) {
		n = read(), u = read(), r = read(), d = read(), l = read();
//		int r_u = 0, r_r = 0, r_d = 0, r_l = 0;
		for (int i = 0; i < 4; i++) rl[i] = 0;
		rl[0] = u, rl[1] = r, rl[2] = d, rl[3] = l;
		for (int i = 0; i < 4; i++) crl[i] = 0;
		int sum = u + r + d + l;
		// n-1 n-1
		// n-1 n-2 n-1 n-2 可以 
		// 3
		// 1 1 1 1
		// 2 2 1 1
		// 2 
		// n 
		//  
		// 0 1 2 3 0
		// 有贡献， 没贡献 
		if (sum > 4 * n || u > n || r > n || d > n || l > n) {
			puts("NO");
			continue;
		} else {
			if (u <= n - 2 && r <= n - 2 && d <= n - 2 && l <= n - 2) {
				puts("YES");
				continue;
			} else {
				// n n n n
				// 1 1 1 1
				// n n n-1 n-1 
				// 2 2 1 1
				// n n-1 n-1 n-2 ->2
				// 2 1 1 0
				// n-1 n-1 n-1 n-1 ->2
				// 1 1 1 1
				// n-1 n-1 n-2 n-2 ->3
				// 1 1 0 0
				int co_0 = 0;
				int index[5];
				for (int i = 0; i < 4; i++) {
					if (rl[i] == 0) {
						index[co_0] = i;
						co_0++;
						
					}
				}
				if (rl[0] <= n && rl[0] >= 1
				 && rl[1] <= n && rl[1] >= 1
				 && rl[2] <= n && rl[2] >= 1 
				 && rl[3] <= n && rl[3] >= 1) {
					puts("YES");
					continue;
				} else if (co_0 == 1) {
					int pos = index[0];
					if (rl[(pos + 2) % 4] <= n && rl[(pos + 2) % 4] >= 2
					 && rl[(pos + 1) % 4] <= n - 1 && rl[(pos + 1) % 4] >= 1
					 && rl[(pos + 5) % 4] <= n - 1 && rl[(pos + 5) % 4] >= 1
					) {
						puts("YES");
						continue;
					}
				} else if (co_0 == 2) {
					if (index[0] + 1 == index[1]) {
						int pos = index[0];
						// 
						// 0 0 1 1
						
					if (rl[(pos + 2) % 4] <= n - 1 && rl[(pos + 2) % 4] >= 1
					 && rl[(pos + 1) % 4] <= n - 2 && rl[(pos + 1) % 4] >= 0
					 && rl[(pos + 5) % 4] <= n - 1 && rl[(pos + 5) % 4] >= 1
					) {
						puts("YES");
						continue;
					}
						
					} else {
						puts("NO");
						continue;
					}
				}
				puts("NO");
			}
		}
		// n n n n
		// 0 0 0 0
		// n-1 
		// n-2 
		// 0 <= sum <= 4 * n
		// 0 <= n
		// if n - 1
		
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

