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
int t, n, m;
map<ll, ll> M;
set<ll> S;


void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        char c = getchar();
        if (c == ' ')
        {
            cin >> m;
            if (S.empty())
            {
                M[n] += m;
                S.insert(n);

                continue;
            }
            auto it = S.lower_bound(n);//大于等于
            if (!S.empty())
            {
                if (it != S.end())
                {
                    if (*it <= n + 30)
                    {
                        continue;
                    }
                }
                if (it != S.begin())
                {
                    it--;
                    if (*it >= n - 30)
                    {
                        continue;
                    }
                    it++;
                }
                if (it != S.end())
                {
                    it++;
                    if (it != S.end())
                    {
                        if (*it <= n + 30)
                        {
                            continue;
                        }

                    }
                    it++;
                }
                M[n] += m;
                S.insert(n);
                if (M[n] == 0)
                {
                    S.erase(it);
                }

            }
            if (M[n] == 0)
            {
                S.erase(it);
            }
        }
        else if (n == -1)
        {
            if (S.empty())
            {
                puts("skipped");
                continue;
            }

            auto it = S.begin();
            cout << M[*it] << endl;
            M[*it] = 0;
            S.erase(it);
        }
        else
        {
            cout << M[n] << endl;
        }
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

