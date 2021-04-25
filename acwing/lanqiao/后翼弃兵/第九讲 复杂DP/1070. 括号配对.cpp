#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

int t, n, f[1005][1005];
string s;
map<char, char> M{{'[', ']'}, {'(', ')'}};

int main() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) f[i][i] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			f[l][r] = INF;
			if (M[s[l]] == s[r]) 
				f[l][r] = min(f[l][r], f[l + 1][r - 1]);
			for (int k = l; k < r; k++)
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
		}
	}
	cout << f[1][n] << endl;
}

