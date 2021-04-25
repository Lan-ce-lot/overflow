#include <iostream>

using namespace std;
typedef long long ll;
ll L, n, m, a[50005];
const int INF = 0x3f3f3f3f;
bool check(int x) {
	int tot = 0, s = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] - s < x) {
			tot++;
		} else {
			s = a[i];
		}
	}
	return tot <= m;
	
}
int main() {
	cin >> L >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = L;
	int l = 0, r = INF;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
 	return 0;
}
