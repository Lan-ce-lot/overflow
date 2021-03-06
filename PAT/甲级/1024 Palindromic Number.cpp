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
ll t, n, k;
ll ans, step;
/*
大数相加
 
*/
vector<int> N; 
vector<int> add(vector<int> A, vector<int> B) {
	reverse(A.begin(), A.end());
	
	ll jw = 0;
	vector<int> RES;
	if (A.size() > B.size()) {
		add(B, A);
	} else {
		for (int i = 0; i < A.size(); i++) {
			RES.push_back((jw + A[i] + B[i]) % 10);
			jw = (jw + A[i] + B[i]) / 10;
		}
	}
	if (jw) {
		RES.push_back(jw);
		jw = 0;
	}
	reverse(RES.begin(), RES.end());
	return RES;
} 

void solve()
{
	n = read(), k = read();
	while (n) {
		N.push_back(n % 10);
		n /= 10;
	}
	step = 0;
	while (step < k) {
		
		bool flag = 0;
		for (int i = 0, j = N.size() - 1; i < N.size() && j > 0; i++, j--) {
			if (N[i] != N[j]) {
				flag = 1;break;
			}
		} 
		if (flag == 0) {
			break;
		}
		step++;N = add(N, N);
		
	}
	for (auto it : N) {
		cout << it;
	}
	
	cout << endl << step << endl;
}
 
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

