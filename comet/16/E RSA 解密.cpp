//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//
//using namespace std;
//// 
//int main() {
//	
//	unsigned __int64 res = 1001733993063167141;
//	
//	for (int i = 2; i * i <= res; i++) {
//		
//		while (res % i == 0 && res != 1) {
//			printf("%I64d %I64d", i, res / i);
//			res /= i;
//		}
//	}
//	
//	return 0;
//} 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))  
#define UI64d unsigned __int64
UI64d FastPower(UI64d a , UI64d k);	
long long res = 1001733993063167141;
 using namespace std;
ll mul(ll a, ll b, ll p) {
	ll res = 0;
	while (b > 0) {
		if (b & 1)
			res = (res + a) % p;
		a = (a + a) % p;
		b >>= 1;
		
	}
	return res;	
}

ll qpow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) {
			res = mul(res, x, p) % p;
		}
		x = mul(x, x, p) % p;
		n >>= 1;
	}
	return res;
} 
 

ll ie(ll d, ll p) {
	return qpow(d, p - 2, p);
} 

ll get(ll o) {
	for (int i = 2; i * i <= o; i++) {
		if (o % i == 0)
			return i;
	}
}

ll phi(ll n) {
	ll res = n;
	for(int i= 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res - res / i;
			while (n % i == 0) {
				n = n / i;
			}
		}
	}
	
	if (n > 1) res = res - res / n;
	return res;
}

//ll phi(int n) {
//	ll res = n;
//	for(int i= 2; i * i <= n; i++) {
//		if (n % i == 0) {
//			res = res / i * (i - 1);
//			while (n % i == 0) {
//				n /= i;
//			}
//		}
//	}
//	
//	if (n != 1) res = res / n * (n - 1);
//	return res;
//}

int main()
{
	long long n = 1001733993063167141;
	//891234941 1123984201

	ll d = 212353;
	ll c = 20190324;
//	ll p1 = get(n);
//	ll p2 = n / p1;
//	cout << p1 << ' ' << p2 << endl;
//	ll k = (p1 - 1) * (p2 - 1);
	ll k = 1001733991047948000;
	cout << k <<endl;
	cout << phi(k) << endl;
	ll e = qpow(d, phi(k) - 1, k);
	cout << e << endl;
	cout << qpow(c, e, n) <<endl;
//	for(int i= 2; i * i <= res; i++)
//	{
//		while(res % i == 0 && res != 1) 
//		{
//			printf("%lld %lld\n", i, res / i);
//			res /= i;
//		}
//	}
		
	
	return 0;
}
