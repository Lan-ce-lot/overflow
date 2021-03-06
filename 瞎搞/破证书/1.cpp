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
ll a[maxn], n;
struct node {
	int num, xz, tk, yy;
	int sum;
}N[maxn];
bool cmp(node a, node b) {
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	} else if (a.yy != b.yy) {
		return a.yy > b.yy;
	} else if (a.tk != b.tk) {
		return a.tk > b.tk;
	} else if (a.xz != b.xz) {
		return a.xz > b.xz;
	} else {
		return a.num < b.num;
	}
}
/*
5
20200001 89 78 84 
20200002 97 86 88
20200003 87 95 78
20200004 76 84 86
20200005 88 84 94

*/
void solve()
{
	int *p = new int(10);
	cout << *p <<endl;
	delete p;
	cout << *p <<endl;
	cin >> n;
	int cont = 0;
	for (int i = 1; i <= n; i++) {
		node tem;
		cin >> tem.num >> tem.xz >> tem.tk >> tem.yy;
		if (tem.yy >= 80 && tem.xz >= 80 && tem.tk >= 80) {
			tem.sum = tem.yy + tem.xz + tem.tk;
			N[cont++] = tem;
		}
		
//		N[cont++].sum = N[cont].xz + N[cont].tk + N[cont].yy;
	}
	sort(N, N + cont, cmp);
	if (cont == 0) {
		cout << "NULL";
	} else {
		for (int i = 0; i < cont; i++) {
			cout << N[i].num << ' ' << N[i].sum << endl;
		}
	}
}/*
06:17:22
80 
00:00:01
2
*/ 
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

