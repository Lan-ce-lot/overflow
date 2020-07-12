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
//==============================================================

vector<PII> A;//底数和指数

void divide(int x)
{
    A.clear();
    for (int i = 2; i <= x / i; i++)//底数和指数
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s++;
//            cout << i << ' ' << s << endl;
            A.push_back({i, s});
        }
    }
    if (x > 1) A.push_back({x, 1});//cout << x << ' ' << 1 << endl;
}


void solve()
{
	cin >> t;
	n = 0;
	while (t--) {
		cin >> n;
//		n++;cout << n << endl;
		if (n == 1) {
			puts("FastestFinger");
			continue;
		}
		
		if (n == 2 || n & 1) {
			puts("Ashishgup");
			continue;
		}
		
		divide(n);
		int f_2 = 0, f_j = 0;
		for (int i = 0; i < A.size(); i++) {
//			cout << A[i].first << " " << A[i].second << endl;
			if (A[i].first == 2) {
				f_2 += A[i].second;
				
			}
			else {
				f_j += A[i].second;
			}
			
		}
		if ((f_2 >= 2 && f_j > 0) || f_j >= 2) {
			puts("Ashishgup");
		}
		else {
			puts("FastestFinger");
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

