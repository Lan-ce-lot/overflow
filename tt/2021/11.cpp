#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll n, m, t, a, b, k, now;
ll all[10005][105];
map<vector<int>, int> M;

struct node {
	int al;
	vector<int> V;
	bool operator < (node W) {
		if (al == W.al) {
			for (int i = 0; i < V.size(); i++) {
				if (V[i] > W.V[i]) {
					return 0;
				} else if (V[i] < W.V[i]) {
					return 1;
				}
			}
		}
		return al > W.al;
	}
}N[maxn];
//bool check(int in, int to) {
//	for (int i = 1; i <= n; i++) {
//		if (all[in][i] == all[to][i]) {
//			
//		}
//	}
//}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s = "";
		vector<int> V;
		for (int j = 1; j <= m; j++) {
			cin >> a;
			V.push_back(a);
		}
		M[V]++;
	}
	int tot = 0;
	for (auto it : M) {
		N[tot++] = {it.second, it.first};
	}
	sort(N, N + tot);
	cout << tot << endl;
	
	for (int i = 0; i < tot; i++) {
		cout << N[i].al;
		for (int j = 0; j < N[i].V.size(); j++) {
			cout << ' ' << N[i].V[j]; 
		}
		puts("");
	}
	

}
