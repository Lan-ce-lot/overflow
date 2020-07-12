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
const int maxn = 1005;
int a[2000];
int b[2000];
int c[2000];
int sum[2000];

void Add(int *a, int *c)
{
    int jw = 0;
    for(int i = 1; i <= 1000; i++)
    {
        c[i] += a[i] + jw;
        jw = c[i] / 10;
        c[i] %= 10;
    }
}

void Mul(int *a, int c)
{
    int jw = 0;
    for(int i = 1; i <= 1000; i++)
    {
        a[i] = a[i] * c + jw;
        jw = a[i] / 10;
        a[i] %= 10;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    a[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        Mul(a, i);
        Add(a, c);
    }
    bool flag = 0;
    for(int i = 1000; i >= 1; i--)
    {
        if(c[i] != 0)
            flag = 1;
        if(flag)
            cout << c[i];
    }
}
