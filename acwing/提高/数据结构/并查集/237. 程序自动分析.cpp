#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
const int MAXN = 2e6 + 5;

using namespace std;
int n, m, w;
int par[MAXN];
int ste[MAXN];
int cost[MAXN];
int dp[MAXN];
int V[MAXN], price[MAXN];
int ans = 0, t;

unordered_map<int, int> M;
int con;
struct node{
	int x, y, e;
	
}N[MAXN];
// ≤ª±£–Ú¿Î…¢ªØ 
int get(int x) {
	if (M.count(x) == 0) M[x] = ++con;
	return M[x];
}

int find(int x) {
	if (par[x] != x) {
		return par[x] = find(par[x]);
	} else {
		return par[x];
	}
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
//		cost[b] += cots[a];
//		V[b] += V[a];
//		price[b] += price[a];
		par[a] = par[b];
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		con = 0;
		M.clear();
		int flag = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x, y, e;
			scanf("%d%d%d", &x, &y, &e); 
			N[i] = {get(x), get(y), e};
		}
		for (int i = 0; i <= con; i++) par[i] = i;
		for (int i = 0; i < n; i++) {
			if (N[i].e == 1) {
				unite(N[i].x, N[i].y);
			} 
		} 
		for (int i = 0; i < n; i++) {
			if (N[i].e == 0) 
				if (find(N[i].x) == find(N[i].y)) {
					flag = 1;
					break;
				}
		}
		
		if (flag) {
			puts("NO");
		} else {
			puts("YES");
		}
		
	}
	return 0;
}
 
