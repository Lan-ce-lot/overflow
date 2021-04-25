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
const int maxn = 400000+10;
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
int t, n, f[maxn], u[maxn], v[maxn], tot;
unordered_map<int, int> me;
int find(int x) {
	if (x == f[x]) {
		return x;
	}
	return f[x] = find(f[x]);
}
//int ind(int x) {
//	int k = x % 200003;
//	for (; me[k] != x && me[k];) k++;
//	me[k] = x;
//	return k;
//}
int ind(int x) {
	if (!me.count(x)) me[x] = ++ tot;
	return me[x]; 
}
void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		f[x] = y;
	}
}



void solve()
{
	cin >> t;
	while (t--) {
		cin >> n;
		
		int con = 0;
		me.clear(), tot = 0;
		for (int i = 1; i <= 400001;i ++) {
			f[i] = i;
//			me[i] = 0;
		}
//		ind(200004);
//		ind(1);
		int ff = 0;
		for (int i = 1; i <= n; i++) {
			int a, b, e;
			cin >> a >> b >> e;
			
			if (e) {
				Union(ind(a), ind(b));
			} else {
				u[++con] = ind(a);
				v[con] = ind(b);
			}
		}
		while (con) {
			if (find(u[con]) == find(v[con])) {
				ff = 1;break;
			}con--;
		}
		puts(ff ? "NO" : "YES");
	}
} 

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

