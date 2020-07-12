#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
ll n, m, k;
int main() {
//	stack<ll> S;
	cin >> n >> m >> k;
	n %= m;
	
	while (k - 10 > 0) {
		n *= 1e10;
		n %= m;
		k -= 10;
	}
	
	for (int i = 0; i < k + 2; i++) {
		n*= 10;
		
		if (i >= k - 1) {
			cout << n / m;
		}
		n %= m;
	}
	
	return 0;
}
