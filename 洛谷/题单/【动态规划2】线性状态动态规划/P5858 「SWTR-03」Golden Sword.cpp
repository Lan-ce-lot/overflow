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
ll t, n,  w, s, a[maxn], f[2][maxn];
ll q[maxn], h;
void solve()
{
	cin >> n >> w >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i=0;i<=1;i++)for(int j=0;j<=w;j++)f[i][j]=-1e15; 
	f[0][0]=0;
	int p = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= w; j++) f[p][j] = -1e17;
		h = t = 1;
		q[h] = w;
		for (ll j = w; j >= 1; j--) {
			while (h <= t && q[h] > min(j + s - 1, w))h++;
			while (h <= t && f[p ^ 1][q[t]] < f[p ^ 1][j - 1]) t--;
			q[++t] = j - 1;
			f[p][j] = f[p^1][q[h]] + a[i] * j;
		}
		p^=1;
	}
	
	cout << *max_element(f[n & 1], f[n & 1] + w + 1) << endl;
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

