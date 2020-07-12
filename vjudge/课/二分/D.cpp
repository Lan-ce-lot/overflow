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
typedef unsigned long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const ll INF = 2000000000;//int2147483647//ll9e18//unsigned ll 1e19
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
ll t, n, k;
ll pex[maxn];





ll l, r, ans = 0;
int a[maxn][4];
int f0[16000000], f1[16000000];
void solve()
{
    cin >> t;
    for (int i = 0; i < t; i ++)
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }

//    for (int i = 0; i < t; i++)
//        for (int j = 0; j < 4; j++)cout << a[i][j] << endl;
    int con = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            f0[con] = a[i][0] + a[j][1];
            f1[con++] = a[i][2] + a[j][3];
        }
    }
//    for (int i = 0; i < con; i++) cout << f0[i] << ' ' << f1[i] << endl;
//cout << con << endl;
    sort(f1, f1 + con);
    f1[con] = INF;
    for (int i = 0; i < con; i++)
    {
        ans += (upper_bound(f1, f1 + con + 1, -f0[i]) - lower_bound(f1, f1 + con + 1, -f0[i]));
    }
    cout << ans << endl;



}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
