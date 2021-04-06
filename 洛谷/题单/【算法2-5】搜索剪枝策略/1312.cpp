/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
//#include <algorithm>
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
//#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
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
bool vis[10][10];
bool flag[11];
int map[10][10];
int step[10][5];
int count[11];
int n, N;
int del() //计算这一次移动能够消去多少
{
    memset(vis, 1, sizeof vis);
    int res = 0;
    int l, r, u, d, x, y, t;
    bool cs = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            if (map[i][j])
                if ((j >= 2 && map[i][j - 1]) || j == 1) //寻找中心块来计算可以消除的块
                {
                    l = r = i;
                    u = d = j;
                    while (l >= 2 && map[l - 1][j] == map[i][j])
                        l--;
                    while (r < 4 && map[r + 1][j] == map[i][j])
                        r++;
                    while (d >= 2 && map[i][d - 1] == map[i][j])
                        d--;
                    while (u <= 6 && map[i][u + 1] == map[i][j])
                        u++;
                    if (r - l >= 2) //表示横方向上可以消除方块
                        for (int k = l; k <= r; k++)
                            vis[k][j] = 0;
                    if (u - d >= 2) //表示竖方向上可以消除方块
                        for (int k = d; k <= u; k++)
                            vis[i][k] = 0;
                }
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            if (!vis[i][j]) //可以消除
            {
                res++;
                map[i][j] = 0;
            }
    for (int i = 1, j; i <= 5; i++) //求每一列是否有块悬着
    {
        for (j = 1; j <= 7; j++)
            if (!map[i][j])
                break;
        x = j; //找到第一个空块
        for (; j <= 7; j++)
            if (map[i][j])
                break;
        if (j == 8) //如果一直到顶都是空块，就没有块可以掉下来，所以不用管它
            continue;
        y = j - 1; //找到空块范围的末端
        t = 0;
        for (j = x; j <= 7; j++) //悬着的块掉下来
        {
            t++;
            if (!map[i][y + t] || map[i][j])
                break;
            map[i][j] = map[i][y + t];
            map[i][y + t] = 0;
            cs = 1;
        }
    }
    if (cs)           //如果有掉下去的
        res += del(); //当悬着的块掉下去后可能还可以继续消除，所以再来一次del
    return res;
}
bool judge()
{
    memset(count, 0x0, sizeof count);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            count[map[i][j]]++;
    for (int i = 1; i <= N; i++)
        if (count[i] >= 1 && count[i] <= 2)
            return 0;
    return 1;
}
void dfs(int num, int tot)
{
    if (!judge())
        return;
    if (num >= n + 1)
    {
        if (!tot) //因为在dfs时就考虑到了优先顺序，所以最先搜到的必定是优先级最大的
        {
            for (int i = 1; i <= n; i++)
                printf("%d %d %d\n", step[i][1] - 1, step[i][2] - 1, step[i][3]);
            exit(0);
        }
        return;
    }
    int x, y;
    int temp[10][10], p, q;
    bool cs;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            temp[i][j] = map[i][j];
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
        {
            if (map[i][j])
            {
                cs = 1;
                if (i <= 4 && map[i][j] != map[i + 1][j]) //剪枝（1）
                {
                    swap(map[i][j], map[i + 1][j]);
                    step[num][1] = i;
                    step[num][2] = j;
                    step[num][3] = 1;
                    p = tot - del();
                    dfs(num + 1, p);
                    cs = 0;
                }
                if (!cs)
                {
                    cs = 1;
                    for (p = 1; p <= 5; p++)
                        for (q = 1; q <= 7; q++)
                            map[p][q] = temp[p][q];
                }
                if (i >= 2 && !map[i - 1][j]) //剪枝（2）
                {
                    swap(map[i][j], map[i - 1][j]);
                    step[num][1] = i;
                    step[num][2] = j;
                    step[num][3] = -1;
                    p = tot - del();
                    dfs(num + 1, p);
                    cs = 0;
                }
                if (!cs)
                    for (p = 1; p <= 5; p++)
                        for (q = 1; q <= 7; q++)
                            map[p][q] = temp[p][q];
            }
        }
}
int main()
{
    int x, y = 0;
    scanf("%d", &n);
    for (int i = 1, j; i <= 5; i++)
    {
        j = 0;
        scanf("%d", &x);
        while (x)
        {
            map[i][++j] = x;
            if (!flag[x])
            {
                flag[x] = 1;
                N++;
            }
            y++;
            scanf("%d", &x);
        }
    }
    dfs(1, y);
    cout << -1 << endl;
    return 0;
}
