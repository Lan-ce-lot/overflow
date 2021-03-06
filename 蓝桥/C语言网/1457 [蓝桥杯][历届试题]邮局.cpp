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
int t, n, m, k;
int ans[55], cur[55], tmpans[55];
double tmpdis[100];
PII p[100], v[100];
double mp[1004][1005];
double dis(PII a, PII b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

/*

*/
bool vis[maxn];
double res = INF;
void dfs(int u, int con, int tmpans[], double tmpdis[]) {
	if (con == k) {
		double sum = 0;
		for (int i = 1; i <= n; i++) sum += tmpdis[i];
		if (sum < res) {
			res = sum;
			for (int i = 1; i <= k; i++) {
				ans[i] = tmpans[i];
			}
		}
		return;
	} else if (u <= m && k - con <= m - u && vis[u] == 0) {
			// ²»
		bool flag = 0, flag1 = 0;
		double neww[55];
		for (int i = 1; i <= n; i++) {
			neww[i] = tmpdis[i];
		}
		for (int i = 1; i <= n; i++) {
			if (tmpdis[i] > mp[i][u + 1]) {
				tmpdis[i] = mp[i][u + 1];
				flag = 1;
			}
		}
		tmpans[con + 1] = u + 1;
		if (flag) {
			dfs(u + 1, con + 1, tmpans, tmpdis);
		} else if (con == 0) {
			vis[u] = 1;
		}
		dfs(u + 1, con, tmpans, neww); 
	}
}

void solve()
{
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++) {
		v[i].first = read(), v[i].second = read();
		
	}
	for (int i = 1; i <= m; i++) {
		p[i].first = read(), p[i].second = read();	
	}
	for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            mp[i][j] = dis(v[i], p[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
    	tmpdis[i] = INF;
	}
    dfs(0, 0, tmpans, tmpdis);
    for (int i = 1; i <= k; i++) {
    	printf("%d ", ans[i]);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

