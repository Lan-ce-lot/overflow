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
int t, n, m;
int ans = 0;
int pa[maxn], pa1[maxn];
int height[maxn];

int find(int x) {
	if (x == pa[x]) {
		return x;
	} else {
		return pa[x] = find(pa[x]);
	}
	
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		pa[x] = y;
	}
}


void solve()
{
	n = read();
	m = read();
	char cc[3];
	for (int i = 0; i <= 2 * n; i++) {
		pa[i] = i;
//		pa1[i] = i;
//		height[i] = 0;
	}
	while (m--) {
		scanf("%s", cc);
		int a = read(), b = read();
		if (cc[0] == 'E') {
//			debug(1);
			unite(a + n, b);
			unite(b + n, a);
		} else if (cc[0] == 'F') {
			unite(a, b);
		}
	}
	for(int i=1;i<=n;i++){
        if(pa[i]==i) ans++;
    }
	cout << ans << "\n";
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

