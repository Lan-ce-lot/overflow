#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

const int maxn = 1000 + 5;

using namespace std;
int n;
int num[maxn][maxn];
int dp[maxn][maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			
			cin >> num[i][j];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			dp[i][j] = num[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	cout << dp[1][1] << endl;
	return 0;
}
