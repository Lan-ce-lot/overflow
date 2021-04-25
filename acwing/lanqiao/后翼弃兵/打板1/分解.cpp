#include <iostream>
#include <vector>
using namespace std;
int t, n;
typedef pair<int, int> PII;
vector<PII> A;


int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		A.clear();
		for (int i = 2; i <= n / i; i++) {
			if (n % i == 0) {
				int s = 0;
				while (n % i == 0) {
					n /= i, s++;
				}
				A.push_back({i, s});
			}
		}
		if (n > 1) A.push_back({n, 1});
		for (auto it : A) cout << it.first << ' ' << it.second << endl;
		puts("");
	}
}
