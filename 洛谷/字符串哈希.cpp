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
typedef unsigned long long ULL;
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
int t, n, m;
//==============================================================

//!!!!!!!!!!!str从下标1开始输入
const int P = 131;//13331
char str[maxn];
ULL h[maxn], p[maxn];//h前缀，p次方


ULL get(int l, int r)//闭区间 1~n
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
//==============================================================
void solve()
{
    cin >> t;map<int, bool> M;
    int ans = 0;
    while (t--)
    {
        scanf("%s", str + 1);//!
        int len = strlen(str + 1);
        p[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + str[i];
        }
        ULL temp = get(1, len );
//        debug(temp);
        if (M[temp] == 0)
        {
            ans++;
            M[temp] = 1;
        }


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

