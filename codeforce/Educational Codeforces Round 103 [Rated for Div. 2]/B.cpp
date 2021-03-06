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
ll a[maxn], sum[maxn], k;
void solve()
{
	t  = read();
	while (t--) {
		ll ans = 0;
		n = read(), k = read();
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			sum[i] += sum[i - 1] + a[i];
		}
		ll summ = 0, tmp;
		for (int i = 2; i <= n; i++) {
			if (a[i] * 100 > (summ + a[i - 1]) * k) {
//				tmp = (100 * a[i] - summ * k) / k;// 取整的问题

				tmp = (100 * a[i] - summ * k) / k + ( (100 * a[i] - summ * k) % k == 0 ? 0 : 1);
				ans += tmp - a[i - 1];
				a[i - 1] = tmp;

			}
			summ += a[i - 1];
		}
		cout << ans << endl;
	}
}
/*
100
4 1
20100 1 1 20100
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

