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
int t, n, c;
int a[maxn];
bool test(int x)
{
	int con = 1, cur = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - a[cur] >= x)
		{
			con++;
			cur = i;
		}
	}
//	cout << x;
//	debug(con);
	if (con >= c)
	{
		return 1;
	}
	return 0;
 } 
int bin(int l, int r)
{
	while (l < r)
	{
		int mid = l + r + 1>> 1;
//		cout << l << " " << r;
		if (!test(mid))// 可以再减小 
		{
			r = mid - 1;
		}
		else
		{
			l = mid;
		}
//		debug(l); 
	}
	return l;
}
/*
5 3
1
2
3
4
5


5 5
1 2 3 4 5
*/

void solve()
{
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i ++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	cout << bin(1, 1e9) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

