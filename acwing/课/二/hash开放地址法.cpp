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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 200003;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 200005;

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

int h[maxn];
int find(int x)
{
    int k = (x % mod + mod) % mod;
    while (h[k] != INF && h[k] != x)
    {
        k++;
        if (k == maxn)
            k = 0;
    }
    return k;
}


//==============================================================

void solve()
{
    char fl[2];
    cin >> n;
    memset(h, 0x3f, sizeof h);
    while (n--)
    {
        cin >> fl >> t;
        int k = find(t);
        if (fl[0] == 'I')
        {
            h[k] = t;
        }
        else
        {
            if (h[k] != INF)
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

