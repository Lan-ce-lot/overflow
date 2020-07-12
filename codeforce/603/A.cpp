/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

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
int a[3];
void solve()
{
    a[0] = read();
    a[1] = read();
    a[2] = read();
    sort(a, a + 3);
    if (a[0] == a[1])
    {
        cout << min(a[2] / 2 + a[0], 2 * a[1])<< endl;
        return;

    }
    if (a[1] == a[2])
    {
        cout << a[0] / 2 + a[1] << endl;
        return;
    }
    else if(a[0] + a[1] <= a[2])
    {
        cout << min(a[0] + a[1], a[2]) << endl;
        return;
    }
    else
    {
        int temp = a[0] + a[1] - a[2];
        cout << min(temp / 2, a[0]) + a[2] << endl;
    }
}


int t, n;
int main()
{
//    ios::sync_with_stdio(false);
    t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}

