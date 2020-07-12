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
const int maxn = 500005;
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
int e[maxn * 4];
int a[maxn];

int lowbit(int x) {
	return x & -x;
}
void update(int x, int k) {
	while (x <= n) {
		e[x] += k;
		x += lowbit(x); 
	}
}

int query(int x) {
	int res = 0;
	while (x > 0) {
		res += e[x];
		x -= lowbit(x);
	}
	return res;
}




void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
//	for (int i = 1; i <= n; i++) cout << a[i];
	for (int i = 1; i <= n; i++) {
		update(i, a[i]);
	}
//	for (int i = 1; i <= n; i++) cout << e[i] <<' ';
	for (int i = 0; i < m; i++) {
		int x, y, z;
//		cin >> x >> y >> z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			update(y, z);
		} else {
			int te = query(z);
//			cout << te <<endl;
			int tl = query(y - 1);
			cout << query(z) - query(y - 1) << endl;
//			cout << te - tl << endl;
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

