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
int base;
vector<int> ANS;
bool f(int n, int m) {
	
	while (n) {
		ANS.push_back(n % m);
		n /= m;
	}
	reverse(ANS.begin(),ANS.end());
//	vector<int> REV_ANS = ANS;
	for (int i = 0, j = ANS.size() - 1; i < ANS.size() && j >= 0; i++, j--) {
		
		if (ANS[j] != ANS[i]) {
			return 0;
		}
	}
	return 1;
}
void solve()
{
	n = read(), base = read();
	
	
	int flag = 0;
	if (f(n, base)) {
		puts("Yes");
		for (int i = 0; i < ANS.size(); i++) {
			cout << ANS[i] ;
			if (i == ANS.size() - 1) {
				puts("");
			} else {
				cout << ' ';
			}
		}
	} else {
		puts("No");
		for (int i = 0; i < ANS.size(); i++) {
			cout << ANS[i] ;
			if (i == ANS.size() - 1) {
				puts("");
			} else {
				cout << ' ';
			}
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

