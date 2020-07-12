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
#define lowbit(x) (x&-x)
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 50005;

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
int tree[maxn], a[maxn];
void add(int x, int y)
{
    while (x <= n)
    {
        tree[x] += y;
        x += lowbit(x);
    }
}

void init()
{
    for (int i =1; i <= n; i++)
        add(i, a[i]);
}

ll getsum(int x)
{
    ll sum = 0;
    while (x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{

//    ios::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(tree, 0, sizeof(tree));
        memset(a, 0, sizeof(a));
        printf("Case %d:\n", i);
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
        }
        init();
        string str;

        while (cin >> str)
        {
            int a1, b1;
            if (str == "End")
                break;
            else if (str == "Query")
            {
                cin >> a1 >> b1;
                cout << getsum(b1) - getsum(a1 - 1) << endl;
            }
            else if (str == "Add")
            {
                cin >> a1 >> b1;
                add(a1, b1);
            }
            else if (str =="Sub")
            {
                cin >> a1 >> b1;
                add(a1, -1 * b1);
            }
        }
    }
    return 0;
}

