/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:分块

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
ll n, m, a[maxn];
int d[maxn];
int num;//分块个数
int belong[maxn];//表示i属于哪一块
int block;//表示块的大小
int l[maxn];//表示i这块的左端点
int r[maxn];//表示i这块的右端点
ll Max[maxn];

void build()
{
    block = sqrt(n);
    num = n / block;
    if (n % block)
        num++;
    for (int i = 1; i <= num; i++)
        l[i] = (i - 1) * block + 1, r[i] = i * block;
    r[num] = n;
    for (int i = 1; i <= n; i++)
        belong[i] = (i - 1) / block + 1;

    for (int i = 0; i <= num; i++)
        for (int j = l[i]; j <= r[i]; j++)
            Max[i] = max(Max[i], a[j]);
}

void update(int x, int y)
{
    a[x] += y;
    Max[belong[x]] = max(Max[belong[x]], a[x]);
}

ll ask(int x, int y)
{
    ll ans = 0;
    if (belong[x] == belong[y])
    {
        for (int i = x; i <= y; i++)
            ans = max(a[i], ans);
        return ans;
    }
    for (int i = x; i <= r[belong[x]]; i++)
        ans = max(ans, a[i]);
    for (int i = belong[x] + 1; i < belong[y]; i++)
        ans = max(ans, Max[i]);
    for (int i = l[belong[y]]; i <= y; i++)
        ans = max(ans, a[i]);
    return ans;
}

int main()
{
//    ios::sync_with_stdio(false);

    return 0;
}

