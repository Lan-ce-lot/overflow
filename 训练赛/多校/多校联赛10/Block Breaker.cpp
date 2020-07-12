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
const int maxn = 2010;
int a[maxn];
int maze[maxn][maxn];//0：0存在，1无；1:0稳定，1不；
int t, n, m, q;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int flag[maxn][maxn][2];//0上下，1左右
struct node
{
    int x, y;
    node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

bool test(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m && maze[x][y] == 0 ? 1 : 0;
}

int inflag(int x, int y)
{
    int ans = 0;
    queue <node> q;
    q.push(node(x, y));
    if (test(x, y))
    {
        maze[x][y] = 1;
        ans++;
    }
    else
        return ans;
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
		maze[top.x][top.y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int tx = top.x + dir[i][0];
            int ty = top.y + dir[i][1];
            if (test(tx, ty))//1234,上，左，下，右
            {
                if (i == 0)
                {
                	if (flag[tx][ty][1])
                	{
                		maze[tx][ty] = 1;
                		q.push(node(tx, ty));
                		ans++;
					}
					else
					{
						flag[tx][ty][0] = 1;
					}
				}
				else if (i == 1)
				{
                	if (flag[tx][ty][0])
                	{
                		maze[tx][ty] = 1;
                		q.push(node(tx, ty));
                		ans++;
					}
					else
					{
						flag[tx][ty][1] = 2;
					}					
				}
				else if(i == 2)
				{
                	if (flag[tx][ty][1])
                	{
                		maze[tx][ty] = 1;
                		q.push(node(tx, ty));
                		ans++;
					}
					else
					{
						flag[tx][ty][0] = 3;
					}					
				}
				else
				{
                	if (flag[tx][ty][0])
                	{
                		maze[tx][ty] = 1;
                		q.push(node(tx, ty));
                		ans++;
					}
					else
					{
						flag[tx][ty][1] = 4;
					}					
				}
            }
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
		memset(flag, 0, sizeof(flag));
		memset(maze, 0, sizeof(maze));
        scanf("%d%d%d", &n, &m, &q);
        int x, y;
        for (int i = 0; i  < q; i++)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", inflag(x, y));
        }
    }
    return 0;
}

