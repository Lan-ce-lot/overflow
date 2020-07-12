#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 1e4 + 5;

using namespace std;
int n, v;
int V[maxn], W[maxn], con[maxn];
int dp[maxn];
int main() {
	
	cin >> n >> v;
	
	int con = 1;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;
		int k = 1;
		while (c >= k) {
			V[con] = a * k;
			W[con++] = b * k;
			c -= k;
			k *= 2;
		}
		if (c > 0) {
			V[con] = a * c;
			W[con++] = b * c;
			c = 0;
		}
		
//		cin >> V[i] >> W[i] >> con[i];
	}
	for (int i = 1; i < con; i++) {
		for (int j = v; j >= V[i]; j--) {
			dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
		}
	}
	cout << dp[v] << endl;
	
	// ps
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= v; j++) {
//			for (int k = 0; k <= con[i] && k * V[i] <= j; k++) {
//				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * V[i]] + k * W[i]);
//			}
//		}
//	}
	
	
//	cout << dp[n][v] << endl;
	
	
	
	return 0;
}
