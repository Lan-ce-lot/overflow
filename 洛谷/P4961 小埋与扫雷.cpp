/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
int n, m, ans = 0;
int maze[maxn][maxn];
int maze1[maxn][maxn];
//1->雷0->空格-1->数字-2->无空格数字
int dir[8][2] = {{1, 0},{1, 1},{0, 1},{-1, 1},{-1, 0},{-1, -1},{0, -1},{1, -1}};
bool vis[maxn][maxn];
bool test(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= m && !vis[x][y] ? 1 : 0;
}

void dfs(int x, int y)
{
    if (!test(x, y))
        return ;
    if (maze[x][y] != 0)
        return ;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
    	dfs(x + dir[i][0], y + dir[i][1]);
	}
        
    return;
}


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j  = 1; j <= m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maze[i][j] == 1)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (maze[i + dir[k][0]][j + dir[k][1]] == 0)
                        maze[i + dir[k][0]][j + dir[k][1]] = -2;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maze[i][j] == 0)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (maze[i + dir[k][0]][j + dir[k][1]] == -2)
                        maze[i + dir[k][0]][j + dir[k][1]]++;
                }
                if (test(i, j))
                {
                	dfs(i, j);
                	ans++;
				}
					
            }
        }
    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j  = 1; j <= m; j++)
//        {
//            printf(j == m ?"%d\n":"%d ", maze[i][j]);
//        }
//    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maze[i][j] == -2)
                ans ++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

