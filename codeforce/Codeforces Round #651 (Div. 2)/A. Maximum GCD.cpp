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
const int maxn = 10005;
//sacnf("%lf") printf("%f")

int lowbit(int n) {
	return n & -n;
}
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
int a[maxn];
int jj[maxn];
int oo[maxn];
int ans ;
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
//==============================================================



void solve()
{
//	__gcd(n, m);
	cin >> t;
	n = 1;
	while (t--) {
		n++;cout << n;
//		cin >> n;
        divide(n);
        for (auto i : A)
            cout << i.first << ' ' << i.second << endl;
        puts("");
		if (n == 1) {
			puts("FastestFinger");
			continue;
		}
		if (n == 2) {
			puts("Ashishgup");
			continue;
		}
		if (n & 1) {
			puts("Ashishgup");
			continue;
		} 
		else {
			if (n - lowbit(n) == 0) {
				puts("FastestFinger");
			}
			else {
				if (n % 4 == 0) {
					puts("Ashishgup");
				}
				else {
					if (n != 10 && n % 10 == 0) {
						puts("Ashishgup");
					}
					else
					puts("FastestFinger");
				}
				
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

