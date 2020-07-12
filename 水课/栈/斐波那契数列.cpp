#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;

ll num[10005];
ll n, a, b, p, t;
int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return num[n] ? num[n] : num[n] = (fib(n - 1) * a % p + fib(n - 2) * b % p) % p;
}

//ll qpow(ll x, ll n, ll mod) {
//	ll res = 1;
//	
//	while (n > 0) {
//		if (n & 1) {
//			res = res * x % mod;
//		}	
//		x = x * x % mod;
//		n >>= 1;
//	}
//	return res % mod;
//}
ll qpow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	if (n & 1) return x * qpow(x, n - 1, mod) % mod;
	else return qpow(x, n >> 1, mod) * qpow(x, n >> 1, mod) % mod;
}

int main() {
//	string str = 
//	num[1] = 1;
//	num[2] = 1;
//	cin >> n >> a >> b >> p;
//	
//	cout << fib(n) << endl;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> p;
		cout << qpow(a, b, p) << endl;
	}
	return 0;
}

