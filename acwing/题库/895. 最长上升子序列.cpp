#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[1005], dp[1005];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}

