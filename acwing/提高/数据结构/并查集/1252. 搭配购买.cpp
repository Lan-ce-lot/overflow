#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int MAXN = 1e6 + 5;

using namespace std;
int n, m, w;
int par[MAXN];
int ste[MAXN];
int cost[MAXN];
int dp[MAXN];
int V[MAXN], price[MAXN];
int ans = 0;
int find(int x) {
	if (par[x] != x) {
		return par[x] = find(par[x]);
	} else {
		return par[x];
	}
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
//		cost[b] += cots[a];
		V[b] += V[a];
		price[b] += price[a];
		par[a] = par[b];
	}
}

int main() {
	cin >> n >> m >> w;
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
	// price wealth
	
	for (int i = 1; i <= n; i++) {
		cin >> price[i] >> V[i];
		
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unite(a, b);
	}
	
	
	for (int i = 0; i <= n; i++) {
		if (par[i] == i) 
			for (int j = w; j >= price[i]; j--) 
				dp[j] = max(dp[j], dp[j - price[i]] + V[i]);
	}
	cout << dp[w] << endl;
	
	
	return 0;
}
 
