#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e4 + 5;

int n, v;
int V[maxn], W[maxn];
int dp[maxn];
int main() {
	cin >> n >> v;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		
		for (int j = 0; j < s; j++) {
			cin >> V[j] >> W[j];
		}
		for (int j = v; j >= 0; j--) {
			for (int k = 0; k < s; k++) {
				if (j >= V[k])
				dp[j] = max(dp[j], dp[j - V[k]] + W[k]);
			}
		}
		
	}
	cout << dp[v] << endl;
	
	
	
	return 0;
}
