/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define x first
#define y second
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
int t, n, a, b, f[10005], res;
vector<PII> P;
bool cmp1(PII A, PII B) {
	return A.x != B.x ? A.x > B.x : A.y > B.y;
}
void solve() {
	cin >> n;
	P.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		P[i] = {a, b};
	}
	sort(P.begin() + 1, P.end(), cmp1);
	for (int i = 1; i <= n; i++) {f[i] = 1;
		for (int j = 1; j < i; j++) {
			if (P[j].y < P[i].y) {
				f[i] = max(f[i], f[j] + 1);
			}
			res = max(res, f[i]);
		}
	}
	cout << res<< endl;
}

int main()
{
//    freopen("P1233_2.in","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}