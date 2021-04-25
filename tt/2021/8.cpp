#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, t, a[maxn], k;
const int INF = 0x3f3f3f3f;
int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int maxx = a[n - 1], minn = a[0], ci = 0, ca = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == maxx) ca++;
		if (a[i] == minn) ci++;
	} 
	cout <<minn << ' ' << ci << endl;
	cout << maxx << ' ' << ca << endl;
	return 0;
}
