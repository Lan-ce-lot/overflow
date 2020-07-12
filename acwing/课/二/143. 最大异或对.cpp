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
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005 * 32;

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
int t, n, a[maxn];
//==============================================================
int num[maxn];
int son[maxn][2], cnt[maxn], idx;
//void init()
//{
//    sort(num, num + n);
//    int Max = num[n - 1];
//    int p = 0;
//    while (Max)
//    {
//        int u = Max & 1;
//        son[p][u];
//        if (!son[p][u]) son[p][u] = ++idx;
//        p = son[p][u];
//        Max >>= 1;
//    }
//}


void insert(int a)
{

    int p = 0, i = 31;
    while (i >= 0)
    {
        int u = a >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        i--;
    }
}

int query(int a)
{
    int p = 0, ans = 0, i = 31;
    while (i >= 0)
    {

        int u = a >> i & 1;
        if (son[p][u ^ 1])
        {
            p = son[p][u ^ 1];
            ans |= (1 << i);

        }
        else
        {
            p = son[p][u];
        }
        i--;
    }
    return ans;
}

//==============================================================
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

/*
10
181262 369842 1036879 546331 868986 496157 646816 459571 215643 448018
*/
