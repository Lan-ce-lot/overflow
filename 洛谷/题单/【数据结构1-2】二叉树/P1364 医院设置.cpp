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
int G[105][105];
int w[10005];
int d[105][105];
void solve()
{
	n = read();
	memset(G, INF, sizeof G);
	for (int i = 1; i <= n; i++) {
		int a = read(), b = read(), c = read();
		if (b) G[i][b] = 1, G[b][i] = 1;
		if (c) G[i][c] = 1, G[c][i] = 1;

		w[i] = a;
	}
	for (int k = 0; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
	int minn = INF, sum;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= n; j++) {
			if(i!=j&&G[i][j]!=INF) sum+=w[j]*G[i][j];
		}
		if(minn>sum) minn=sum;
	}
	cout<<minn<<endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

