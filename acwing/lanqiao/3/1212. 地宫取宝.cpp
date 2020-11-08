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
int G[1005][1005], f[55][55][14][14];
void solve()
{
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m; j++) {
			G[i][j] = read();
			G[i][j]++;
			
		}
	}
	f[1][1][1][G[1][1]] = 1;
	f[1][1][0][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			for (int u = 0; u <= k; u++) {
				
				for (int v = 0; v <= 13; v++) {
					int &val = f[i][j][u][v];
                    val = (val + f[i - 1][j][u][v]) % mod;
                    val = (val + f[i][j - 1][u][v]) % mod;
                    if (u > 0 && v == G[i][j])
                    {
                        for (int c = 0; c < v; c ++ )
                        {
                            val = (val + f[i - 1][j][u - 1][c]) % mod;
                            val = (val + f[i][j - 1][u - 1][c]) % mod;
                        }
                    }					
				}
			}
			
			
		}
	}
    int res = 0;
    for (int i = 0; i <= 13; i ++ ) res = (res + f[n][m][k][i]) % mod;

    cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

