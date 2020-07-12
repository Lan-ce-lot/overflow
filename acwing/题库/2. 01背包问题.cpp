#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int  maxn = 1005;

int n, v;

//int dp[maxn][maxn];
int dp[maxn];
int V[maxn], W[maxn];

int main() {
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> V[i] >> W[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= V[i]; j--) {
			dp[j] = max(dp[j - V[i]] + W[i], dp[j]);
			
		}
	}
	cout << dp[v] << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= v; j++) {
//			if (j >= V[i]) {
//				dp[i][j] = max(dp[i - 1][j - V[i]] + W[i], dp[i - 1][j]);
//			} else {
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//	}
//	cout << dp[n][v] <<endl;
	return 0;
} 
