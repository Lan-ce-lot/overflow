#include <iostream>

using namespace std;
const int maxn = 1e6 +5;
int prime[maxn], tot, n;
bool vis[maxn];

void get(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) prime[tot++] = i;
		for (int j = 0; i <= n / prime[j]; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int main() {
	cin >> n;
	get(n);
	cout << tot << endl;	
	
	return 0;	
}
