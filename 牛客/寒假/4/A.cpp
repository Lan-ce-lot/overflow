/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:第四场2月11日：搜索，简单STL，前缀和，二分搜索，位运算，贪心，分治，树
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
typedef unsigned long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 998244353;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 200005;

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
int t, n, con = 0;
ll k, a[maxn];
ll sum[maxn];
ll p[maxn];
/*
9 3
1 2 3 0 4 6 8 0 100
*/
int extend_gcd(ll a,ll b,ll &x,ll &y)
{
    ll d;
    if(b==0)
    {x=1; y=0;return a;}
    d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll mod_reverse(ll a, ll p)
{
ll x,y;
ll d=extend_gcd(a,p,x,y);
if(d==1)
return (x%mod+mod)%mod;
else
return -1;
}
ll qkp(ll a) {
    ll rt=1,b=mod-2;
    while(b) {
        if(b&1) rt=rt*a%mod;
        b>>=1; a=a*a%mod;
    }
    return rt;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    ll ans = 0;
    for (int i = 1; i <= n - k + 1; )
    {
        int j = 1;
        while (a[i] == 0 && i <= n)
            i++;
        while (a[i] && i <= n)
        {
            p[j++] = a[i++];
        }
        j--;
        if (j >= k)
        {
            memset(sum + 1, 0, j + 1);
            sum[0] = 1;
            for (int k1 = 1; k1 <= j; k1++)
            {
                sum[k1] = sum[k1 - 1] * p[k1] % mod;
//                cout << sum[k1] << ' ';
            }

            for (int k1 = 1; k1 <= j - k + 1; k1++)
            {
                ll tp = qkp(sum[k1 - 1]);
                ans = max(ans, (sum[k1 + k - 1] * tp) % mod);
            }
        }
    }
    cout << ans <<endl;
}
/*
9 3
1 2 3 0 4 6 8 0 100
*/
int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

