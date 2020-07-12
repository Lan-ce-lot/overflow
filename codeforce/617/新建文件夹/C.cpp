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
#define lowbit(x) (x&-x)
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
ll a[maxn];

struct node
{
    int x, y;
    ll v;
};
string str;//LRDU
void solve()
{
    cin >> t;
    while (t--)
    {
        map<pair<int, int>, int> M;
        int ans = INF;
        int xx = 0, yy = 0;
        int x = 0, y = 0;
        n = read();
        cin >> str;
        M[make_pair(x, y)] = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'L')x++;
            else if (str[i] == 'R')x--;
            else if (str[i] == 'D')y++;
            else
                y--;
            if (M.count(make_pair(x, y)))
            {
                if (ans > i - M[make_pair(x, y)])
                {
                    ans = i - M[make_pair(x, y)];
                    xx = M[make_pair(x, y)];
                    yy = i;
                }
            }
            M[make_pair(x, y)] = i + 1;
        }
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << xx + 1 << ' ' << yy + 1 << endl;
    }

}

int main()
{

    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

