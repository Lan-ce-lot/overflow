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
int t, n;//L, R, U, D;
//int L[maxn], R[maxn], U[maxn], D[maxn];

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int x[maxn], y[maxn];
string str;
struct node
{
    int trace[200010], in=1;
} sum[30];
map<char, int> mm;
mm['L'] = 0;
mm['R'] = 1;
mm['U'] = 2;
mm['D'] = 3;
void solve()
{
    cin >> t;
    while (t--)
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        cin >> n;
        cin >> str;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            sum[mm[str[i]]].trace[sum[mm[str[i]]].in ++] = i;
        }
        int ans = INF;
        for (int )
        {

        }
        if (ans == INF)
            cout << -1 <<endl;
        else
            cout << ans << endl;
    }
}
int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

