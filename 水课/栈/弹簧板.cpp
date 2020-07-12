#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
int n;
int a[1005], b[1005];
int ans = 0x3f3f3f3f;
void dfs(int st, int i) {
	if (st >= ans) return;
	if (i > n) {
//		cout << '=';
		ans = min(st, ans); 
		return;
	}
//	cout << st << '-' << i <<endl;
	dfs(st + 1, i + a[i]);
	dfs(st + 1, i + b[i]);
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	dfs(0, 1);
	cout << ans << '\n';
	return 0;
}
