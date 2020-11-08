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
const int maxn = 100005;
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
unordered_map<ll, bool> can;
//int num_s[maxn], num_e[maxn];
unordered_map<ll, ll> num_s;
unordered_map<ll, ll> num_e;
unordered_map<ll, vector<ll>> rev;
//map<ll, int> M;
vector<ll> G;
void solve()
{
	t = read();
	while (t--) {
//		memset(can, 0, sizeof can);
		can.clear();
		num_s.clear();
		num_e.clear();
		rev.clear();
//		memset(num_s, 0, sizeof num_s);
//		memset(num_e, 0, sizeof num_e);
		G.clear();
		n = read();
		int tem = -1;
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			
			a[i] = read();
			if (tem > a[i]) flag = 1;
			rev[a[i]].push_back(i);
			G.push_back(a[i]);
//			M[a[i]] = i;
			tem = a[i];
		}
		if (flag == 0) {
			puts("YES");
			continue;
		} 
		sort(G.begin(), G.end());
		for (int i = 0; i < G.size(); i++) {
			ll tem = G[i];
			if (num_s[tem] == 0) {
				num_s[tem] = i + 1;
			} 
			num_e[tem] = i + 1;
		}
		ll min_ = *min_element(a + 1, a + n + 1);
		
		if (min_ == 1) {
			puts("YES");
			continue;			
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] % min_ == 0) {
					can[a[i]] = 1;
				}
			}
			int ff = 0;
			for (int i = 1; i <= n; i++) {
				ll tem = a[i];
				ll to = G[i - 1];
				if (tem == to) {
					continue;
				} else {
					if (can[tem] && can[to]) {
						auto &arr = rev[to];
						for (vector <ll>::iterator Iter = rev[to].begin(); Iter != rev[to].end(); Iter++) {
							if (*Iter > i) {
								rev[to].erase(Iter);
								break;
							}
						}
					} else {
//						debug(tem);debug(to);
						puts("NO");ff = 1;
						break;
						
//						continue;
					}
				}
			}
			if (ff != 1) {
//				debug(1);
				puts("YES");
			}
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

