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
const int maxn = 10005;
ll mm[1005][1005];
ll ann[1005];

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
ll t, n, a[maxn], c;
ll b[maxn];

void cpy(int a[], int b[])
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i];
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memcpy(b, a, sizeof a);
    for (int i = 1; i <= n; i++)
    {
        memcpy(a, b, sizeof b);
        ann[i] += a[i];
        for (int j = i; j >= 0; j--)
        {
            mm[i][j] = a[j];
            if (j != 0)
            {
                a[j - 1] = min(a[j], a[j - 1]);
                mm[i][j - 1] = min(a[j], a[j - 1]);
                ann[i] += mm[i][j - 1];
            }
            else
            {
                mm[i][j] = a[j];
//                ann[i] += mm[i][j];
            }
        }
        for (int j = i; j <= n; j++)
        {
            if (j != n)
            {
                a[j + 1] = min(a[j], a[j + 1]);
                mm[i][j + 1] = min(a[j], a[j + 1]);
                ann[i] += mm[i][j + 1];
            }
            else
            {
                mm[i][j] = a[j];
//                ann[i] += mm[i][j];
            }
        }
    }
    int pos = max_element(ann + 1, ann + n + 1) - ann;
//    cout << pos;
//    debug(ann[pos]);
    for (int i = 1; i <= n; i++)
    {
        cout << mm[pos][i] << ' ';
    }
    puts("");
}
/*
5
1 3 2 4 1

5
5 1 10 1 11

5
11 1 2 3 4

5
1 10 6 7 1

5
5 1 2 1 4

5
1 2 4 1 10
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

