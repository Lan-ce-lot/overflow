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
#define lowbit(x)  x & - x
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
ll t, n, ans = 0, flag = 0;
string str1, str2;
double sy, l, r;
void sx(double x)
{

    if (x - pow(x, 1.0 / 3) > 1.0 + eps)
    {
        flag ++;
        sx(pow(x, 1.0 / 3));
    }
    else
    {
        sy = x;
        return ;
    }

}

void solve()
{

    cin >> t;
    while (t--)
    {
        double ans = 0;
        cin >> l >>r;
        if (l < 0)
        {
            l = -l;
            r = -r;
        }
        if (l < r)
        {
            printf("%.9f\n", abs(r - l));
            continue;
        }
        else
        {
            sx(l);
//            debug(sy);
            printf("%.9f\n",flag + sy - r) ;
        }
    }

}
//<=1
int main()
{
//    printf("%.9f",2+pow(3, 1.0 / 3) );

    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

