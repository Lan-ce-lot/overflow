#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;

set<int> S;
int e[100005];
int n, a[100005];
int ans[100005];
int lowbit(int x) {
	return x & -x; 
}

void add(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i)) e[i] += k;
}

int sum(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += e[i];
	return res;
}


int main() {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
//		add(i, 1);
		e[i] = lowbit(i);
	}
	for (int i = n; i >= 0; i--) {
		int l = 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (sum(mid) >= a[i] + 1) r = mid;
			else l = mid + 1;
		}
		add(l, -1);
		ans[i] = l;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
