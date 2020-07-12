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
const int maxn = 105;
int a[maxn];
int n, ans = 0;
char maze[maxn][maxn];
bool test(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < n)
        return 0;
    return 1;
}
void dfs(int x, int y)
{
    if (test(x + 1, y))
        return;
    if (maze[x + 1][y] == 'C')
        ans++;
    dfs(x + 1, y);
}
void dfs1(int x, int y)
{
    if (test(x, y + 1))
        return;
    if (maze[x][y + 1] == 'C')
        ans++;
    dfs1(x, y + 1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%s", maze[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == 'C')
            {
                dfs(i, j);
                dfs1(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

