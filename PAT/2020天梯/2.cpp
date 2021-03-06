#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
int n;
double a[maxn], dao[maxn];

int main()  {
//	T_T
//  ^_^
	cin >> n;
	double sum = 1.0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum *= a[i];
		dao[i] = 1.0 / (a[i] * 1.0);
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dao[i];
	}
	printf("%.2f\n", (n * 1.0)/ ans);
	
	return 0;
}
