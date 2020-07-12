/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;


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

ll t, n, k, m, ans = -1,temp = 0;
int a[maxn];
int main()
{
    t = read();
    while (t--)
    {
        k = read();
        m = read();
        ans = -1;
        for (ll i = 1; i < 500; i++)//ans=n;
        {
            int m1 = m;
            n = (k ^ i);
            if (n <= 0)
            {
                temp = 0;
            }
            else
            {
                for(ll j  = n + 1; ; j++)
                {
                    if (__gcd(j, n) == 1)
                    {
                        m1 --;
                        if (!m1)
                        {
                            temp = j - n;
                            break;
                        }
                    }
                }
            }
            if (temp == i)
            {
                if (ans == -1 || ans > k ^ i)
                    ans = k ^ i;
            }
        }
        printf("%lld", ans);
    }
    return 0;
}
