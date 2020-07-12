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
const int maxn = 1005;

typedef pair<int, int> P;
vector<int> vx, vy;
vector<P> t[maxn], ask[maxn];
int T, n, m, k;

struct line
{
    int x, y;
    char dir;
} a[maxn];

void LiSanhua(line a[], int k)
{

    vx.clear();
    vy.clear();
    for(int i = 1; i <= k; i++)
        scanf("%d%d %c", &a[i].x, &a[i].y, &a[i].dir), vx.push_back(a[i].x), vy.push_back(a[i].y);//空格好评
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());//unique去重
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    n = vx.size() + 1;
    m = vy.size() + 1;
    for (int i = 1; i <= k; i++)
        a[i].x = lower_bound(vx.begin(), vx.end(), a[i].x) - vx.begin() + 1, a[i].y = lower_bound(vy.begin(), vy.end(), a[i].y) - vy.begin() + 1;
    for (int i = 1; i <= k; i++)
    {
        printf(i == k ? "%d %d " : "%d %d\n", a[i].x, a[i].y);
    }
}



int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d", &T);
    while (T--)
    {
        cin >> n >> m >> k;
        LiSanhua(a, k);


    }

    return 0;
}

