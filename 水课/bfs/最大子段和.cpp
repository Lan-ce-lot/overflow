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
ll num[maxn];
void solve()
{
	
	
	cin >> n;
	ll tt = 0, maxx = -10000000000; 
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		maxx = max(maxx, num[i]);

	}
	if (maxx <= 0) {
		cout << maxx << endl;
		return;
	}
	ll sum = 0, temp = 0,index_s = 0, index_e = 0, ans = -10000000000;
	for (int i = 0; i < n; i++) {
		if (sum + num[i] < 0) {
			sum = 0;
			temp = i + 1;
		} else {
			sum += num[i];
		}
		ans = max(ans, sum);
		if (ans < sum) {
			index_s = temp;
			index_e = i;
		} 
	} 
//	cout << index_s << ' ' << index_e <<endl;// ±ÕÇø¼ä 
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
