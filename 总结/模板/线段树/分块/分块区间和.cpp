/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: 题目link: poj.org/problem?id=3468
 优美而暴力
 暴力美学
 分块和做的区间和
 1.build

 2.update
 分两种情况：
 1.在某块内就直接暴力
 2.跨多个块就
 两边暴力
 中间有类似lazy的add数组，但是和线段树不同的是这个要方便很多
 大段维护，局部朴素

 3.query
 思想同修改

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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5 +5;

ll n, m, a[maxn], add[maxn], sum[maxn];
int d[maxn];
int num;//分块个数
int belong[maxn];//表示i属于哪一块
int block;//表示块的大小
int le[maxn];//表示i这块的左端点
int ri[maxn];//表示i这块的右端点

void build()
{
    block = sqrt(n);
    num = n / block;
    if (n % block)
        num++;
    for (int i = 1; i <= num; i++)
        le[i] = (i - 1) * block + 1, ri[i] = i * block;
    ri[num] = n;

    for (int i = 1; i <= num; i++)//区间和的初始化
        for (int j = le[i]; j <= ri[i]; j++)
        {
            belong[j] = i;
            sum[i] += a[j];
        }

//    for (int i = 1; i <= n; i++)
//        belong[i] = (i - 1) / block + 1;
}

void update(int l, int r, ll k)
{
    int p = belong[l], q = belong[r];
    if (p == q)
    {
        for(int i = l; i <= r; i++)
            a[i] += k;
        sum[p] += k * (r - l + 1);
    }
    else
    {
        for (int i = p + 1; i <= q - 1; i++)
            add[i] += k;
        for (int i = l; i <= ri[p]; i++)
            a[i] += k;
        sum[p] += k * (ri[p] - l + 1);
        for (int i = le[q]; i <= r; i++)
            a[i] += k;
        sum[q] += k * (r - le[q] + 1);
    }
}

ll query(int l, int r)
{
    int p  = belong[l], q = belong[r];
    ll ans = 0;
    if (p == q)
    {
        for (int i = l; i <= r; i++)
            ans += a[i];
        ans += add[p] * (r - l + 1);
    }
    else
    {
        for (int i = p + 1; i <= q - 1; i++)
            ans += sum[i] + add[i] * (ri[i] - le[i] + 1);
        for (int i = l; i <= ri[p]; i++)
            ans += a[i];
        ans += add[p] * (ri[p] - l + 1);
        for (int i = le[q]; i <= r; i++)
            ans += a[i];
        ans += add[q] * (r - le[q] + 1);
    }
    return ans;
}

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

int main()
{
//    ios::sync_with_stdio(false);
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build();
    while (m--)
    {
        char s;
        int l, r, d;
        cin >> s;
        l = read();
        r = read();
        if (s == 'C')
        {
            d = read();
            update(l, r, d);
        }
        else
            printf("%lld\n", query(l, r));
    }
    return 0;
}

