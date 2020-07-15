#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 5;
int t, n;
const int MOD = 998244353;

const int mod=998244353; 
const int N=1e6 + 5;
ll Finv[N],fac[MAXN],inv[N];

ll qpow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

ll niyuang(ll x) {
	return qpow(x, MOD - 2);
}
// =====================
void initFACT() {
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		fac[i] = fac[i - 1] * i % MOD; 
	}
}
ll ji(int n) {
	return fac[n + n + 1] * niyuang(fac[n]) % MOD;
}
// =========================
void init(int n)//n<N
{
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=((mod-mod/i)*inv[mod%i])%mod;
	fac[0]=Finv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod,Finv[i]=Finv[i-1]*inv[i]%mod;
	//Finv[n]=modpow(fac[n],mod-2,mod);
	//for(int i=n-1;i>=1;--i)Finv[i]=Finv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m)
{
	if(m<0||m>n)return 0;
	return fac[n]*Finv[n-m]%mod*Finv[m]%mod;
}

ll down[MAXN], up[MAXN];

int ya[1005][1005];
int main() {
	
	up[1] = 1;
	down[1] = 6;
	// 
//	cin >> n; 
	n = MAXN;
	for (int i = 2, j = 10; i <= n; i++) {
		
		up[i] = up[i - 1] * i % MOD;
		down[i] = down[i - 1] * (j + (i - 2) * 4) % MOD;
	}
//	for (int i = 1; i <= n; i++) 
//	cout << up[i] << ' ' << down[i] << endl;
	
	while (cin >> n) {
		cout << up[n] * niyuang(down[n])  % MOD<< endl;
	}
//	init(100);
//	initFACT();
//	n = 0;
//	while (1) {
//		n++;
//	ll up = 0;
//	ll down = ji(n);
////	cout << ji(n) << endl;
//	for (int i = 1; i <= n + 1; i++) {
//		if (i & 1) {
//			up = (up + down * C(n, i - 1) / (n + i)) % MOD;
//		} else {
//			up = (up - down * C(n, i - 1) / (n + i)) % MOD;
//		}
//	}
//	cout << up << ' ' << down << endl;
//	cout << up * niyuang(down) % MOD << endl;
//	}
    return 0;
}

/*


*/
