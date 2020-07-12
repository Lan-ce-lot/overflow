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
int m, k, x;

ll pre[maxn];
ll a[maxn];

void solve()
{
    cin >> t;

    while (t--) {
        ll sum = 0;
        int ans = 0;
        memset(pre, 0, sizeof pre);
        pre[0] = 0;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
//            debug(pre[i]);
            sum += a[i];
        }

        for (int i = n; i >= 1; i--) {
            if (pre[i] % x) {
//                debug(1);
                ans = max(ans, i);
            }
        }
        for (int i = 0; i <= n; i++) {
            if ((sum - pre[i]) % x) {
//                debug(sum - pre[i] % x);
                ans = max(ans, n - i);
            }

        }
        if (ans == 0) cout << -1 << endl;
        else
        cout << ans << endl;
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

