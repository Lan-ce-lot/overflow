#include <bits/stdc++.h>

using namespace std;
int n;
struct node {
	double x, y;
}G[100005];
double f[16][1 << 16];
double dis(node A, node B) {
	return sqrt((A.x - B.x) * (A.x - B.x) - (A.y - B.y) * (A.y - B.y));
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++ ) {
		cin >> G[i].x >> G[i].y;
	}
	int all = (1 << n) - 1;
	memset(f, 127, sizeof f);
	for (int i = 1; i <= all; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i & (1 << (j - 1))) == 0) continue;
			if(i == (1 << (j - 1))) {f[j][i] = 0;continue;}
			for (int k = 1; k <= n; k++) {
				if ((i & (1 << (k - 1))) == 0 || k == j) continue;
				f[j][i] = min(f[j][i], f[k][i ^ (1 << (j - 1))] + dis(G[j], G[k]));
			}
		}
	}
	double ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		ans = min(f[i][all] + dis(G[i], {0, 0}), ans);
	printf("%.2lf\n", ans);
	return 0;
}
