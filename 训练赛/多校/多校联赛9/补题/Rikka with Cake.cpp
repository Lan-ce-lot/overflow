/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: Discretization 离散化
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
const int maxn = 1e5 + 10;

typedef pair<int, int> P;
vector<int> vx, vy;
vector<P> t[maxn], ask[maxn];
int T, n, m, k;


int a_t[maxn];
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
        A[u].sum = 0;//这里可以改为初始数组的
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


struct line
{
    int x, y;
    char dir;
    bool operator <(const line &A) const
    {
        return x < A.x;
    }
} a[maxn];

void LiSanhua(line a[], int k)
{

    vx.clear();
    vy.clear();
    for(int i = 1; i <= k; i++)
        vx.push_back(a[i].x), vy.push_back(a[i].y);//空格好评
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());//unique去重
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    n = vx.size() + 1;
    m = vy.size() + 1;
    for (int i = 1; i <= k; i++)
        a[i].x = lower_bound(vx.begin(), vx.end(), a[i].x) - vx.begin() + 1, a[i].y = lower_bound(vy.begin(), vy.end(), a[i].y) - vy.begin() + 1;
}


int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ll ans = 0;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= k; i++)
            scanf("%d%d %c", &a[i].x, &a[i].y, &a[i].dir);
        LiSanhua(a, k);
        build(1, 1, m);
        sort(a + 1, a + k + 1);
        for (int i = 1; i <= k; i++)
        {
            if (a[i].dir == 'U')
            {
                add(1, 1, m, a[i].y, m, 1);
            }
            else if (a[i].dir == 'D')
            {
                add(1, 1, m, 1, a[i].y, 1);
            }
            else if (a[i].dir == 'L')
            {
                ans += query(1, 1, m, a[i].y, a[i].y);
            }
        }
        build(1, 1, m);
        for (int i = k; i >= 1; i--)
        {
            if (a[i].dir == 'U')
            {
                add(1, 1, m, a[i].y, m, 1);
            }
            else if (a[i].dir == 'D')
            {
                add(1, 1, m, 1, a[i].y, 1);
            }
            else if (a[i].dir == 'R')
            {
                ans += query(1, 1, m, a[i].y, a[i].y);
            }
        }
        printf("%lld\n", ans + 1);
    }
    return 0;
}
//1076MS	13056K
