#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, t, a[maxn], k;

int main() {
	
	cin >> n >> k >> m;
	int ans = (n - k * m);
	if (ans < 0) ans = 0;
	cout << ans << endl;	
	return 0;
}
