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
int t, n, a, b ,c, tem;
vector<int> G[3];
void solve()
{
	a = read(), b = read(), c = read();
	for (int i = 0; i < a; i++) {
		tem = read();
		G[0].push_back(tem);
	} 
	for (int i = 0; i < b; i++) {
		tem = read();
		G[1].push_back(tem);
	} 
	for (int i = 0; i < c; i++) {
		tem = read();
		G[2].push_back(tem);
	} 
	sort(G[0].begin(),G[0].end());
	sort(G[1].begin(),G[1].end());
	sort(G[2].begin(),G[2].end());	
	ll ans = 0;
	while ((a > 0 && b > 0) || (a > 0 && c > 0) &&(b > 0 && c > 0)) {
		int tem_0 = G[0][a - 1];
		int tem_1 = G[1][b - 1];
		int tem_2 = G[2][c - 1];
		if (tem_0 >= tem_1 && tem_0 >= tem_2) {
			G[0].pop_back();
			a--;
			
			if (tem_1 >= tem_2) {
				G[1].pop_back();
				b--;
				ans += tem_1 * tem_0;
			} else {
				G[2].pop_back();
				c--;
				ans += tem_2 * tem_0;
			}
		}
		if (tem_1 >= tem_0 && tem_1 >= tem_2) {
			G[1].pop_back();
			b--;
			if (tem_0 >= tem_2) {
				G[0].pop_back();
				a--;
				ans += tem_1 * tem_0;
			} else {
				G[2].pop_back();
				c--;
				ans += tem_1 * tem_2;
			}
		}
		if (tem_2 >= tem_0 && tem_2 >= tem_1) {
			G[2].pop_back();
			c--;
			if (tem_0 >= tem_1) {
				G[0].pop_back();
				a--;
				ans += tem_2 * tem_0;
			} else {
				G[1].pop_back();
				b--;
				ans += tem_2 * tem_1;
			}
		}
	}
	cout << ans << '\n' ; 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

