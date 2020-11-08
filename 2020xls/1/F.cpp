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
//#include <unordered_map>
//#include <set>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const double pi = acos(-1.0);
//const double eps = 1e-6;
////const int mod = 1e9 + 7;
//#define debug(a) cout << "*" << a << "*" << endl
//const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn = 2e7 + 5;
//
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
//ll t, n, k, mod;
//
//
//int V[maxn];
//unordered_map<ll, ll> S;
//ll primesum(ll range) {
////	memset(V, 0, sizeof V);
//	ll i, k;
//	
//	S.clear();
//	ll r = sqrt(range);
//	ll p = range / r;
//	ll len = r + p - 1;
//	k = r + 1;
//	for (int i = 1; i < k; i++) {
//		V[i - 1] = range / i;
//	}
//	ll count = 1;
//	for (int i = r + p - 2; i >= r; i--) {
//		V[i] = count++;
//	}
////	cout << r + p - 1 << endl;
//	for (i = 0; i < len; i++) {
//		S[V[i]] = V[i] * (V[i] + 1) / 2 - 1;
////		cout << S[V[i]] << endl;
//	}
//	
//	ll sp, p2;
//	for (p = 2; p < r + 1; p++) {
//		if (S[p] > S[p - 1]) {
//			sp = S[p - 1];
//			p2 = p * p;
//			for (i = 0; i < len; i++) {
//				if(V[i] < p2) break;
////				S.put(V[i], S.get(V[i]) - p * (S.get(V[i] / p) - sp));
//				S[V[i]] -= p * (S[V[i] / p] - sp);
////				cout << S[V[i]] << endl;
//			}
//		}
//	}
//	
//	return S[range];
//}
//
//void solve()
//{
//	t = read();
//	while (t--) {
//		        scanf("%lld%lld", &n, &mod);
//        if (n % 2)
//            k = ((n + 4) % mod) * ((n - 1) / 2 % mod) % mod;
//        else
//            k = ((n + 4) / 2 % mod) * ((n - 1) % mod) % mod;
//        printf("%lld\n", ((primesum(n + 1) - 2) % mod + k) % mod);    
//	}
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
//#pragma GCC optimize(2)

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#define ls (k << 1)
#define rs (ls | 1)
using namespace std;
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<int, int> P; 
typedef pair<ll, ll> pll; 
//const int mod = 1e9 + 7;
const int N = 2e7 + 5;
struct ed{
    int to, nxt, w;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v, int w){
    e[tot].to = v, e[tot].w = w, e[tot].nxt = head[u], head[u] = tot++;
}
ull V[N];
unordered_map<ull, ull> S;
ull primesum(ull range)
{
    ull i, k;
    ull r = sqrt(range);
    ull p = range / r;
    ull len = r + p - 1;
    k = r + 1;
    for (int i = 1; i < k; i++)
        V[i - 1] = range / i;
    ull count = 1;
    for (int i = r + p - 2; i >= r; i--)
        V[i] = count++;
    //cout << r + p - 1 << endl;
    for (int i = 0; i < len; i++)
        S[V[i]] = V[i] * (V[i] + 1) / 2 - 1;
    ull sp, p2;
     for (p = 2; p < r + 1; p++) {
            if (S[p] > S[p - 1]) {
                sp = S[p - 1];
                p2 =  p * p;
                for (i = 0; i < len; i++) {
                    if (V[i] < p2) {
                        break;
                    }
                    S[V[i]] -= p * (S[V[i] / p] - sp);
                }
            }
        }

        return S[range];
}
int t;
ull n, mod, k; 
int  main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%ulld%ulld", &n, &mod);
        if (n % 2)
            k = ((n + 4) % mod) * ((n - 1) / 2 % mod) % mod;
        else
            k = ((n + 4) / 2 % mod) * ((n - 1) % mod) % mod;
        printf("%ulld\n", ((primesum(n + 1) - 2) % mod + k) % mod);    
    }    
}
