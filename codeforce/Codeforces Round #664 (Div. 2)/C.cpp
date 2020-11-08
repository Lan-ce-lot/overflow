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
const int maxn = 1005;
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
int t, n, m;
int a[maxn], b[maxn], c[maxn];
vector<int> G[maxn];
vector<int> H;
void solve()
{
	memset(c, INF, sizeof c);
	n = read(), m = read();
	for (int i = 0; i < n; i++) {
		a[i] = read();
	}
	for (int i = 0; i < m; i++) {
		b[i] = read();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
//			c[i] = min(a[i] & b[j], c[i]);
			G[i].push_back(a[i] & b[j]);
		}
	}
	ans = 0;
	for (int i = 0; i < n; i ++) {
		ll tem = 1 << 10 - 1;
		for (auto j : G[i]) {
			tem &= j;
		}
		ans += ;
	}
	ll ans = 0;
	
//	puts("");
	printf("%lld\n", ans);
}
/*
147
     1001 0011
179
  	 1011 0011
   1 0000 0101
   1 1011 0000
     1010 0010
      101 0010
       10 1011
          1010
       10 0110
       
// 1 0111 1011
// 1 0110 0101
//   1100 1010
//   1011 1000
//   1100 0101
// 
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

