#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll; 
const int MAXN = 1e6 + 5;

int n, m;
ll a[MAXN];
ll e[MAXN];	// b[i]
ll e2[MAXN];// i * b[i]
// ans = sum(b) * (n + 1) - sum(i * b)

int lowbit(int x) {
	return x & -x;
}

void add(int x, ll k) {
	for (int i = x; i <= n; i += lowbit(i)) {
//		cout << k << "->" << e[i] << ' ' << e2[i] << endl;
		e[i] += k;
		e2[i] += x * k;
//		cout << i << "->" << e[i] << ' ' << e2[i] << endl;
	}
}

ll sum(int x) {
	ll res = 0;
	for (int i = x; i; i -= lowbit(i)) res += e[i];
	return res;
}

ll sum2(int x) {
	ll res = 0; 
	for (int i = x; i; i -= lowbit(i)) res += e2[i];
	return res;
}

ll get_sum(int x) {
	return sum(x) * (x + 1) - sum2(x);
}
ll a1, b1, c1;
char c[10];
int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		add(i, a[i] - a[i - 1]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", c);
		if (c[0] == 'Q') {
			scanf("%lld%lld", &a1, &b1);
//			cout << a1 << "->" << b1 << endl;
//			a1--;
//cout << sum(b1) * (b1 + 1) << ' ' << sum2(b1) << ' ' << sum(a1 - 1) * (a1) << ' ' << sum2(a1 - 1) << endl;
			printf("%lld\n", get_sum(b1) - get_sum(a1 - 1));
			
		} else {
//			cout << 1 << endl;
			scanf("%d%d%lld", &a1, &b1, &c1);
			add(a1, c1);
			add(b1 + 1, -c1);
		}
	}
	return 0;
} 
