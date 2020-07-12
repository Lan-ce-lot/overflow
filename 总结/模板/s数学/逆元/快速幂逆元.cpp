#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
typedef long long ll;
 
using namespace std;

ll qpow(ll x, ll n, ll p) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = res * x % p;
		}
		x = x * x % p;
		n >>= 1;
	}
	return res;
	
}




int main() {
	
	int a, b, c;
	
	cin >> a >> b >> c;
	for (int i = 1; ; i++) {
//		cout << i <<"->" << endl;
		if (i % 23 == a && i % 233 == b && i % 2333 == c) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
} 
