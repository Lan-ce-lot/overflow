/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:1.线段树
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
const int maxn = 1e6 + 5;

ll a[maxn];
struct node
{
    ll sum;
    ll lazy;
} A[maxn << 2];

void build(int u, int l, int r)
{
    A[u].lazy = 0;
    if (l == r)
    {
        A[u].sum = a[l];//这里可以改为初始数组的
        return;
    }
    int mid = (l + r) / 2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
    A[u].sum = A[2 * u].sum + A[2 * u + 1].sum;//等价pushup操作
}

//下放操作，将当前的lazy下放
void pushdown(int u, int l,int  r)
{
    if (A[u].lazy == 0)
        return ;
    int mid = (l + r) / 2;
    A[u * 2].sum += A[u].lazy * (mid - l + 1);
    A[u * 2 + 1].sum += A[u].lazy * (r - mid);
    A[u * 2].lazy += A[u].lazy;
    A[u * 2 + 1].lazy += A[u].lazy;
    A[u].lazy = 0;
}

//l,r表示更新区间sl,sr一开始为1, n, u == 1

void add(int u, int sl, int sr, int l, int r, ll k)
{
    if (l > sr || r < sl)
        return ;
    if (l <= sl && r >= sr)
    {
        A[u].sum += k * (sr - sl + 1);
        A[u].lazy += k;
        return ;
    }
    pushdown(u, sl, sr);
    int mid = (sl + sr) / 2;
    add(2 * u, sl, mid, l, r, k);
    add(2 * u + 1, mid + 1, sr, l, r, k);
    A[u].sum = A[u * 2].sum + A[u * 2 + 1].sum;
    return ;
}



ll query(int u, int sl, int sr, int l, int r)
{
    if (l > sr || r < sl)
        return 0;
    if (l <= sl && r >= sr)
        return A[u].sum;
    pushdown(u, sl, sr);
    int mid = (sl + sr) / 2;
    return (query(2 * u, sl, mid, l, r) + query(2 * u + 1, mid + 1, sr, l, r));
}
int n, m;
int main()
{
//    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0 ;  i < m; i++)
    {
        int flag = 0, a1, b1, c1;
        cin >> flag;
        if (flag == 1)
        {
            cin >> a1 >> b1;
            cout << query(1, a1, b1, 1, n) << endl;
        }
        else if (flag == 2)
        {
            cin >> a1 >> b1 >> c1;
            add(1, a1, b1, 1, n, c1);
        }
        else
        {
            cin >> a1 >> b1;//m倍数，x加
            for (int i = 1; i <= n; i++)
            {
                if (i * a1 > n)
                    break;
                add(1, i * a1, i * a1, 1, n, b1);
            }

        }
    }
    return 0;
}

