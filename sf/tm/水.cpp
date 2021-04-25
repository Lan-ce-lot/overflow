#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define cost(x) p[x].first
#define pos(x) p[x].second
typedef pair<ll, ll> PII;
const int N = 4e5 + 8;
ll n, S, T, f[N];
PII p[N];
set<PII> st;

ll dis(ll i, ll j) {
	return abs(pos(i) - pos(j));
}

int main() {
	scanf("%lld%lld%lld", &n, &S, &T);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &cost(i), &pos(i));
	p[0] = PII(0, T);
	sort(p, p + n + 1);
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	st.insert(PII(T, 0));
	for (int i = 1; i <= n; ++i) {
		PII tmp = PII(pos(i), cost(i));
		set<PII>::iterator it = st.lower_bound(tmp);
		if (it == st.begin()) {
			int j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * cost(i));
		} else if (it == st.end()) {
			--it;
			int j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * cost(i));
		} else {
			int j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * cost(i));
			--it;
			j = lower_bound(p, p + n + 1, PII(it->second, it->first)) - p;
			f[i] = min(f[i], f[j] + dis(i, j) * cost(i));
		}
		st.insert(tmp);
	}
	ll ans = 5e18;
	for (int i = 1; i <= n; ++i)
		if (pos(i) == S)
			ans = min(ans, f[i]);
	printf("%lld\n", ans);
}
