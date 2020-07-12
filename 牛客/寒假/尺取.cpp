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
int t, n, m;
string str;
void solve()
{
    cin >> n >> m;
    cin >> str;
    int con0 = 0, con1 = 0;
    int L = 0, R = 0;
    int ans = 0;
    for (int i = 0; i < n ; i++)
    {
        if (str[i] == '0')
        {
            if (con0 < m)
            {
                con0++;
                R++;
            }
            else
            {

                while (str[L] != '0' && L <= R)
                {
                    L++;
                }
                L++, R++;
            }
        }
        else
            R++;
        ans = max(ans, R - L);

    }
    L = R = 0;
    int ans1 = 0;
    for (int i = 0; i < n ; i++)
    {
        if (str[i] == '1')
        {
            if (con1 < m)
            {
                con1++;
                R++;
            }
            else
            {

                while (str[L] != '1' && L <= R)
                {
                    L++;
                }
                L++, R++;
            }
        }
        else
            R++;
        ans1 = max(ans1, R - L);

    }
    cout << max(ans, ans1) << endl;
}
int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

