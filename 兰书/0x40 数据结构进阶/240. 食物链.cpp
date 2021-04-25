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
int t, n, k;
int pa[maxn];
int find(int x) {
	if (x != pa[x]) return pa[x] = find(pa[x]);
	return x;
}
void add(int x, int y ) {
	x = find(x), y = find(y);
	if (x != y) {
		pa[x] = y;	
	}
}
void solve()
{
	cin >> n >> k;
	int ans = 0, d, x, y;
	for (int i = 1; i <= n * 3; i++ ) {
		pa[i] = i;
	}
	for (int i = 0; i < k; i++) {
		cin >> d >> x >> y;
		if (x > n || y > n) {
			ans++;
			continue;
		}
		if (d == 1) {
			// 同类
			//  
			if (find(x + n) == find(y) || find(y + n) == find(x)) {
				ans++;
				continue;
			}
			add(x, y);
			add(x + n, y + n);
			add(x + n * 2, y + n * 2);
		} else {
			if (x == y || find(x) == find(y) || find(y + n) == find(x)) {
				ans++;
				continue;
			} 
			add(x, y + 2 * n);
			add(x + n, y);
			add(x + 2 * n, y + n);
		}
	}
	/*
		1 同类
		2 食物
		3 捕食 
	*/
	cout << ans << endl;
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

