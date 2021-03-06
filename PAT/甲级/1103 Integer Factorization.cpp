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

int t, n, k, p, ans[maxn], e[maxn], fasum = -1, tmpans[maxn];
// n, 
void dfs(int index, int step, int sum, int allsum) {
	if (step == k) {
		if (allsum == n && sum > fasum) {
			for (int i = 0; i < k; i++) {
				ans[i] = tmpans[i];
				fasum = sum;
			}
		}
		return ;
	}
	
	
	for (;index > 0;index--) {
		if (allsum + e[index] <= n) {
			tmpans[step] = index;
			dfs(index, step + 1, sum + index, allsum + e[index]);
		}
	}
	
}
int mmax = 0;
void solve() {
	while (cin >> n >> k >> p) {
		mmax = int(pow(n, 1.0/p));
//		cout << mmax<< endl;
		for (int i = 1; i <= mmax; i++) {
			e[i] = pow(i, p);
//			cout << e[i] << endl;
		}
		// k, 
		dfs(mmax, 0, 0, 0);
		if (fasum == -1) {
			cout << "Impossible" << endl;continue;
		}
		cout << n << " = ";
		for (int i = 0; i < k; i++) {
			cout << ans[i] << '^' << p;
			if (i == k - 1) {
				cout << endl;
			} else {
				cout << " + ";
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

