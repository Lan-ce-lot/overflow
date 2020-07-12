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
int t, n, x;
int pex[maxn];
string str;

void solve()
{
    cin >> t;
    while (t--)
    {
        int ans = 0, con = 0;
        n = read();
        x = read();
        cin >> str;
        string temp = str;
        int B = 0, ttt = 0;
        for (int i = 0; i < n; i++)
        {
            if (temp[i] - '0')
            {
                B -= 1;
                pex[i + 1] = B ;
            }
            else
            {
                B += 1;
                pex[i + 1] = B ;
            }
            if (B == x)
                ttt++;
        }
        if (B == 0 && ttt)
        {
            cout << -1 << endl;
            continue;
        }
        else if (B == 0 && ttt == 0)
        {
            if (x == 0)cout << 1 << endl;
            else cout << ttt <<endl;
            continue;
        }
        if (B * x < 0)
        {
            cout << ttt << endl;
            continue;
        }
        else
        {
            int ton = (x % B) ? (x / B): (x / B - 1) ;
            for (int i = ton * n; i <= (ton + 2) * n; i++)
            {


                if (i < (ton + 1) * n && pex[i - ton * n] + B * (i / n)== x)
                {
                    ans++;
                }
                else if(i >= (ton + 1) * n && pex[i - (ton + 1) * n] + B * (i / n)== x)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }

    }
}

int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

