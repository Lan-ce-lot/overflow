#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 2e6 + 5; 
int n, m, t, a, b;
int par[maxn];

int find(int x) {return x == par[x]? x: par[x] = find(par[x]);}

void uinte(int a, int b) {par[find(a)] = find(b);}

int main() {
	cin >> n >> m;
	for (int i = 0; i <= n * m + 1; i++) 
		par[i] = i;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		uinte(a, b);
	}
	set<int> S;
	for (int i = 1; i <= n * m; i++) 
		S.insert(find(i));
	cout << S.size() << endl;
	
	return 0;
}
