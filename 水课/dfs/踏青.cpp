#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
char map[1005][1005];
bool vis[1005][1005];
int n,m,ans=0,t;
int dir[2][2] = {{0, 1}, {1, 0}};
bool test(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m && map[x][y] != '.' && !vis[x][y])
        return 1;
    else
        return 0;
}

void dfs(int x, int y)
{
    if (test(x, y) == 0)return;
    vis[x][y] = 1;
    for (int i = 0; i <= 2; i++)
        dfs(x + dir[i][0], y + dir[i][1]);
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s",map[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 1 && map[i][j] == '#')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
	return 0;
}
