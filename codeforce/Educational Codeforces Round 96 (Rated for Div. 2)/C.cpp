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
const int maxn = 200005;
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
bool vis[maxn];
void solve()
{
	t = read();
	while (t--) {
		n = read();
		memset(vis, 0, sizeof vis);
		cout << 2 << endl;
		int tem = 0;
		if (n == 2) {
			cout << 1 << ' ' << 2 << endl;
			continue;
		} 
		else if (n == 3) {
			cout << 1 << ' ' << 3 << endl;
			cout << 2 << ' ' << 2 << endl;continue;
		}
		if (n & 1) {
			for (int i = n, tem = i; i > 1; i--) {
				if (i == 2) {
					cout << 1 << ' '  << tem << endl;
				} else if ((n - i) % 2 == 0) {
					vis[tem] = 1, vis[tem - 2] = 1;
					cout << tem - 2 << ' ' << tem << endl;tem = tem - 1;
				} else {
					if (vis[tem] == 0) {
						cout << tem << ' ' << tem << endl;
					} else {
						cout << tem - 2 << ' ' << tem << endl;tem = tem - 1;
					}
					
				}
				
			}	
		} else {
			for (int i = n, tem = i; i > 1; i--) {
				if (i == 2) {
					cout << 1 << ' ' << tem << endl;
				}
				else if ((n - i) % 2 == 0) {
					vis[tem] = 1, vis[tem - 2] = 1;
					cout << tem - 2 << ' ' << tem << endl;tem = tem - 1;
				} else {
					if (vis[tem] == 0) {
						cout << tem << ' ' << tem << endl;
					} else {
						cout << tem - 2 << ' ' << tem << endl;tem = tem - 1;
					}
				}
				
			}			
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

