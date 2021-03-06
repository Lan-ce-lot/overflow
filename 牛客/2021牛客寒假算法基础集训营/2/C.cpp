/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 4000005;
ll lowbit(ll x) {
	return x & -x;
}
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
ll t, n;
int primes[maxn], cnt;     // primes[]´æ´¢ËùÓÐËØÊý
bool st[maxn];         // st[x]´æ´¢xÊÇ·ñ±»É¸µô
ll f[maxn];
int weshu[maxn];
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
int getw(ll x) {
	int res = 0;
	while (x) {
		x /= 10;
		res++;
	}
	return res;
}
ll qpow(int x, int n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}
ll divide(int x)
{
	int tmp = x;
	ll ans = 0;
	if (!st[x]) {
		weshu[tmp] += getw(x);
		return x % mod;
	}
    for (int i = 2; i <= x / i; i ++ ) {
    	if (x % i == 0) {
            int s = 0;
            while (x % i == 0) {
            	x /= i;
				s ++;
				ans = (ans * qpow(10, getw(i))) % mod;
				ans = (ans + i) % mod;
			}
			weshu[tmp] += s;
//            cout << i << ' ' << s << endl;
        }
		if (!st[x]) {
			break;
//			return x % mod;
		}
 	}
    if (x > 1) {
    	weshu[tmp] += getw(x);
    	ans = (ans * qpow(10, getw(x))) % mod; 
		ans = (ans + x) % mod;
	}
	return ans;
//    cout << endl;
}

//ll f(int n) {
//	if (f[n]) {
//		reurn f[n];
//	} else {
//		
//	}
//}
void solve()
{
	n = read();
	get_primes(n + 1);
	memset(f, -1, sizeof f);
	divide(1024);
	for (int i = 0; i < cnt; i++) {
		f[primes[i]] = primes[i];
		weshu[primes[i]] = getw(primes[i]);
	}
	
	for (int i = 2; i <= n / i; i++) {
		for (int j = i; j <= n / i; j++) {
			if (f[i] == -1) {
				f[i] = divide(i);
			} 
			if (f[j] == -1) {
				f[j] = divide(j);
			}

			if (f[i * j] == -1) {
//				f[i * j] = (f[j] * qpow(10, weshu[f[i]]) % mod + f[i]) % mod;
				f[i * j] = (f[i] * qpow(10, weshu[j]) % mod + f[j]) % mod;
				weshu[i * j] = weshu[i] + weshu[j];
			}			
		}
	}
//	f[2048] = 222222068;
	ll flag = 0;
	for (int i = 2; i <= n; i++) {
		if (f[i] != divide(i)) {
			
			cout << i << endl;
			cout << f[i] << ' ' << divide(i) << ' ' << i - flag <<  endl; 
			flag = i;
		}
	}
//	for (int i = 2; i <= n; i++) {
//		cout << f[i] << endl;
//	}
	ll ans = 0;
//	for (int i = 2; i <= n; i++) {
////		cout << divide(i) << endl;
//		ans = (ans + f[i]) % mod;
//	}
//	cout << ans << endl;
	ans = 0;
	for (int i = 2; i <= n; i++) {
//		cout << divide(i) << endl;
		ans = (ans + divide(i)) % mod;
	}
	cout << ans << endl;
	cout << f[1024] << ' '<< divide(1024) << endl;
	cout << f[2048] << ' '<< divide(2048) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

