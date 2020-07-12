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
const int INF = 0x3f3f3f3f;            //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e7 + 10;
ll mod;
int prime[maxn + 10], cnt;
bool vis[maxn + 10];

bool isprime(ll x)
{
    for (int i = 0; i < cnt && (ll)prime[i] * prime[i] <= x; i++)
        if (x % prime[i] == 0)
            return 0;
    return 1;
}

bool isprime(ll a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			return false;
		}	
	}
	return true;
 } 

void getprime()//埃拉托色尼筛法 
{
    for (int i = 2; i <= maxn; i++)
    {
        if (!vis[i])//非零为素数 
        {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && (ll)i * prime[j] <= maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll mul(ll a,ll b)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res % mod;
}

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main()
{
    int t;
    getprime();
    ll p, q;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &p);
        mod = p;
        q = p - 1;
        while (!isprime(q))
			q--;
        ll ans = p - 1;
        for(ll i = q + 1; i <= p - 1; i++)
            ans = mul(ans, qpow(i, mod - 2));
        printf("%lld\n", ans);
    }
    return 0;
}

