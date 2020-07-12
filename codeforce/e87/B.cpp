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
const int maxn = 1000005;

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
        n = read();
        x = read();
        cin >> str;
        int flag = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            pex[i] = pex[i - 1] + (str[i - 1] - '0' ?  -1 : 1);
            if (pex[i] == x)
                flag = 1;
        }
        if (pex[n] == 0 && flag)
        {
            cout << -1 << endl;
            continue;
        }
        else if (pex[n] == 0 && (!flag))
        {
//            debug(1111);
            cout << 0 << endl;
            continue;
        }
        int temp = 0;
        if (x == 0)
            ans++;
        for (int i  = 1; i <= n; i++)
        {
            if ((pex[i] - x) % pex[n] == 0 && (pex[i] - x) / pex[n] <= 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}



int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

