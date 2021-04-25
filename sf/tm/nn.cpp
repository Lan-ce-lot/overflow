#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define x first
#define y second
typedef pair<ll, ll> PII;
const int N = 4e5 + 8;
ll n, S, T, f[N];
PII p[N];
set<PII> st;

ll dis(ll i, ll j) {
	return abs(p[i].y - p[j].y);
}

int main() {
	scanf("%lld%lld%lld", &n, &S, &T);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	p[0] = {0, T};
	sort(p, p + n + 1);
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	st.insert(PII(T, 0));
	for (int i = 1; i <= n; ++i) {
		PII tmp = PII(p[i].y, p[i].x);
		set<PII>::iterator it = st.lower_bound(tmp);
		if (it == st.begin()) {
			int j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * p[i].x);
		} else if (it == st.end()) {
			--it;
			int j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * p[i].x);
		} else {
			int j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * p[i].x);
			--it;
			j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * p[i].x);
		}
		st.insert(tmp);
	}
	ll ans = 5e18;
	for (int i = 1; i <= n; i++)
		if (p[i].y == S)
			ans = min(ans, f[i]);
	printf("%lld\n", ans);
}
