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
int idx[maxn];
int par[maxn];
int find(int x) {
	if (x == idx[x]) return idx[x];
	else {
		idx[x] = find(idx[x]);
		return idx[x];
	}
}

void unite(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		idx[a] = b;
	}
}

void solve()
{
	t = read();
	while (t--) {
		
		int flag = 0;
		n = read();
		for (int i = 0; i <= n; i++) idx[i] = i;
		string a1, b1;
		cin >> a1 >> b1;
		for (int i = 0; i < n; i++) {
			if (a1[i] > b1[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0, j = 1; i < n; i++) {
			idx[i] = i;
			while (j < n && a1[i] == a1[j] && a1[j] <= b1[i]) {
				idx[i] = j;
				j++;
			}
		}
		int ans = 0;
		for (int i = 0, j = 0; i < n; i++) {			
			while (a1[i] == b1[i] && i < n) {
				i++;
			}
			if (i >= n) break;
//			if (i == n - 1) {
//				ans ++;
//				break;
//			}
			if (a1[i] == a1[i + 1]) {
				unite(i, i + 1);
			}
//			cout << i << idx[i] << ' ' << idx[i + 1] << endl;
			if (a1[i] != b1[i]) {
				char c = b1[i];
				string tem(idx[i] - i + 1, c);
				a1 = a1.substr(0, i) + tem + a1.substr(idx[i] + 1, n - idx[i] + 1);	
			}
			ans++;
		}
		cout << ans << endl;
		
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

