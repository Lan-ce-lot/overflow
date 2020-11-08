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
inline bool read(int &x) {
    char c=getchar();
    if(c==EOF)return false;
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return true;
}
int t, n;
int a[maxn], d1[maxn], d2[maxn], f[maxn], i, j, x;
void solve()
{

	while (~scanf("%d", &a[++n]));
//	cout << n;
	n--;
//	while (~scanf("%d", &a[++n]));
//	cout << n;
//n--;
//	memset(d1, 0, sizeof(d1));
//	memset(d2, INF, sizeof(d2));
//	for (int i = 1; i <= n; i++) {
//		
//		*upper_bound(d1 + 1, d1 + 1 + n, a[i], greater<int>()) = a[i];
//		*lower_bound(d2 + 1, d2 + 1 + n, a[i]) = a[i];
//	}
//	for (int i = 0; i <= n * 2; i++) cout << d1[i] << ' ' ;
//	puts("");
//	for (int i = 0; i <= n * 2; i++) cout << d2[i] << ' ' ;
//	cout << lower_bound(d1 + 1, d1 + n + 1, INF) - d1 - 1 << endl;
//	cout << lower_bound(d2 + 1, d2 + n + 1, INF) - d2 - 1 << endl;
	
	
	int len1 = 1, len2 = 1;
	d1[1] = d2[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (d1[len1] >= a[i]) d1[++len1] = a[i];
		else *upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>()) = a[i];
	}
	for (int i = 2; i <= n; i++) {
		if (d2[len2] < a[i]) d2[++len2] = a[i];
		else *lower_bound(d2 + 1, d2 + 1 + len2, a[i]) = a[i];
	}
	printf("%d\n%d", len1, len2);
	return;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

