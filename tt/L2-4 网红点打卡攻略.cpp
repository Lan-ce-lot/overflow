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
ll t, n, m, k, all;ll a, b ,c ;
ll G[1005][1005];
vector<ll> ans;
ll id = 0, ssum = 0;
vector<ll> tmp;
bool vis[260];
void solve()
{

	cin >> n >> m;
	for(int i=0;i<=n;i++)  for(int j=0;j<=n;j++)  G[i][j]=1e9+5;
	for (int i = 0; i <= n; i++) G[i][i] = 1e9+5;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		G[a][b] = G[b][a] = min(c, G[a][b]);	
	}
	cin >> k;
	ll sum = INF, tsum = 0;
	for (int i = 1; i <= k; i++) {
		cin >> all;
		tsum = 0;
		ll last = 0, ff = 0;
		map<int, int> M;
		while (all--) {
			cin >> a;
			M[a]++;
			tsum += G[a][last];
			last = a;
		}
		tsum += G[0][last];
		for (int i  =1; i <= n; i++) if (M[i] != 1) ff = 1;
		
		if (tsum <= 1e9 && ff == 0) {
			ssum++;
			if (tsum < sum) {
				sum = tsum;
				id = i;
			}
		}
	}
	
	cout << ssum << endl;
	if (ssum != 0) cout << id << ' ' << sum << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

