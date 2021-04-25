#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
int t, n, m;

int h[maxn], ne[maxn], tot, e[maxn], a, b, du[maxn]; // ³ö¶È 
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}

int seq[maxn], cnt = 0;
void top_sort() {
	queue<int> Q;
	for (int i = 1; i <= n; i++) if (!du[i]) Q.push(i);
	while (Q.size()) {
		int x = Q.front();
		Q.pop();
		seq[cnt++] = x;
		for (int i = h[x]; ~i; i = ne[i]) {
			int y = e[i];
			if (--du[y] == 0) Q.push(y);
		}
	}
}

bitset<30005> f[30005];
void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		add(a, b);
		du[b]++;
	}
	top_sort();

	for (int i = n - 1; i >= 0; i--) {
		int j = seq[i];
		f[j][j] = 1;
		for (int k = h[j]; ~k; k = ne[k]) f[j] |= f[e[k]];
	}
	
	for (int i = 1; i <= n; i++)
		cout << f[i].count() << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

