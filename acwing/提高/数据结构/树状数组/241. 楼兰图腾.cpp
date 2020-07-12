#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int MAXN = 2e5 + 5;
typedef long long ll;
int t, e[MAXN], a[MAXN];
int gr[MAXN], lo[MAXN];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int k) {
	for (int i = x; i <= t; i += lowbit(i)) e[i] += k;
}

int get(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += e[i];
	return res;
}

int main() {
	
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		
		cin >> a[i];
	}
//	init();
	for (int i = 1; i <= t; i++) {
		int y = a[i];
		gr[i] = get(t) - get(y);
		lo[i] = get(y - 1);
		add(y, 1);
	}  
	
	memset(e, 0, sizeof e);
	ll res1 = 0, res2 = 0;
	
	for (int i = t; i; i--) {
		int y = a[i];
		res1 += gr[i] * (ll)(get(t) - get(y));
		res2 += lo[i] * (ll)(get(y - 1));
		add(y, 1);
	}
	printf("%lld %lld\n", res1, res2); 
	return 0;
} 
