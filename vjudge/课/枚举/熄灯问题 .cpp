/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define lowbit(a) a & -a
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
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
int t, n = 6;
bool a[5][6], res[5][6], step[5][6];

bool check()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res[i][j])
                return 0;
        }
    }
    return 1;
}

void P_set(int x, int y)
{
    res[x][y] = !res[x][y];
    if (x > 0)
    {
        res[x - 1][y] = !res[x - 1][y];
    }
    if (x < n - 2)
    {
        res[x + 1][y] = !res[x + 1][y];
    }
    if (y > 0)
    {
        res[x][y - 1] = !res[x][y - 1];
    }
    if (y < n - 1)
    {
        res[x][y + 1] = !res[x][y + 1];
    }
}

void solve()
{
    n = 6;
    int con = 0;
    scanf("%d", &t);
    while (t--)
    {

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
//                debug(a[i][j]);
            }
        }




        for (int i = 0; i < 1 << 6; i++)//0~111111->63
        {
            memset(step, 0, sizeof step);
            memcpy(res, a, sizeof res);
            int temp = i;
            while (temp)
            {
                int tem = round((log(lowbit(temp)) / log(2)));
//                cout << '*' << log(lowbit(temp)) / (log(2)) << endl;
                step[0][tem] = 1;
                P_set(0, tem);
                temp -= lowbit(temp);
            }

            for (int j = 1; j < n - 1; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (res[j - 1][k])
                    {
                        P_set(j, k);
                        step[j][k] = 1;
//                        print_mat();
//                        debug(i);
                    }
                }
            }
            if (check())
            {
//                debug(i);
                break;
            }
        }

        printf("PUZZLE #%d\n", ++con);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d%c", step[i][j], j == n - 1 ? '\n' : ' ');
            }
        }
    }
}

int main()
{
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
