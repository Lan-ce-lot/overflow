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
int a[maxn];
int f[maxn];
int bit[maxn];
int yi;
void solve()
{

        n = read();

        for (int i = 0; i < n; i++)
        {
            a[i] = read();
        }
        for (int i = 0; i < n; i++)
        {
            int temp = a[i];
            f[i] = a[i];
            int j = 0;
            while (temp)
            {

                if (temp & 1)
                {
                    bit[j]++;
                    if (bit[j] >= 2)
                    {
                        yi |= (1 << j);
                    }
                }
                j++;
                temp >>= 1;
            }
        }
//        debug(yi);
        for (int i = 0; i < n; i++)
        {
//            cout << f[i] << endl;
            f[i] &= (~yi);
        }

        swap(a[max_element(f, f + n) - f], a[0]);
        for (int i = 0; i < n; i++)
            cout << a[i] << (i == n - 1 ? '\n' : ' ');


}

int main()
{
//    n = 20;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            cout <<i << ' ' << j << ' '<< ((i | j) - j) << ' '<< (i&(~j))<< endl;
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

