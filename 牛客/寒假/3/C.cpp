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
int a[maxn], pex[maxn];
void solve()
{
    cin >> n;
    int con = 0;
    for (int i = 1;  i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
        {
            con++;
            pex[a[i]] = i;
        }

    }
    printf("The size of the tree is %d\n", con);
    int ro = 1;
    printf("Node %d is the root node of the tree\n", a[1]);
    for (int i = 1; i <= con; i++)
    {
        int l, r;
        if (pex[i] * 2 > n)
        {
            l = -1;
            r = -1;
        }
        else if (pex[i] * 2 == n)
        {
            l = a[pex[i] * 2];
            r = -1;
        }
        else
        {
            l = a[pex[i] * 2];
            r = a[pex[i] * 2 + 1];
        }
        printf("The father of node %d is %d, the left child is %d, and the right child is %d\n", i, (pex[i] / 2?a[pex[i] / 2]:-1 ), l, r);
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

