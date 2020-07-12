#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;



int n, q;

int primes[100000005], cnt;
bool st[100000005];

void get_primes(int n) {
	for (int i = 2; i <= n; i++) {
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n / i; j++) {
			st[primes[j] * i] = 1;
			if (i % primes[j] == 0) break;
		}
	}
}

vetcor<int> G[maxn];
int dis[maxn];
bool vis[maxn];
int dj() {
	
	memset(dis, 0x3f3f3f3f, sizeof vis);
	
	dis[1] = 0;	
	for (int i = 0; i < n; i++) {
		int max1 = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (t != -1|| dis[max1] > dis[j])) {
				max1 = j;
			}
		}
		
		for (int j = 1; j <= n; j++) {
			
			dis[j] = min(dis[j], dis[t] + g[t][j]);
			vis[t] = 1;
		}
		
		
	}
	if (dis[n] == 0x3f3f3f3f) return -1;
	return dis[n];
	
	
} 

int main() {
	
	scanf("%d%d", &n, &q);
	int tem = 0;
	get_primes(n);
	for (int i = 0; i < q; i++) {
		scanf("%d", &tem);

		printf("%d\n", primes[tem - 1]);
	}
	
	return 0;
} 
