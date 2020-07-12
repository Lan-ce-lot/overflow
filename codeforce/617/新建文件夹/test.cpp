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

ll q_pow(int a, int x)//a的x次方
{
    ll res = 1;
    while (x)
    {
        if (x & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }

    return res % mod;
}

int a[maxn] = {1, 3, 4, 5, 7, 8, 9, 9, 10, 10};
int bin(int n, int f)
{
    int l = 0, r = n - 1;

    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > f)
        {
            r = mid - 1;
        }
        else if (a[mid] < f)
        {
            l = mid + 1;
        }
        else
            return mid;
    }
    return l;
}

int t, n, x;
int main()
{
    while(cin >> t)
    cout << bin(10, t) <<endl;
//    ios::sync_with_stdio(false);
    return 0;
}

