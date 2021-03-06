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
int t, n, a[maxn], min_s = INF, num = 0;
double r, p;
vector<int> G[100005];
void dfs(int u, int step) {
	if (G[u].size() == 0) {
		if (min_s > step) {
			min_s = step;
			num = 1;
		} else if (min_s == step){
			num++;
		}
		return ;	
	}
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		dfs(to ,step + 1);
	} 
}
void solve()
{
	while (cin >> n >> p >> r) {
		for (int i = 0; i < n; i++) {
			t = read();
			for (int j = 0; j < t; j++ ){
				G[i].push_back(read());
			}
		}
		dfs(0, 0);
		for (int i = 0; i < min_s; i++) {
			p += r * 0.01 * p;
		}
		printf("%.4lf %d\n", p, num);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

