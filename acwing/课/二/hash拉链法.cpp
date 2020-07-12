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
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 100003;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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

//hash拉链法

//记住h[]memset-1
int h[maxn], e[maxn], ne[maxn], idx;

void inser(int x)
{
    int k = (x % mod + mod) % mod;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % mod + mod) % mod;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}




//==============================================================
void solve()
{
    memset(h, -1, sizeof h);
    char fl[2];
    cin >> n;
    while (n--)
    {
        cin >> fl >> t;
        if (fl[0] == 'I')
        {
            inser(t);
        }
        else
        {
            if (find(t))
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

