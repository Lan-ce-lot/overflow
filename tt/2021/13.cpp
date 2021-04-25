#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll n, m, t, a, b, k, now, u, v, c,d;
ll all[10005][105];
int h[maxn], tot;
struct node {
	int to, cost, m, ne;
}G[maxn];
void add(int a, int b, int c, int d) {
	G[tot] = {b, c, d, h[a]}, h[a] = tot++;
}
int cit[maxn];
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i < m; i++) {
		cin >> u >> v >> c >> d;
		add(u, v, c, d);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cit[i] = a;
	}
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		cit[a] = b;
		
	}
	
	
}
