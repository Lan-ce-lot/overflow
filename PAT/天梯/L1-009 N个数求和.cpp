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
int t, n;


vector<pair<ll, ll> > V;

//ll lcm(ll a, ll b) {
//	return a * b / __gcd(a, b);
//}
void solve()
{
	n = read();
	ll fm = 0, fz = 0;
	for (int i = 1; i <= n; i++) {
		string tem;
		ll a, b;
		scanf("%lld/%lld",&a,&b);
		V.push_back({a, b});
		
	}
	ll gg = 1;
	bool ff = 0;
	
	for (int i = 0; i < V.size(); i++) {
		gg = gg / __gcd(gg, V[i].second) * V[i].second;
	}
	
	for (int i = 0; i < V.size(); i++) {
		V[i].first *= gg / V[i].second;
	}
	for (int i = 0; i < V.size(); i++) {
		fz += V[i].first;
	}
	fm = gg;
	ll te = __gcd(abs(fz) * 1ll, fm * 1ll);
	fz /= te, fm /= te;
	if (fz % fm == 0) {
		cout << fz / fm << endl;
	} else if (fz > fm) {
		cout << fz / fm << ' ' << fz % fm << '/' << fm << endl;
	} else {
		cout << fz % fm  << '/' << fm << endl;
	}
}

int main()
{
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

