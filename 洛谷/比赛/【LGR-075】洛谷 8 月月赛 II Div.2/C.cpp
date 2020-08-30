/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#pragma GCC optimize(2)

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
#include <unordered_map>
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
int t, n;
ll a[maxn];
//ll con[maxn];
map<ll, ll> con;

ll par[maxn];
map<ll, ll> sum;
map<ll, bool> vis;
ll find(ll x) {
	if (par[x] = x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

void unite(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x > y) {
//		sum[y] += sum[x];
		par[y] = x;
	} else {
		par[x] = y;
	}
}

ll LCM(ll a, ll b) {
	return a * b / __gcd(a, b);
}
ll tem[maxn][2], num = 1;
void solve()
{
	n = read();
	ll ans =  0;
	
	for (int i = 0; i < 3 * 1e5 + 5; i++) {
		par[i] = i;
		sum[i] = 1; 
	}
	for (int i = 0; i < n; i++) {
		a[i] = read();
		con[a[i]] ++;
	}
	for (map<ll, ll>::iterator it = con.begin(); it != con.end(); it++) {
		tem[num][0] = it->first;
		tem[num][1] = it->second;
		it->second = num;
		num++;
	}

	
	for (int i = 1; i <= num; i++)
	{
		if (tem[i][0] % 3 == 0 && con[tem[i][0] / 3 * 2])
			unite(i, con[tem[i][0] / 3 * 2]);
	}
	for (int i = 1; i <= num; i++)
	{
		sum[find(i)] += tem[i][0] * tem[i][1];
	}
	for (int i = 1; i < num; i++)
	{
		if (sum[i])
			ans = max(ans, sum[i]);
	}
	printf("%lld\n", ans);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

