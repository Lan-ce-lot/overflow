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
int t, n, m;
ll a[maxn];
map<int, int> M;
set<int> G_4;
set<int> G_24;
set<int> G_6;
set<int> G_8;
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		M[a[i]] ++;
	}
//	for (auto it : M) cout << it.first << ' ' << it.second << endl;
	m = read();
	char ss1;
	int ss2;
	
	for (auto it : M) {
		if (it.second >= 8) {
			G_8.insert(it.first);
		} else if (it.second >= 6){
			G_6.insert(it.first);
		} else if (it.second >= 4) {
			G_4.insert(it.first);
		} else if (it.second >= 2){
			G_24.insert(it.first);
		}
	}
	
	
	for (int i = 1; i <= m; i++) {
//		scanf("%c%")
		
		scanf("%c %d", &ss1, &ss2);
		getchar();
//		cout << ss2<< endl;
		int tt = ss2;
		if (ss1 == '-') {
			M[tt]--;
		} else {
			M[tt]++;
		}
//		debug(M[tt]);
		if (M[tt] >= 8) {
			G_8.insert(tt);
			G_6.erase(tt);
		} else if (M[tt] >= 6) {
			G_8.erase(tt);
			G_4.erase(tt);
			G_6.insert(tt);
		} else if (M[tt] >= 4) {
			G_6.erase(tt);
			G_24.erase(tt);
			G_4.insert(tt);
		} else if (M[tt] >= 2) {
//			G_2.erase(tt);
			G_4.erase(tt);
			G_24.insert(tt);
		} else {
			G_24.erase(tt);
		} 

		if (G_8.size() > 0) {
			puts("YES");
//			debug(1);
		} else if ((G_6.size() > 0 && (G_4.size() >= 1 || G_24.size() >= 1))) {
			puts("YES");
//			debug(2);
		} else if (G_6.size() >= 2) {
			puts("YES");
		} else if ((G_24.size() >= 2 && G_4.size() >= 1)) {
			puts("YES");
//			debug(3);
		} else if (G_4.size() >= 2) {
			puts("YES");
		}
		else {
			puts("NO");
//			cout << G_24.size() << ' '<< G_4.size() << endl;
		}
//		debug(i);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

