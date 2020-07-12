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
const int maxn = 1005;
int t, n, N, d, x, y, maze[maxn][maxn];
char ch;
class U_set
{
public:
    int parent[maxn], height[maxn];
    void init()
    {
        for (int i = 0; i < maxn; i++)
        {
            parent[i] = i;
            height[i] = 0;
        }
    }
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = Find(parent[x]);// Â·¾¶Ñ¹Ëõ
    }

    void Union(int x, int y)
    {
        Find(x);
        Find(y);
        if (x == y)
            return;
        else if (height[x] < height[y])
            parent[x] = y;
        else
            parent[y] = x;
            if (height[x] == height[y])
                height[x]++;
    }
    bool same(int x, int y)
    {
        return Find(x) == Find(y);
    }
}Sset;

bool check(int x, int y, int xx, int yy)
{
    return (sqrt((double)(x - xx) * (x - xx) * (y - yy) * (y - yy)))<= d;
}


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

pair<int > pari;

int main()
{
//    ios::sync_with_stdio(false);
    Sset.init();
    scanf("%d%d", &N, &d);
    while (N--)
    {
        scanf("%d%d", &x, &y);

        maze[x][y] = 1;
    }
    while (~scanf("%c", &ch))
    {
        int temp1, temp2;
        if (ch == 'O')
        {
            scanf("%d", &temp1);

            check();
        }
        else if (ch == 'S')
        {
            scanf("%d%d", &temp1, &temp2);
            puts(Sset.same(temp1, temp2)? "SUCCESS" : "FAIL");
        }

    }
    return 0;
}

