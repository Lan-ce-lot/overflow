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
int A[maxn], B[maxn], C[maxn];
ll sumA[maxn], sumB[maxn], sumC[maxn], ss[maxn]; 
ll ans = 0;
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		A[i] = read();
	} 
	for (int i = 1; i <= n; i++) {
		B[i] = read();
	} 
	for (int i = 1; i <= n; i++) {
		C[i] = read();
	} 
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	sort(C + 1, C + n + 1);
	ss[0] = 0;
	A[n + 1] = INF;
	B[n + 1] = INF;
	C[n + 1] = INF;
	A[0] = -INF;
	B[0] = -INF;
	C[0] = -INF;
	n++;
/*
20
1 3 4 7 10 10 12 12 12 12 13 13 14 14 14 15 18 19 19 20
1 2 2 2 2 3 5 6 8 9 9 10 10 10 10 11 11 12 13 18
0 2 2 4 5 5 6 6 7 9 9 9 11 11 16 16 18 19 19 20
*/
	for (int i = 1; i <= n - 1; i++) {
		
		// bin
		int tar = B[i];
		int l = 0, r = n, mid; 
		while (l < r) {
			mid = l + r + 1>> 1;
			if (A[mid] < tar) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		// l
		//		n - l + 1
		sumB[i] = l;
		ss[i] = ss[i - 1] + sumB[i];
	}
	
	for (int i = 1; i <= n - 1; i++) {
		// bin
		int tar = C[i];
		int l = 0, r = n, mid; 
		while (l < r) {
			mid = l + r + 1 >> 1;
			if (B[mid] < tar) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		// l
		// n - l + 1
		sumC[i] = ss[l];
		ans += sumC[i];
	}
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*
3
4 1 5
9 5 5
7 6 4
*/
