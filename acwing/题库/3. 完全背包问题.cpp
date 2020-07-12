#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 1e4 + 5;

using namespace std;
int n, v;
int V[maxn], W[maxn];
//int dp[maxn][maxn];
int dp[maxn]; 
int main() {
	
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> V[i] >> W[i];
	} 
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= v; j++) {
//			for (int k = 0; k * V[i] <= j; k++) {
//				dp[i][j] = max(dp[i - 1][j - k * V[i]] + W[i] * k, dp[i][j]);
//			}
//		}
//	}
//	for (int i = 1;  i <= n; i++) {
//		for (int j = 1; j <= v; j++) {
//			dp[i][j] = dp[i - 1][j];
//			if (j >= V[i])
//				dp[i][j] = max(dp[i][j], dp[i][j - V[i]] + W[i]);
//		}
//	}

	for (int i = 1; i <= n; i++) {
		for (int j = V[i]; j <= v; j++) {
			dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
		}
	}
	cout << dp[v] <<endl;
//	cout << dp[n][v] << endl;
	return 0;
} 
