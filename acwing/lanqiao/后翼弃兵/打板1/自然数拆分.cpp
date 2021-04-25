#include <bits/stdc++.h>

using namespace std;
int n, a[100005];
void dfs(int sum, int st, int now) {
	if (sum > n) return;
	if (sum == n) {
		
		for (int i = 1; i < now; i++) cout << a[i] << (i == now - 1 ? '\n' : '+');
		
		return ;
	}
	
	for (int i = st; i < n; i++) {
		a[now] = i;
		dfs(sum + i, i, now + 1);
		a[now] = 0;
	}
	
}
int main() {
	cin >> n;
	
	dfs(0, 1, 1);
	
	return 0;
}
