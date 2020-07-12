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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5 + 5;

int t, n1, m, q, k, a[maxn], num[maxn], ans[maxn];
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

struct node
{
	int left,right; //
}n[4*maxn];

void build(int p, int l, int r)//½¨Ê÷
{
    if(l == r)
    {
        n[p].left = 0;
        n[p].right = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    n[p].left = max(n[p << 1].left, n[(p << 1) + 1].left);
    n[p].right = min(n[p << 1].right, n[p << 1 | 1].right);
}

void change(int p, int l, int r, int x, int num)//µã¸üÐÂ
{
    if(l == r)
    {
        n[p].left = num;
        n[p].right = num;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) change(p << 1, l, mid, x, num);
    else change(p << 1 | 1, mid + 1, r, x, num);
    n[p].left = max(n[p << 1].left, n[p << 1 | 1].left);
    n[p].right = min(n[p << 1].right, n[p << 1 | 1].right);
}

int Find(int p, int l, int r, int x, int y)//find max
{
    if(x <= l && y >= r)
    {
        return n[p].left;
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return Find(p << 1, l, mid, x, y);
    if(x > mid) return Find(p << 1 | 1, mid + 1, r, x, y);
    return (max(Find(p << 1, l, mid, x, mid), Find(p << 1 | 1, mid + 1, r, mid + 1, y)));
}


//int main()
//{
//    int N, M, a, b;
//    int s;
//    while(~scanf("%d%d", &N, &M))
//    {
//        for(int i = 1; i <= N; i++)
//			scanf("%d", &num[i]);
//        build(1, 1, N);
//        while(M--)
//        {
//            scanf("%d%d%d", &s, &a, &b);
//            if(s == 0)
//            {
//                printf("%d\n", (Find(1, 1, N, a, b) + Find2(1, 1, N, a, b)) / 2);
//            }
//            else change(1, 1, N, a, b);
//        }
//    }
//    return 0;
//}






int main()
{
//    ios::sync_with_stdio(false);
    t = read();
    while (t--)
    {
        n1 = read();
        k = read();
        for (int i = 1; i <= n1; i++)
        {
            a[i] = read();
            num[a[i]] = i;
        }
        build(1, 1, n1);
        for (int i = 1; i <= n1; i++)
        {
        	int temp = 0;
            int l = num[i] - k, r = num[i] + k;
            if (num[i] + k > n1)
            {
                r = n1;
            }
            if (num[i] - k < 1)
            {
                l = 1;
            }
            temp = Find(1, 1, n1, l, r);
            ans[i] = ans[temp] + 1;
            change(1, 1, n1, num[i], i);
        }
        for (int i = 1; i <= n1; i++)
        {
            printf(i == n1 ? "%d\n":"%d ", ans[i]);
        }
    }
    return 0;
}
