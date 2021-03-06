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
const int maxn = 10000005;
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
//d(i) 表示 i 的约数个数  
//
//num[i] 表示 i 的最小素因子的个数 
//
//prim[i] 表示 第 i 个素数
ll t, n;
ll prime[maxn], tot = 0, num[maxn], d[maxn];
bool vis[maxn];
void init(ll en) {
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) prime[tot++] = i, num[i] = 1, d[i] = 2; 
		for (int j = 0; prime[j] <= n / i && j < tot; j++) {
			
			vis[prime[j] * i] = 1;
			if (i % prime[j] == 0) {
				num[i*prime[j]]=num[i]+1;
				d[i*prime[j]]=d[i]/(num[i]+1)*(num[i*prime[j]]+1);
				break;
			}
			d[i * prime[j]] = d[i] * d[prime[j]];
			num[i * prime[j]] = 1;
		}
	}
}


void solve()
{
	n = read();
	init(n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += d[i] * i;
	}
	
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

