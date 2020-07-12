#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int par[2000010];

struct node{
	int fr, to;
}N[2010010];

int n, m, k;

void init() {
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
}

int find(int a) {
	return a == par[a] ? a : par[a] = find(par[a]);
}

void unite(int a, int b) {
	par[find(a)] = find(b);
}



int main() {
	init();
	scanf("%d%d%d", &n, &m, &k);
	for (int i =0; i < m; i++) {
		int a, b;
		scanf("%d%d", &N[i].fr, &N[i].to);
	}
	
	for (int i = 0; i < k; i++) {
		int b;
		init();
		scanf("%d", &b);
		
		for (int j = 0; j < m; j++) {
			if (N[j].fr != b && N[j].to != b) {
				unite(N[j].fr, N[j].to);
			}
		}
		set<int> S;
		for (int j = 1; j <= n; j++) {
//			cout << par[j] << endl;
			if (j != b)
				S.insert(find(par[j]));// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!S.insert(par[j])
		}
		printf("%d\n", S.size() - 1);
	}
	return 0;
}
