/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: 我也借鉴了好多线段树+lazy的模板，维护值有用数组和结构体的，个人比较喜欢用结构体储存
 然后线段树的操作也就那几种(虽然叫法各异，但是实际上是一样的)：
 建树：build
 更新：update，change，add
 查询：find，query
 标记下放：pushdown
 向上更新：pushup(这个函数就一行，感觉没有必要，即两个子节点向上更新父节点的维护值)
 注意：无论是线段树还是树状数组，初始数组都应该从1开始存数据
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
const int maxn = 1e5 + 5;

ll a[maxn];
struct node
{
    ll sum;
} A[maxn << 2];

void build(int u, int l, int r)
{
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


//l,r表示更新区间sl,sr一开始为1, n, u == 1

void add(int u, int sl, int sr, int l, int r, ll k)
{
    if (l > sr || r < sl)
        return ;
    if (l <= sl && r >= sr)
    {
        A[u].sum += k * (sr - sl + 1);
        return ;
    }
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
    int mid = (sl + sr) / 2;
    return (query(2 * u, sl, mid, l, r) + query(2 * u + 1, mid + 1, sr, l, r));
}

int t, n, q, x, y, k;
char c;
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d", &t);
//注意：无论是线段树还是树状数组，初始数组都应该从1开始存数据
    while (t --)
    {
        int x, k, co = 1;

        char str[10];
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        printf("Case %d:\n", co++);
        while (1)
        {
            scanf(" %s", str);
            if (strcmp(str, "Query") == 0)
            {
                scanf("%d%d", &x, &k);
                printf("%d\n", query(1, 1, n, x, k));
            }
            else if (strcmp(str, "Add") == 0)
            {
                scanf("%d%d", &x, &k);
                add(1, 1, n, x, x, k);
            }
            else if (strcmp(str, "Sub") == 0)
            {
                scanf("%d%d", &x, &k);
                add(1, 1, n, x, x, -k);
            }
            else if (strcmp(str, "End") == 0)
            {
                break;
            }
        }
    }
    return 0;
}
