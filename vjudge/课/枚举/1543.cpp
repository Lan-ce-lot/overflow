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
const int maxn = 40005;
//sacnf("%lf") printf("%f")

int t, n, a, b, c, d, ans;
int vis[maxn];
void get_f(int a, int b, int c)//23 28 33
{
	int star_a = a % 23;
	int star_b = b % 28;
	int star_c = c % 33;
	for (int i = star_a; i < maxn; i += 23)
	{
		vis[i] ++;
	}
	for (int i = star_b; i < maxn; i += 28)
	{
		vis[i] ++;		
	}
	for (int i = star_c; i < maxn; i += 33)
	{
		vis[i] ++;
	}
	for (int i = d + 1; i < maxn; i++)
	{
		if (vis[i] == 3)
		{
			ans = i - d;
			return;
		}
	}
}

void solve()
{
	int con = 0;
	while (~scanf("%d %d %d %d", &a, &b, &c, &d), a >= 0)
	{
		memset(vis, 0, sizeof vis);
		ans = 0;
		if (a == 0 && b == 0 && c == 0)
		{
			
			ans = 21252 - d;
		}
		else
		{
			get_f(a, b, c);
		}
		con++;
		printf("Case %d: the next triple peak occurs in %d days.\n", con, ans);
	}
}

int main()
{
//        debug(pow(3.0, 1/3));
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

