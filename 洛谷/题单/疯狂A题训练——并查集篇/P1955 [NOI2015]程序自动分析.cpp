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
const int maxn = 1000005 * 3;
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
int pa[maxn];

struct node {
	int x, y, e;
}N[maxn];
int lsh[maxn], tot = 0;
bool cmp(node a,node b){
    return a.e>b.e;
}
int find(int x) {
	if (x == pa[x]) return x;
	else return pa[x] = find(pa[x]);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		pa[x] = y;
	}
}
void solve()
{
	t = read();
	while (t--) {
		n = read();
		
		tot = 0;
		for (int i = 1; i <= n; i++) {
			int a = read(), b = read(), c = read();
			N[i] = {a, b, c};
			lsh[tot++] = a;
			lsh[tot++] = b;
		}
		// 排序
		// 去重
		// 转lower_bound二分引索 
		sort(lsh, lsh + tot);
		
		int res = unique(lsh, lsh + tot) - lsh;// 去重后元素个数
		
		for (int i = 1; i <= n; i++) {
			N[i].x = lower_bound(lsh, lsh + res, N[i].x) - lsh + 1;
			N[i].y = lower_bound(lsh, lsh + res, N[i].y) - lsh + 1;
			
		} 
		for (int i = 1; i <= res; i++) {
			pa[i] = i;
		}
		int flag = 1;
		sort(N + 1, N + n + 1, cmp); 
		for (int i = 1; i <= n; i++) {
			int aa = find(N[i].x), bb = find(N[i].y);
			
			if (N[i].e == 1) { // == 
			
				// pass
				unite(N[i].x, N[i].y);
			} else if (aa == bb) { // != 
				// pass
				flag = 0;
				break;
			}
		}
		
		if (flag) {
			puts("YES");
		} else {
			puts("NO");
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

