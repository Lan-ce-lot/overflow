/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

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
int n, m, q;
ll t, r, c, z;
ll a[2005][2005], b[2005][2005];

void inserted(int x1, int y1, int x2, int y2, int k)
{
    b[x1][y1] = (b[x1][y1] + k) % mod;
    b[x1][y2 + 1] = (b[x1][y2 + 1] - k) % mod;
    b[x2 + 1][y1] = (b[x2 + 1][y1] - k) % mod;
    b[x2 + 1][y2 + 1] = (b[x2 + 1][y2 + 1] + k) % mod;
}
ll ans = 0;
void solve()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; i++)
    {
        r = read();
        c = read();
        z = read();
        inserted(1, c, n, c, z);
        inserted(r, 1, r, m, z);
        inserted(r, c, r, c, -z);
    }
    for (int i = 1; i <= n; i++)
    {
//        debug(" ");
        for (int j = 1; j <= m; j++)
        {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
//            printf("%d%c", b[i][j], ((m == j) ? '\n' : ' '));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = (ans + (b[i][j] * (i + j)) % mod) % mod;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

