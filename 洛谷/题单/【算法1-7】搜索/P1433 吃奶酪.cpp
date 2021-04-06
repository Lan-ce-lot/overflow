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
struct node {
	double x, y;
}G[maxn];
double f[20][35005];

double get(node A, node B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> G[i].x >> G[i].y;
	}
	int all = (1 << n) - 1;
	// 注意浮点数的最大值 
	memset(f, 127, sizeof f);
	for (int s = 1; s <= all; s++) {
		for (int i = 1; i <= n; i++) {
			// s 不包含i 
			if((s & (1 << (i - 1))) == 0) continue;
			// s 只有为自己 边界 
			if(s == (1 << (i - 1))) {f[i][s] = 0;continue;}
			for (int j = 1; j <= n; j++) {
				// s 不包含i 或 i == j 
				if ((s & (1 << (j - 1))) == 0 || i == j) continue;
				f[i][s] = min(f[i][s], f[j][s ^ (1 << (i - 1))] + get(G[i], G[j]));
			}
		}
	}
	double ans = INF;
	for (int i = 1; i <= n; i++)
		ans = min(f[i][all] + get(G[i], {0, 0}), ans);
	printf("%.2lf\n", ans);
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

