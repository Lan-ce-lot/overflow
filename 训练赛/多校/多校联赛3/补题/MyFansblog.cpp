#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 10;
ll mod;
int prime[N + 10], cnt;
bool vis[N + 10];
bool is_prime(ll x)
{
    for(int i = 0; i < cnt && (ll)prime[i]*prime[i] <= x; i++)
    {
        if(x % prime[i] == 0)
            return 0;
    }
    return 1;
}
void get_prime()
{
    for(int i = 2; i <= N; i++)
    {
        if(!vis[i])
            prime[cnt++] = i;
        for(int j = 0; j < cnt && (ll)i * prime[j] <= N; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
ll mul(ll a, ll b)
{
    ll res = 0;
    while(b)
    {
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res % mod;
}
ll poww(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int main()
{
    int t;
    get_prime();
    ll p, q;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &p);
        mod = p;
        q = p - 2;
        ll ans = 1;
        for(ll i = 2; !is_prime(q); q--, i++)
            ans = mul(ans, poww(p - i, mod - 2));
        printf("%lld\n", ans);
    }
    return 0;
}
