#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> R;
		for (int i = 1; i <= n / i; i++) {
			if (n % i == 0) {
				R.push_back(i);
				if (i != n / i) R.push_back(n / i);
			}
		}
		sort(R.begin(), R.end()); 
		for (auto i : R) cout << i << ' ';	
		puts("");
	}
	return 0;
}
