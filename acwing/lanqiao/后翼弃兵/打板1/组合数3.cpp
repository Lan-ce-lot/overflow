
#include <iostream>

using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
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
ll C(ll a, ll b) {
	ll res = 1;
	for (int i = 1, j = a; i <= b; i++, j--) {
		res = res * j % mod;
		res = res * qpow(i, mod - 2) % mod;
	}
	return res;
}

ll LC(ll a, ll b) {
	if (a < mod && b < mod) return C(a, b);
	return C(a % mod, b % mod) * LC(a / mod, b / mod) % mod;
	
}

int main() {
	
	
	cin >> n;
	while (n--) {
		ll a, b;
		cin >> a >> b >> mod;
		cout << LC(a, b) << endl;
	}
	return 0;
}
