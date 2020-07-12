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
int t, n, m, a[maxn], con;
int ans = 0;
bool ff[maxn];
bool vis[maxn];
bool is_prime(int n)
{
    if (n == 1) return 0;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void dfs(int step, int idx, int sum)
{
    if (step == m)
    {
//        sum += a[idx];
        if (is_prime(sum))
        {
            debug(sum);
            ans++;
        }

        return;
    }
    for (int i = idx; i < n; i++)
    {
        dfs(step + 1, i + 1, sum + a[i]);
    }

//    for (int i = 0; i < n; i++)
//    {
//        if (!vis[i])
//        {
//            vis[i] = 1;
//            dfs(step + 1, i + 1, sum + a[i]);
//            vis[i] = 0;
//        }
//    }

}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        a[i] = read();
    dfs(0, 0, 0);
    cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

