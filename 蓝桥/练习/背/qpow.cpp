#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;

//int fib(int n) {
//	return n == 1 || n == 2 ? 1 : fib(n - 1) + fib(n - 2); 
//}
int num[1000005];
int fib(int n) {
	if (n <= 1) return n;
	if (num[n] != 0) {
		return num[n];
	} else return num[n] = fib(n - 1) + fib(n - 2);
	
}
bool vis[1004];

void dfs(int st, int n, string str) {
	if (st == n) {
		cout << str << endl;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (vis[num[i]] == 0) {
			vis[num[i]] = 1;
			dfs(st + 1, n, str + char('0' + num[i]));
			vis[num[i]] = 0;
		}
	}
}


void dfs2(int a[], int st, int n) {
	if (st == n) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}puts("");
		return;
	}
	
	for (int i = st; i < n; i++) {
		swap(a[i], a[st]);
		dfs2(a, st + 1, n);
		swap(a[i], a[st]);
	}
	
}

ll qpow(int x, int n, int mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return res % mod;
}

int n, m;
int main() {
	
	
	cin >> n;
	cin >> m;
	cout << qpow(n, m, 10007);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	dfs(0, n, "");
	dfs2(num, 0, n);
//	cin >> n;
//	cout << fib(n) << endl;
	return 0;
}
