#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, t, a[maxn];
double k;
const int INF = 0x3f3f3f3f;
int main() {
	double minn = INF;
	cin >> n >> m;
	for (int i = 0; i < n ;i++) {
		cin >> k;
		if (k < m) {
			minn = k;
			cout << "On Sale! ";
			printf("%.1lf\n", minn);
		}
	}
	
	return 0;
}
