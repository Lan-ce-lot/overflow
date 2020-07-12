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
vector<int> S;
int t, n, m;
int a[maxn];
int c[maxn];
int ans[maxn];
int num[maxn];
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &c[i]);
    }
    int j = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        if (num[c[i]] == 0)
            ans[j++] = c[i];
        num[c[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (num[a[i]] == 0)
            ans[j++] = a[i];
        num[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
            cout << ans[i] << ' ';
    }
    return 0;
}
