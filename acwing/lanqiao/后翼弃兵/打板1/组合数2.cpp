#include <iostream>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, m;
const int maxn = 1e7 + 6;
ll f[maxn], inf[maxn];

ll qpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res *= a, res %= mod;
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res;
}

int main() {
	
	
	cin >> n;
	f[0] = 1, inf[0] = 1;
	for (int i = 1; i <= 10000005; i++) {
		f[i] = f[i - 1] * i % mod;
		inf[i] = inf[i - 1] * qpow(i, mod - 2) % mod;
	}
	
	
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << f[a] * inf[a - b] % mod * inf[b] % mod << endl;
	}
	return 0;
}
