#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll n, m, t, a, b, k, now;
string s[1005], ans;
stack<char> S; 
const int INF = 0x3f3f3f3f;

int main() {
	cin >> n >> m  >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	while (cin >> a) {
		if (a == -1) {
			cout << ans << endl;
			break;
		}
		if (a == 0 && S.size()) {
			ans += S.top();
			S.pop();
		} else {
			if (S.size() == k) {
				ans += S.top();
				S.pop();
			}
			if (s[a].size() != 0) {
				S.push(s[a][0]);
				s[a] = s[a].substr(1, s[a].size() - 1);
			}
		}
	}
}
