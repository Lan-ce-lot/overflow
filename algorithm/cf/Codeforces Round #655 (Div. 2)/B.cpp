#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

int n, m, t, a, b;

ll LCM(int a, int b) {
	return 1ll * a / __gcd(a, b) * b;
}

bool is_prime(int x) {
	for (int i = 0; i < n; i++) {
		
	}
}
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}
int main() {
	cin >> t;
	n = 1;
	while (t--) {
//		n++;
//		cout << n << endl;
		cin >> n;
		int tem = 1;
		vector<int> res = get_divisors(n);
		if (n % 2 == 0) {
			cout << n / 2 << ' ' << n / 2 << endl;
		} else {
			for (auto i : res) {
				if (i <= n / 2) {
					tem = i;
				}
			}
//			for (int i = 1; i * i <= n; i++) {
//				if (n % i == 0) tem = i;
//			}
			cout << tem << ' ' << n - tem << endl;
//			cout << n / 2 << ' ' << n / 2 + 1 << endl;
		}
//		for (int i = 1; i <= n / 2; i++) {
//			cout << i << ' ' << n - i << ' ' << LCM(i, n - i) << endl;
//		}
//		puts("");
//		cout << 
	}
	
	return 0;
} 
