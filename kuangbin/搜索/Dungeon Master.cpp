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
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 105;

int h, row, col;

struct node
{
    int h, row, col;
    int step;
};

char maze[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int dir[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
node start;
node endt;
node top;

void find_s()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                if (maze[i][j][k] == 'S')
                {
                    start.h = i;
                    start.row = j;
                    start.col = k;
                }
                else if (maze[i][j][k] == 'E')
                {
                    endt.h = i;
                    endt.row = j;
                    endt.col = k;
                }
            }
        }
    }
}

bool test(int h0, int r0,int c0)
{
    if (h0 >= 0 && h0 < h && r0 >= 0 && r0 < row && c0 >= 0 && c0 < col && (maze[h0][r0][c0] == '.' || maze[h0][r0][c0] == 'E')&& (!vis[h0][r0][c0]))
        return 1;
    return 0;
}

void bfs()
{
    queue <node> q;
    q.push(start);
    while (!q.empty())
    {
        top = q.front();
        q.pop();
        if (maze[top.h][top.row][top.col] == 'E')
            return;
        for (int i = 0; i < 6; i++)
        {
            int hh = top.h + dir[i][0];
            int rr = top.row + dir[i][1];
            int cc = top.col + dir[i][2];
            if (test(hh, rr, cc))
            {
                q.push(node{hh, rr, cc, top.step + 1});
                vis[hh][rr][cc] = 1;
            }
        }
    }
}

void solve()
{

    while(~scanf("%d%d%d",&h, &row, &col))
    {
        if (h == 0 && row == 0 && col == 0)
            return;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < row; j++)
            {
                cin >> maze[i][j];
            }
        }
//        for (int i = 0; i < h; i++)
//        {
//            for (int j = 0; j < row; j++)
//            {
//                cout << maze[i][j] << endl;
//            }
//        }
        find_s();
        bfs();
        if (maze[top.h][top.row][top.col] == 'E')
        {
            printf("Escaped in %d minute(s).\n", top.step);
        }
        else
        {
            printf("Trapped!\n");
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    vis[i][j][k] = 0;
                }
            }
        }
    }
}

int main()
{
    solve();

}
