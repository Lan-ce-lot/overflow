#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<ll, ll> PII;
const int N = 4e5 + 8;
ll n, S, T, f[N];
PII p[N];

ll dis(ll i, ll j) {
	return abs(p[i].y - p[j].y);
}

int main() {
	scanf("%lld%lld%lld", &n, &S, &T);
	p[0] = {0, T};
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	
	sort(p, p + n + 1);
	f[0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			f[i] = min(f[i], f[j] + dis(i, j) * p[i].x);

	for (int i = 0; i <= n; i++) {
		if (p[i].y == S) {
			printf("%lld\n", f[i]);
			break;
		}
	}
}
