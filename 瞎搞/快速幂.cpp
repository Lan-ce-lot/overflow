#include <cstdio>
typedef long long ll;
ll qpow(ll a, ll b, ll m)
{
	ll ret = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)
			ret = ret * a % m;
		a = a * a % m;
	}
	return ret;
}
int main()
{
	ll n, m, k, x;
	scanf("%lld%lld%lld%lld", &n, &m, &k, &x);
	printf("%lld\n", (x % n + qpow(10, k, n) * m % n) % n);
	return 0;
}
