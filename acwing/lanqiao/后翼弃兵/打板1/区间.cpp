#include <bits/stdc++.h>

using namespace std;
int n, a[10005], f[1005][1005], s[1005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	
//	memset(f, 0x3f, sizeof f);
	for (int len = 2; len <= n ; len ++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			f[l][r] = 0x3f3f3f3f;
			for (int k = l; k < r; k++) {
				f[l][r] = min(f[l][r], (f[l][k] + f[k + 1][r] + s[r] - s[l - 1]));
			} 
		}
	}
	cout << f[1][n] << endl;
	
	return 0;
}
