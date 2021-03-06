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
const int maxn = 30005;
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
struct node {
	ll num, sore, loc, loc_r, z_r;
	bool operator < (const node & A) {
		if (sore == A.sore) {
			return num < A.num;
		}
		return sore > A.sore;
	}
}N[maxn], tmp[maxn];
void solve()
{	
	t = read();
	ll index = 0, endd = 0;
	ll in_ = 0;
	while (t--) {
		in_++;
		n = read();
		endd = index + n;
		for (int i = 0; i < n; i++) {
			tmp[i] = {read(), read(), in_, 1, 1};
		}
		
		sort(tmp, tmp + n);
//		for (int i = 0; i < n; i++) {
//			cout << tmp[i].num << ' ' << tmp[i].sore << endl;
//		}
		int con = 1;
		tmp[0].loc_r = 1;
		for (int i = 1; i < n; i++) {
			if (tmp[i - 1].sore == tmp[i].sore) {
				tmp[i].loc_r = tmp[i - 1].loc_r;
			} else {
				tmp[i].loc_r = i + 1;
			}
//			cout << tmp[i].num << ' ' << tmp[i].z_r << ' ' << tmp[i].loc << ' ' << tmp[i].loc_r <<  ' ' << endl;
		}
		for (int i = index, j = 0; i < endd && j < n; i++, j++) {
			N[i] = tmp[j];
		}
		index = endd;
	}
//	debug(endd);
	cout << endd << endl;
	sort(N, N + endd);
	N[0].z_r = 1;	
	for (int i = 0; i < endd; i++) {
		if (N[i - 1].sore == N[i].sore) {
			N[i].z_r = N[i - 1].z_r;
		} else {
			N[i].z_r = i + 1;
		}
		printf("%013lld", N[i].num);
		cout << ' ' << N[i].z_r << ' ' << N[i].loc << ' ' << N[i].loc_r << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

