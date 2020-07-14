#include<bits/stdc++.h>

using namespace std;
const int maxn = 5005;
typedef long long ll;
int n, m, k;

int G[5005][5005];
int dp[5005][5005];
int q[maxn];
int main() {
	
	cin >> n >> m >> k;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!G[i][j]) {
				for (int k = 0; k * i <= n && k * j <= m; k++) {
					G[k * i][k * j] = i * j * k;
				}
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << G[i][j] << ' ';
//		}
//		puts("");
//	}
	
	for (int j = 1; j <= m; j++) {
		int l = 1, r = 0;
		for (int i = 1; i <= n; i++) {
			if (l <= r && q[l] < i - k + 1) l++;
			while (l <= r && G[i][j] > G[q[r]][j]) r--;
			q[++r] = i;
//			cout << q[l] << endl;
			dp[i][j] = G[q[l]][j];
		}
	}
	memset(q, 0, sizeof q);
	for (int i = k; i <= n; i++) {
		int l = 1, r = 0;
		for (int j = 1 ; j <= m; j++) {
			if (l <= r && q[l] < j - k + 1) l++;
			while (l <= r && dp[i][j] > dp[i][q[r]]) r--;
			q[++r] = j;
//			dp[i][j] = q[l];
			if (j >= k) {
				ans += dp[i][q[l]];
//				cout << dp[i][q[l]] << endl; 
			}
//				cout << "*" << endl;
		}
	}
	cout << ans << endl;
	
	return 0;
}
