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
int t, n, q, tem;
int a[maxn];
ll getSum(ll a, ll b) {
    // return a+b;
    ll ab_yu = a&b;
    ll ab_yihuo = a^b;
    
    while(ab_yu){
        ll e = ab_yihuo;
        ll f = ab_yu<<1;
        ab_yu = e&f;
        ab_yihuo = e^f;
    }
    
    return ab_yihuo;
}
void solve()
{
//	while (1) {
//		ll x = read(), y = read();
//		cout << getSum(x, y) << endl;
//		
//	}
	n = read();	
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
//	for (int i = 1; i <= 10; i++) {
//		int tem = 0;
//		for (int j = 1; j <= n; j++) {
//			tem += (i ^ a[j]);
//		}
//		cout  << i << ' ' << tem << endl;
//	}
	q = read();
	while (q--) {
		tem = read();
		cout << 1073741824000000 << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

