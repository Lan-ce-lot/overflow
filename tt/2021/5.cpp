#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, t, a[maxn], k;
int h[maxn], tot;
struct node {
	int to, v, ne;
	
}G[maxn];

bool vis[maxn], dis[maxn];
int dj() {
	for (int i = 0; i < n; i++) {
		int u =  -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (u == -1 || dis[j] < dis[u])) {
				u = j;
			}
		}
		vis[u] = 1;
		for (int j = h[u]; ~j; j = G[j].ne) {
			int to = G[u].to;
			
			dis[to] = min(dis[to], dis[u] + G[j].v);
		}
	} 
	
}
void add(int a, int b, int c) {
	G[tot] = {b, c, h[a]}, h[a] = tot++;
} 
int main() {
	
	
	memset(h, -1, sizeof h);
	cin >> n >> k >> m;	
	return 0;
}
