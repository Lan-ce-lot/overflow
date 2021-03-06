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
int t, n, a[maxn];
set<int> S;
int z_l[maxn], z_l_min[maxn], l_index = 0;
int z_r[maxn], z_r_max[maxn], r_index = 0;
void solve()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			a[i] = read(); 
		}
		l_index = n;
		a[0] = z_r_max[0] = -INF, a[n + 1] = z_l_min[n + 1] = INF;
		for (int i = n; i > 0; i--) {
			z_l_min[i] = min(a[i + 1], z_l_min[i + 1]);
		}
		for (int i = 1; i <= n; i++) {
			z_r_max[i] = max(a[i - 1], z_r_max[i - 1]); 
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] > z_r_max[i] && a[i] < z_l_min[i]) {
				S.insert(a[i]);
			}
		}
		cout << S.size() << endl;
		int j = 0;
		for (auto it : S) {
			if (j++) {
				cout << ' ' << it;
			} else {
				cout << it;
			}
		}
		puts("");
	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

