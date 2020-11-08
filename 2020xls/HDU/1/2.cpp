///*************************************************************************
// > FileName:
// > Author:      Lance
// > Mail:        lancelot_hcs@qq.com
// > Date:        9102.1.8
// > Description:
// ************************************************************************/
////#include <bits/stdc++.h>
////#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
//#include <algorithm>
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <sstream>
//#include <vector>
//#include <cstdio>
//#include <bitset>
//#include <string>
//#include <cmath>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const double pi = acos(-1.0);
//const double eps = 1e-6;
//const int mod = 1000000009;
//#define debug(a) cout << "*" << a << "*" << endl
//const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn = 1000005;
////sacnf("%lf") printf("%f")
//ll read()
//{
//    ll x = 0,f = 1;
//    char ch = getchar();
//    while (ch < '0' || ch > '9')
//	{
//		if (ch == '-')
//		f = -1;
//		ch = getchar();
//	}
//    while (ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//    return x * f;
//}
//ll t, n, c, k;
//
//ll qpow(ll a, ll x) {
//	ll res = 1;
//	while (x) {
//		res = res * a % mod;
//		if (x & 1) {
//			a = a * a % mod;
//		}
//		x >>= 1;
//	}
//	return res;
//}
//ll fi[100];
//int f(int i) {
//	if (i == 0 || i == 1)
//		return 1;
//	if (fi[i]) return fi[i];
//	else return fi[i] = (f(i - 1) + f(i - 2)) % mod;
//}
//// F(2n) = nF(n) + (n - 1)F(n - 1) 
//ll ans = 0;
//void solve()
//{
////	t = read();
////	n = read();
////	int p;
////	p = read();
////	cout << f(n - 1) % p << endl;
//	for (int i = 0; i < 45; i ++) cout << f(i) << endl;
//	n = 8;
//	for (int i = 1; i <= n; i++) {
//		ans = 0;
//		for (int j = 0; j <= n * i; j+=i) {
////			cout << ans << endl;
//			ans = (ans + f(j)) % mod;
//		}
//		cout << ans << ' ' << i << endl;
//	}
////	for (int i = 0; i <= 100; i++) {
////		cout << i << ' ' << f(i) << endl;
////	}
//	
////	while (t--) {
////		n = read(), c = read(), k = read();
////		
////		
////		
////	}
//}
//
//int main()
//{
//
////    freopen("F:/Overflow/in.txt","r",stdin);
////    ios::sync_with_stdio(false);
//    solve();
//    return 0;
//}
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
 
const int P=1000000009;
const int INV2=500000005;
const int SQRT5=383008016;
const int INVSQRT5=276601605;
const int A=691504013;
const int B=308495997;
 
const int N=110005;
 
ll n,K,c;
ll fac[N],inv[N];
ll pa[N],pb[N];
 
inline void Pre(int n){
  fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%P;
  inv[1]=1; for (int i=2;i<=n;i++) inv[i]=(P-P/i)*inv[P%i]%P;
  inv[0]=1; for (int i=1;i<=n;i++) inv[i]=inv[i]*inv[i-1]%P;
  pa[0]=1; for (int i=1;i<=n;i++) pa[i]=pa[i-1]*A%P;
  pb[0]=1; for (int i=1;i<=n;i++) pb[i]=pb[i-1]*B%P;
}
 
inline ll C(int n,int m){
  return fac[n]*inv[m]%P*inv[n-m]%P;
}
 
inline ll Pow(ll a,ll b){
  ll ret=1;
  for (;b;b>>=1,a=a*a%P)
    if (b&1)
      ret=ret*a%P;
  return ret;
}
 
inline ll Inv(ll x){
  return Pow(x,P-2);
}
 
inline void Solve(){
  ll Ans=0;
  for (int j=0;j<=K;j++){
    ll t=pa[K-j]*pb[j]%P,tem;
    t = Pow(t, c);
    tem=t==1?n%P:t*(Pow(t,n)-1+P)%P*Inv(t-1)%P;
    if (~j&1)
      Ans+=C(K,j)*tem%P,Ans%=P;
    else
      Ans+=P-C(K,j)*tem%P,Ans%=P;
  }
  Ans=Ans*Pow(INVSQRT5,K)%P;
  printf("%lld\n",Ans);
}
int main(){
  int T;
//  freopen("t.in","r",stdin);
//  freopen("t.out","w",stdout);
  Pre(110000);
  scanf("%d",&T);
  while (T--){
    scanf("%lld%lld%lld",&n,&c,&K);
    Solve();
  }
}
