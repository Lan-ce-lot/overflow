#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e6 + 5;
/*
4
8 10 11 9
0 375 4218 31
6
17 20 24 19 22 25
16 110 1703 47 406 3468
5
359999 431998 518397 300000 746491
31 47 47 31 78
0
*/
ll  n, ind, d[maxn], t[maxn], M[7];
long double k[7][maxn], loss[7], ans = INF;

long double get_loss(long double *k) {
	long double avg = 0;
	for (int i = 0; i < n; i++) avg += k[i];
	avg /= n;
	long double res = 0;
	for (int i = 0; i < n; i++) 
		res += (k[i] - avg) * (k[i] - avg);
	res = sqrt(res);
	res /= avg;
	return fabs(res);
}
ll fac(int x) {
	ll res = 1;
	for (int i = 2; i <= x; i++) res *= i;
	return res;
}

void solve() {
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) cin >> d[i];
		for (int i = 0; i < n; i++) {
			cin >> t[i];
			if (!t[i]) t[i] = 1;
			k[1][i] = 1.0 * d[i] / t[i];
			k[2][i] = 1.0 * d[i] * log(d[i]) / t[i];
			k[3][i] = 1.0 * d[i] * d[i] / t[i];
			k[4][i] = 1.0 * d[i] * d[i] * d[i] / t[i];
			if (d[i] <= 31) k[5][i] = 1.0 * pow(2, d[i]) / t[i];
			else k[5][i] = 1.0 * t[i] / pow(2, d[i]);
			if (d[i] <= 20) k[6][i] = 1.0 * fac(d[i]) / t[i];
			else k[6][i] = 1.0 * t[i] / fac(d[i]);
		}
		for (int i = 1; i < 7; i++) loss[i] = get_loss(k[i]);
		long double ans = INF;
		int ind = 0;
		for (int i = 1; i < 7; i++) if (ans - loss[i] > 0) ans = loss[i], ind = i;
		cout << ind << endl;
	} 
}

int main() {
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

