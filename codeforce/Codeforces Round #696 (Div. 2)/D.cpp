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
#define debug(a) cout<<#a<<"="<<a<<endl;
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
int t, n, a[maxn];
int pre[maxn], nex[maxn];

void solve()
{
	t = read();
	while (t--) {
		n = read();
		for (int i = 0; i < n + 10; i++) {
			pre[i] = nex[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		
		for (int i = 1; i <= n; i++) {
			if (pre[i - 1] > a[i]) {
				pre[i] = INF / 2;
			} else {
				pre[i] = a[i] - pre[i - 1];
			}
		} 
		
		for (int i = n; i >= 1; i--) {
			if (nex[i + 1] > a[i]) {
				nex[i] = INF;
			} else {
				nex[i] = a[i] - nex[i + 1];
			}
		}
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if (pre[i] == nex[i + 1]) {
				flag = 1;
				break;
			} else {
				int A = a[i], B = a[i + 1];
				
				if (A >= nex[i + 2] && B >= pre[i - 1]) {
					A -= nex[i + 2];
					B -= pre[i - 1];
					if (A - B == 0) {
						flag = 1;
						break;
					}
				}
			}
		}
		
		if (flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
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

