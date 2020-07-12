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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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
int t, n;
int p[maxn], heigh[maxn];
int find(int x)
{
    return x == p[x] ? p[x] : p[x] = find(p[x]);
}

void solve()
{
    cin >> t >> n;
    string c;
    for (int i = 1; i <= t; i++) p[i] = i, heigh[i] = 1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> c >> a;
        if (c == "C")
        {
            cin >> b;
            if (find(a) == find(b)) continue;
            heigh[find(b)] += heigh[find(a)];
            p[find(a)] = find(b);
        }
        else if (c == "Q1")
        {
            cin >> b;
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            cout << heigh[find(a)] << endl;
        }
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

