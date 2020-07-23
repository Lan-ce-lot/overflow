/////*************************************************************************
//// > FileName:
//// > Author:      Lance
//// > Mail:        lancelot_hcs@qq.com
//// > Date:        9102.1.8
//// > Description:
//// ************************************************************************/
//////#include <bits/stdc++.h>
//////#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
////#include <algorithm>
////#include <iostream>
////#include <cstdlib>
////#include <cstring>
////#include <sstream>
////#include <vector>
////#include <cstdio>
////#include <bitset>
////#include <string>
////#include <cmath>
////#include <deque>
////#include <queue>
////#include <stack>
////#include <map>
////#include <set>
////using namespace std;
////typedef long long ll;
////typedef pair<int, int> PII;
////const double pi = acos(-1.0);
////const double eps = 1e-6;
////const int mod = 1e9 + 7;
////#define debug(a) cout << "*" << a << "*" << endl
////const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
////const int maxn = 1000005;
//////sacnf("%lf") printf("%f")
////ll read()
////{
////    ll x = 0,f = 1;
////    char ch = getchar();
////    while (ch < '0' || ch > '9')
////	{
////		if (ch == '-')
////		f = -1;
////		ch = getchar();
////	}
////    while (ch >= '0' && ch <= '9')
////	{
////		x = x * 10 + ch - '0';
////		ch = getchar();
////	}
////    return x * f;
////}
////int t, n;
//////int dis[maxn], a[maxn];
////struct node{
////	dis, a;
////}r[maxn];
////void solve()
////{
////	cin >> t;
////	while (t--) {
////		scanf("%d", &n);
////		for (int i = 1; i < n; i++) {
////			scanf("%d", &r[i].dis, &r[i].a;
////		}	
////		
////		
////	}
////	
////}
////
////int main()
////{
////
//////    freopen("F:/Overflow/in.txt","r",stdin);
//////    ios::sync_with_stdio(false);
////    solve();
////    return 0;
////}
//#include <iostream>
//#include <string.h>
//#include <stdio.h>
// 
//using namespace std;
//typedef long long LL;
//const int N = 100005;
//const LL MOD = 1000000009;
// 
//LL fac[N],A[N],B[N];
// 
//void Init()
//{
//    fac[0] = 1;
//    for(int i=1; i<N; i++)
//        fac[i] = fac[i-1] * i % MOD;
//    A[0] = B[0] = 1;
//    for(int i=1; i<N; i++)
//    {
//        A[i] = A[i-1] * 691504013 % MOD;
//        B[i] = B[i-1] * 308495997 % MOD;
//    }
//}
// 
//LL quick_mod(LL a,LL b,LL MOD)
//{
//    LL ans = 1;
//    a %= MOD;
//    while(b)
//    {
//        if(b & 1)
//        {
//            ans = ans * a % MOD;
//            b--;
//        }
//        b >>= 1;
//        a = a * a % MOD;
//    }
//    return ans;
//}
//LL c;
//LL Solve(LL n,LL k)
//{
//    LL ans = 0;
//    for(int r=0; r<=k; r++)
//    {
//        LL t = A[k-r] * B[r] % MOD;
//        t = quick_mod(t, c, MOD);
//        LL x = fac[k];
//        LL y = fac[k-r] * fac[r] % MOD;
//        LL c = x * quick_mod(y,MOD-2,MOD) % MOD;
//        LL tmp = t * (quick_mod(t,n,MOD) - 1) % MOD * quick_mod(t-1,MOD-2,MOD) % MOD;
//        if(t == 1) tmp = n % MOD;
//        tmp = tmp * c % MOD;
//        if(r & 1) ans -= tmp;
//        else      ans += tmp;
//        ans %= MOD;
//    }
//    LL m = quick_mod(383008016,MOD-2,MOD);
//    ans = ans * quick_mod(m,k,MOD) % MOD;
//    ans = (ans % MOD + MOD) % MOD;
//    return ans;
//}
// 
//int main()
//{
//    int T;
//    LL n,k;
//    Init();
//    scanf("%d",&T);
//    while(T--)
//    {
////        cin>>n>>k;
//		scanf("%lld%lld%lld", &n, &c, &k);
//        cout<<Solve(n,k)<<endl;
//    }
//    return 0;
//}
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
 
inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
  return *p1++;
}
 
//inline void read(ll &x){
//  char c=nc(),b=1;
//  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
//  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
//}
 
const int M=55;
const int P=1e9+9;
 
struct Matrix{
  int n;
  ll a[M][M];
  Matrix(){ }
  Matrix(int in,int ii=0){
    n=in; memset(a,0,sizeof(a));
    if (ii) for (int i=0;i<=n;i++) a[i][i]=1;
  }
  ll *operator[](int x){
    return a[x];
  }
  friend Matrix operator* (Matrix A,Matrix B){
    int n=A.n; Matrix ret(n);
    for (int i=0;i<=n;i++)
      for (int j=0;j<=n;j++)
        for (int k=0;k<=n;k++)
	  (ret[i][j]+=A[i][k]*B[k][j]%P)%=P;
    return ret;
  }
}A;
 
 
Matrix Pow(Matrix A,int b){
  Matrix ret(A.n,1);
  for (;b;b>>=1,A=A*A)
    if (b&1)
      ret=ret*A;
  return ret; 
}
 
ll n,K;
ll C[M][M];
 
inline void Pre(){
  C[0][0]=1;
  for (int i=1;i<=K;i++){
    C[i][0]=1;
    for (int j=1;j<=i;j++)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
  }
}
 
ll Ans;
ll c;
int t;
int main(){
//  freopen("t.in","r",stdin);
//  freopen("t.out","w",stdout);
//  read(n); read(K); 
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld", &n, &c, &K);
  		Pre();
  A=Matrix(K+1);
  for (int a=0;a<=K;a++)
    for (int t=0;t<=a;t++)
      A[a][K-a+t]=C[a][t];
  A[K+1][K+1]=A[K+1][K]=1;
  A=Pow(A,n-1);
  for (int i=0;i<=K+1;i++)
    (Ans+=A[K+1][i])%=P;
  printf("%lld\n",Ans);
	}

  return 0;
}
