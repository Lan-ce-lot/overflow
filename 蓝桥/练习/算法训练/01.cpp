#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

//int dp[5005];
int dp[5005][5005];
int V[5005], W[5005];
int v, n;

int main() {
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> V[i] >> W[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= v; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - V[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - V[i]] + W[i]);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = v; j >= V[i]; j--) {
//			dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
//		}
//	}
	
	cout << dp[n][v] << endl;
	return 0;
} 
