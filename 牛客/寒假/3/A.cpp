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
const int maxn = 100010;

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
int vis[maxn];
int prime[maxn];
void oulasai(int n)  //欧拉筛
{
    int x = 0;
    for(int i=2; i<=n; i++)
    {
        if(!vis[i])
            prime[x++]=i;
        for(int j=0; j<x; j++)
        {
            if(i*prime[j]>n)
                break;
            vis[i*prime[j]]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}
int t, n, m, q;
int h[maxn];//     1,2,3,4,5,6,7,8,9,10,11,12
int flag[maxn];
int ans[maxn];
void solve()
{

    cin >> n >> m;
    for (int i = 4; i <= n; i++)
    {
        if (vis[i] )
        {
            ans[i]++;
                for (int j = 2; j * i <= n ; j++)
                {
                    int con = j * i;
                    flag[con] = 1;
                    ans[con]++;
                }
        }
    }
    for (int i = 1; i <= n; i++)
    {
//        cout << ans[i] << ' ';
        h[ans[i]]++;
    }
    while (m--)
    {
        cin >> q;
        cout << h[q] << endl;
    }
}

int main()
{
    oulasai(maxn);
//    for (int i = 0; i < 100; i++)
//    cout << prime[i] << ' '<<vis[i] << endl;;
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

