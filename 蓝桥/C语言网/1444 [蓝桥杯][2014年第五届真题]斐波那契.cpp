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

struct matrix {
	ll a[2][2];
}; 
ll n, m, p;
ll fib_m;
ll mul_mod(ll a, ll b, ll p) {
	ll res = 0;
	while (b) {
		if (b & 1)
			res = (res + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return res;
}

matrix mul_mat(matrix first, matrix second) {
	matrix res;
	memset(res.a, 0, sizeof res.a);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res.a[i][j] = (res.a[i][j] % p + 
				mul_mod(first.a[i][k], second.a[k][j], p) % p) % p;
			}
		}
	}
	return res;
}

matrix pow_mat(matrix mat, ll n) {
	matrix res = 
	{1, 0, 
	0, 1};
	while (n > 0) {
		if (n & 1)
			res = mul_mat(res, mat);
		mat = mul_mat(mat, mat);
		n >>= 1;
	}
	return res;
}

ll quick_fib(ll c) {
	matrix mat = {{1, 1, 1, 0}}, tmp = pow_mat(mat, c);
	return tmp.a[0][1];
}

//*******************

matrix mul_mat_1(matrix first, matrix second) {
	matrix res;
	memset(res.a, 0, sizeof res.a);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res.a[i][j] = (res.a[i][j] + first.a[i][k] * second.a[k][j]);
			}
		}
	}
	return res;
}

matrix pow_mat_1(matrix mat, ll n) {
	matrix res = {{1, 0, 0, 1}};
	while (n > 0) {
		if (n & 1) res = mul_mat_1(res, mat);
		n >>= 1;
		mat = mul_mat_1(mat, mat);
	}
	return res;
}

ll quick_fib_1(ll c) {
	matrix mat = {{1, 1, 1, 0}}, tmp = pow_mat_1(mat, c);
	return tmp.a[0][1];	
}

void solve()
{
	scanf("%lld %lld %lld", &n, &m, &p);
	if (m > n + 2) {
		printf("%lld", (quick_fib(n + 2)) % p - 1);
		return;
	} else {
		fib_m = quick_fib_1(m);
		printf("%lld", (quick_fib_1(n + 2)) % fib_m % p - 1);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

